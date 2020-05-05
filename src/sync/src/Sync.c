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

/* OSCO OD */
#include "OSCOOD.h"

/* OSCO public includes */
#include "OSCOTypes.h"
#include "OSCOPrint.h"
#include "OSCOConfigDefines.h"
#include "OSCO.h"

/* Defines --------------------------------------------- */
#define DEFAULT_SYNC_COB_ID         0x080U
#define SYNC_COB_ID_PRODUCER_MASK   0x40000000U

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoSyncInstance_t syncModule;

/* OSCO CAN Driver functions --------------------------- */
/* Check OD for SYNC settings */
static oscoErrorCode_t syncCheckODSettings(void) {
    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    /* Check if the COB-ID entry is here */
    lErrorCode = OSCOODGetU32(SYNC_COB_ID_IDX, SYNC_COB_ID_SUBIDX, &syncModule.cobID);
    if(OSCO_ERROR_OD_NOT_FOUND == lErrorCode) {
        /* Set the default SYNC COB-ID */
        syncModule.cobID = DEFAULT_SYNC_COB_ID;
    } else if (OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <syncCheckODSettings> Failed to get the SYNC COB-ID object\n");
        return lErrorCode;
    }

    /* Check if this node is a SYNC producer */
    if(SYNC_COB_ID_PRODUCER_MASK == (SYNC_COB_ID_PRODUCER_MASK & syncModule.cobID)) {
        syncModule.producer = true;
        syncModule.cobID = syncModule.cobID & ~SYNC_COB_ID_PRODUCER_MASK;
    } else {
        syncModule.producer = false;
    }

    /* Check the Communication Cycle Period (if producer) */
    if(syncModule.producer) {
        lErrorCode = OSCOODGetU32(SYNC_COMM_CYCLE_PERIOD_IDX, SYNC_COMM_CYCLE_PERIOD_SUBIDX, &syncModule.period);
        if(OSCO_ERROR_OD_NOT_FOUND == lErrorCode) {
            /* Set the default SYNC COB-ID */
            syncModule.period = 0U;
        } else if (OSCO_ERROR_NONE != lErrorCode) {
            eprintf("[ERROR] OSCO <syncCheckODSettings> Failed to get the SYNC Communication Cycle Period Object\n");
            return lErrorCode;
        }
    }

    return lErrorCode;
}

/* Initialization */
oscoErrorCode_t OSCOSyncInit(void) {
    if(syncModule.initialized) {
        eprintf("[ERROR] OSCO <OSCOSyncInit> Service is already initialized !\n");
        return OSCO_ERROR_ALREADY_INIT;
    }

    syncModule.period   = 0U;
    syncModule.producer = false;
    syncModule.cobID    = DEFAULT_SYNC_COB_ID;

    syncModule.recvInd      = NULL;
    syncModule.preSendInd   = NULL;
    syncModule.postSendInd  = NULL;

    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    /* Set/Check the SYNC settings */
    lErrorCode = syncCheckODSettings();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOSyncInit> Failed to set/check SYNC settings\n");
        syncModule.initialized = false;
        return lErrorCode;
    }

    syncModule.initialized = true;

    return lErrorCode;
}

/* Getters */
bool OSCOSyncIsProducer(void) {
    return syncModule.producer;
}

uint32_t OSCOSyncGetCOBID(void) {
    return syncModule.cobID;
}

uint32_t OSCOSyncGetPeriod(void) {
    return syncModule.producer ? syncModule.period : 0U;
}

/* Indication function callers */
void OSCOSyncRecvInd(const uint8_t pSyncCounter) {
    if(NULL != syncModule.recvInd) {
        syncModule.recvInd(pSyncCounter);
    }
}

/* Setters */
oscoErrorCode_t OSCOSyncSetPeriod(const uint32_t pPeriodMs) {
    syncModule.period = pPeriodMs;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOSyncSetRecvIndFunction(OSCOSyncRecvInd_t pIndFct) {
    /* NULL is possible to unregister an indication function */
    syncModule.recvInd = pIndFct;
    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOSyncSetPreSendIndFunction(OSCOSyncPreSendInd_t pIndFct) {
    /* NULL is possible to unregister an indication function */
    syncModule.preSendInd = pIndFct;
    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOSyncSetPostSendIndFunction(OSCOSyncPostSendInd_t pIndFct) {
    /* NULL is possible to unregister an indication function */
    syncModule.postSendInd = pIndFct;
    return OSCO_ERROR_NONE;
}

/* Process */
oscoErrorCode_t OSCOSyncProcess(void) {
    oscoErrorCode_t lErrorCode = OSCO_ERROR_UNKNOWN;
    static uint64_t lNewTicks = 0UL, lOldTicks = 0UL;

    if(!syncModule.initialized) {
        eprintf("[ERROR] OSCO <OSCOSyncProcess> Service is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    /* Set/Check the SYNC settings in case they changed 
     * TODO : Check if they changed before changing.
     * 
     * This is useful in the case where a SDO write occured
     * on this node's SYNC entries, thus changing the settings.
     */
    lErrorCode = syncCheckODSettings();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOSyncProcess> Failed to set/check SYNC settings\n");
        return lErrorCode;
    }

    /* Send SYNC if this node is a producer and the period isn't 0 */
    if((syncModule.producer) && (0U != syncModule.period)) {
        /* Get ticks to see if it is time to send a SYNC message */
        lErrorCode = OSCOClockGetTicks(&lNewTicks);
        if(OSCO_ERROR_NONE != lErrorCode) {
            eprintf("[ERROR] OSCO <OSCOSyncProcess> OSCOClockGetTicks failed !\n");
            return OSCO_ERROR_MODULE;
        }

        if(syncModule.period <= lNewTicks - lOldTicks) {
            /* Period passed, we must send the SYNC message */

            /* Pre-send indication function call */
            if(NULL != syncModule.preSendInd) {
#ifdef OSCO_SYNC_COUNTER_ENABLED
                syncModule.preSendInd(&syncModule.counter);
#else /* OSCO_SYNC_COUNTER_ENABLED */
                syncModule.preSendInd(NULL);
#endif /* OSCO_SYNC_COUNTER_ENABLED */
            }
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

            /* Post-send indication function call */
            if(NULL != syncModule.postSendInd) {
#ifdef OSCO_SYNC_COUNTER_ENABLED
                syncModule.postSendInd(&syncModule.counter);
#else /* OSCO_SYNC_COUNTER_ENABLED */
                syncModule.postSendInd(NULL);
#endif /* OSCO_SYNC_COUNTER_ENABLED */
            }

            /* Save the new time of SYNC emission */
            lOldTicks = lNewTicks;
        }
    }

    return OSCO_ERROR_NONE;
}
