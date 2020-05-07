/**
 * @brief OSCO PDO init implementation
 * 
 * @file PDOInit.c
 */

/* Includes -------------------------------------------- */
#include "PDOPrivate.h"
#include "OSCOPDO.h"

/* OSCO public headers */
#include "OSCOInd.h"
#include "OSCOPrint.h"
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
extern oscoPDOInstance_t pdoModule;

/* Helper functions ------------------------------------ */

/* PDO indication setters ------------------------------ */
oscoErrorCode_t OSCOPSOSetPreSendIndFunction(OSCOHBRxInd_t pIndFct) {
    if(NULL == pIndFct) {
        eprintf("[ERROR] OSCO <OSCOPSOSetPreSendIndFunction> Arg function ptr is NULL\n");
        return OSCO_ERROR_ARG;
    }

    pdoModule.preSendIndFct = pIndFct;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOPSOSetPostSendIndFunction(OSCOHBTxInd_t pIndFct) {
    if(NULL == pIndFct) {
        eprintf("[ERROR] OSCO <OSCOPSOSetPostSendIndFunction> Arg function ptr is NULL\n");
        return OSCO_ERROR_ARG;
    }

    pdoModule.postSendIndFct = pIndFct;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOPSOSetPreRecvIndFunction(OSCOHBRxInd_t pIndFct) {
    if(NULL == pIndFct) {
        eprintf("[ERROR] OSCO <OSCOPSOSetPreRecvIndFunction> Arg function ptr is NULL\n");
        return OSCO_ERROR_ARG;
    }

    pdoModule.preRecvIndFct = pIndFct;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOPSOSetPostRecvIndFunction(OSCOHBTxInd_t pIndFct) {
    if(NULL == pIndFct) {
        eprintf("[ERROR] OSCO <OSCOPSOSetPostRecvIndFunction> Arg function ptr is NULL\n");
        return OSCO_ERROR_ARG;
    }

    pdoModule.postRecvIndFct = pIndFct;

    return OSCO_ERROR_NONE;
}
