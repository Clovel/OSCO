/**
 * @brief OSCO PDO init implementation
 * 
 * @file PDOInit.c
 */

/* Includes -------------------------------------------- */
#include "PDOPrivate.h"
#include "OSCOPDO.h"

/* OSCO public headers */
#include "OSCO.h"
#include "OSCOPrint.h"
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoPDOInstance_t pdoModule = {
    false,
    NULL,
    NULL,
    NULL,
    NULL
};

/* Helper functions ------------------------------------ */

/* PDO initialization ---------------------------------- */
oscoErrorCode_t OSCOPDOInit(void) {
    if(pdoModule.initialized) {
        eprintf("[ERROR] OSCO <OSCOPDOInit> Service is already initialized !\n");
        return OSCO_ERROR_ALREADY_INIT;
    }

    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    pdoModule.initialized    = false;
    pdoModule.preSendIndFct  = NULL;
    pdoModule.postSendIndFct = NULL;
    pdoModule.preRecvIndFct  = NULL;
    pdoModule.postRecvIndFct = NULL;

    /* Set/Check TPDO settings */
    lErrorCode = TPDOCheckODSettings();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOPDOInit> Failed to set/check RPDO settings\n");
        pdoModule.initialized = false;
        return lErrorCode;
    }

    /* Set/Check RPDO settings */
    lErrorCode = RPDOCheckODSettings();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOPDOInit> Failed to set/check RPDO settings\n");
        pdoModule.initialized = false;
        return lErrorCode;
    }

    pdoModule.initialized = true;

    return lErrorCode;
}
