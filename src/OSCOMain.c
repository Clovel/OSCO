/*
 * @brief Main OSCO implementation file
 * 
 * @file CANDriver.c
 */

/* Includes -------------------------------------------- */
/* OSCO CAN Driver */
#include "OSCOCANDriver.h"

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
oscoErrorCode_t OSCOProcess(void) {
    if(true != gOSCOStack.initialized) {
        eprintf("[ERROR] OSCO <OSCOProcess> OSCO stack is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    oscoErrorCode_t lErrorCode = OSCO_ERROR_UNKNOWN;

    /* CAN driver process */
    lErrorCode = OSCOCANDriverProcess();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOProcess> OSCOCANDriverProcess failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    /* Process services */
    lErrorCode = OSCOSyncProcess();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOProcess> OSCOSyncProcess failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }
    
    /* Process incoming CAN messages */
    lErrorCode = OSCORxMgrProcess();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOProcess> OSCORxMgrProcess failed with error code %u !\n", lErrorCode);
        return OSCO_ERROR_MODULE;
    }

    /* Process outgoing CAN Messages */

    return OSCO_ERROR_NONE;
}
