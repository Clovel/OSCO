/*
 * @brief Main OSCO implementation file
 * 
 * @file CANDriver.c
 */

/* Includes -------------------------------------------- */
/* OSCO Sync */
#include "OSCOSync.h"

/* OSCO Clock */
#include "OSCOClock.h"

/* OSCO RxMgr */
#include "OSCORxMgr.h"

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
extern oscoInstance_t gOSCOStack;

/* OSCO Main functions --------------------------------- */
oscoErrorCode_t OSCOProcess(const uint8_t pID) {
    if(true != gOSCOStack.initialized) {
        eprintf("[ERROR] OSCO <OSCOProcess> OSCO stack is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOProcess> Invalid OSCO stack ID !\n");
        return OSCO_ERROR_ARG;
    }

    oscoErrorCode_t lErrorCode = OSCO_ERROR_UNKNOWN;

    /* Process services */
    lErrorCode = OSCOSyncProcess(pID);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOProcess> OSCOSyncProcess failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }
    
    /* Process incoming CAN messages */
    lErrorCode = OSCORxMgrProcess(pID);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOProcess> OSCORxMgrProcess failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    /* Process outgoing CAN Messages */

    return OSCO_ERROR_NONE;
}
