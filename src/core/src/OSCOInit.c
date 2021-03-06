/*
 * @brief OSCO initialization implementation file
 * 
 * @file OSCOInit.c
 */

/* Includes -------------------------------------------- */
/* OSCO HB Module */
#include "OSCOHeartbeat.h"

/* OSCO SYNC Module */
#include "OSCOSync.h"

/* OSCO Clock */
#include "OSCOClock.h"

/* OSCO Clock */
#include "OSCORxMgr.h"

/* OSCO State Machine */
#include "OSCOStateMachine.h"

/* OSCO CAN Driver */
#include "OSCOCANDriver.h"

/* OSCO private includes */
#include "OSCOPrivate.h"

/* OSCO public includes */
#include "OSCOTypes.h"
#include "OSCOPrint.h"
#include "OSCOConfigDefines.h"
#include "OSCO.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoInstance_t gOSCOStack;

/* OSCO Init functions --------------------------------- */
oscoErrorCode_t OSCOInit(const bool pThreadedRx) {
    if(true == gOSCOStack.initialized) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCO stack is already initialized !\n");
        return OSCO_ERROR_ALREADY_INIT;
    }

    oscoErrorCode_t lErrorCode = OSCO_ERROR_UNKNOWN;

    /* Initialize the CAN Driver */
    lErrorCode = OSCOCANDriverInit(pThreadedRx);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOCANDriverInit failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_DRIVER;
    }

    /* Initialize the State Machine */
    lErrorCode = OSCOStateMachineInit();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOStateMachineInit failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_DRIVER;
    }

    /* Initialize the stack's internal clock */
    lErrorCode = OSCOClockInit(OSCO_CLOCK_RESOLUTION);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOClockInit failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    /* Initialize services */
    lErrorCode = OSCOSyncSetPeriod(OSCO_SYNC_PERIOD);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOSyncSetPeriod failed with erro code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    lErrorCode = OSCOSyncInit();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOSyncInit failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    lErrorCode = OSCOHBInit();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOHBInit failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    lErrorCode = OSCORxMgrInit();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCORxMgrInit failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    gOSCOStack.initialized = true;

    return OSCO_ERROR_NONE;
}
