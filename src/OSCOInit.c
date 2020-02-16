/*
 * @brief OSCO initialization implementation file
 * 
 * @file OSCOInit.c
 */

/* Includes -------------------------------------------- */
/* OSCO SYNC Module */
#include "OSCOSync.h"

/* OSCO Clock */
#include "OSCOClock.h"

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
oscoErrorCode_t OSCOInit(const uint8_t pID) {
    if(true == gOSCOStack.initialized) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCO stack is already initialized !\n");
        return OSCO_ERROR_ALREADY_INIT;
    }

    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOInit> Invalid OSCO stack ID !\n");
        return OSCO_ERROR_ARG;
    }

    oscoErrorCode_t lErrorCode = OSCO_ERROR_UNKNOWN;

    gOSCOStack.canDriverID = pID;

    /* Initialize the CAN Driver */
    lErrorCode = OSCOCANDriverInit(gOSCOStack.canDriverID);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOCANDriverInit failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_DRIVER;
    }

    lErrorCode = OSCOCANDriverEnable(gOSCOStack.canDriverID);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOCANDriverEnable failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_DRIVER;
    }

    /* Initialize the stack's internal clock */
    lErrorCode = OSCOClockInit(OSCO_CLOCK_RESOLUTION);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOClockInit failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    /* Initialize services */
    lErrorCode = OSCOSyncSetPeriod(pID, OSCO_SYNC_PERIOD);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOSyncSetPeriod failed with erro code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    lErrorCode = OSCOSyncInit(pID);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOSyncInit failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    gOSCOStack.initialized = true;

    return OSCO_ERROR_NONE;
}
