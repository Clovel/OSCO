/*
 * @brief Implementation of the stack's internal clock.
 * 
 * @file Clock.c
 */

/* Includes -------------------------------------------- */
/* OSCO Sync includes */
#include "OSCOSync.h"

/* OSCO Clock includes */
#include "OSCOClock.h"

/* OSCO Driver includes */
#include "OSCOCANDriver.h"

/* OSCO Module private includes */
#include "SyncPrivate.h"

/* OSCO public includes */
#include "OSCOTypes.h"
#include "OSCOPrint.h"
#include "OSCOConfigDefines.h"
#include "OSCO.h"

/* Defines --------------------------------------------- */
#define DEFAULT_SYNC_COB_ID 0x080U

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoSyncInstance_t syncModule;

/* OSCO CAN Driver functions --------------------------- */
/* Initialization */
oscoErrorCode_t OSCOSyncInit(void) {
    if(syncModule.initialized) {
        eprintf("[ERROR] OSCO <OSCOSyncInit> Service is already initialized !\n");
        return OSCO_ERROR_ALREADY_INIT;
    }

    syncModule.period = OSCO_SYNC_PERIOD;
    syncModule.producer = OSCO_SYNC_PRODUCER;

    syncModule.cobID = DEFAULT_SYNC_COB_ID;

    /* TODO */

    syncModule.initialized = true;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOSyncSetPeriod(const uint32_t pPeriodMs) {
    syncModule.period = pPeriodMs;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOSyncProcess(void) {
    oscoErrorCode_t lErrorCode = OSCO_ERROR_UNKNOWN;
    static uint64_t lNewTicks = 0UL, lOldTicks = 0UL;

    if(!syncModule.initialized) {
        eprintf("[ERROR] OSCO <OSCOSyncProcess> Service is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    lErrorCode = OSCOClockGetTicks(&lNewTicks);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOSyncProcess> OSCOClockGetTicks failed !\n");
        return OSCO_ERROR_MODULE;
    }

    if(syncModule.period <= lNewTicks - lOldTicks) {
        /* Period passed, we must send the SYNC message */
#ifdef OSCO_SYNC_COUNTER_ENABLED        
        lErrorCode = OSCOCANDriverSend(syncModule.cobID, 1U, &syncModule.counter, 0x00000000U);
        syncModule.counter = 0xFFU <= syncModule.counter ? 0U : syncModule.counter + 1U;
#else /* OSCO_SYNC_COUNTER_ENABLED */
        lErrorCode = OSCOCANDriverSend(syncModule.cobID, 0U, NULL, 0x00000000U);
#endif /* OSCO_SYNC_COUNTER_ENABLED */
        if(OSCO_ERROR_NONE != lErrorCode) {
            eprintf("[ERROR] OSCO <OSCOSyncProcess> OSCOCANDriverSend failed !\n");
            return OSCO_ERROR_DRIVER;
        }

        /* Save the new time of SYNC emission */
        lOldTicks = lNewTicks;
    }

    return OSCO_ERROR_NONE;
}
