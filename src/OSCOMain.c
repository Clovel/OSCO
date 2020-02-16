/*
 * @brief Main OSCO implementation file
 * 
 * @file CANDriver.c
 */

/* Includes -------------------------------------------- */
/* OSCO Driver */
#include "OSCOCANDriver.h"

/* OSCO Clock */
#include "OSCOClock.h"

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

    oscoErrorCode_t lResult = OSCO_ERROR_UNKNOWN;
    
    /* Process incoming CAN messages */

    /* Process outgoing CAN Messages */

    return OSCO_ERROR_NONE;
}
