/**
 * @brief OSCO PDO private header
 * 
 * @file PDOPrivate.h
 */

#ifndef PDO_PRIVATE_H
#define PDO_PRIVATE_H

/* Includes -------------------------------------------- */
#include "OSCOPDO.h"

/* OSCO Public */
#include "OSCOInd.h"
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
typedef struct _PDOPrivateVars {
    bool initialized;

    /* Indication functions */
    OSCOPDOPreSendInd_t  preSendIndFct;
    OSCOPDOPostSendInd_t postSendIndFct;
    OSCOPDOPreRecvInd_t  preRecvIndFct;
    OSCOPDOPostRecvInd_t postRecvIndFct;
} oscoPDOInstance_t;

/* Variable declarations ------------------------------- */

/* OSCO PDO private functions -------------------------- */
oscoErrorCode_t TPDOCheckODSettings(void);
oscoErrorCode_t RPDOCheckODSettings(void);


#endif /* PDO_PRIVATE_H */
