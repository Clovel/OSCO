/*
 * @brief OSCO initialization implementation file
 * 
 * @file OSCOInit.c
 */

/* Includes -------------------------------------------- */
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

    oscoErrorCode_t lResult = OSCO_ERROR_UNKNOWN;

    gOSCOStack.canDriverID = pID;

    /* Initialize the CAN Driver */
    lResult = OSCOCANDriverInit(gOSCOStack.canDriverID);
    if(OSCO_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOCANDriverInit failed with error code %u !\n", lResult);
        return lResult;
    }

    /* Initialize the stack's internal clock */
    lResult = OSCOClockInit();
    if(OSCO_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOInit> OSCOClockInit failed with error code %u !\n", lResult);
        return lResult;
    }

    gOSCOStack.initialized = true;

    return OSCO_ERROR_NONE;
}
