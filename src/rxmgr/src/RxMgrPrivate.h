/*
 * @brief Private definition of the OSCORxMgr module's
 * internal variables. 
 * 
 * @file RxMgrPrivate.h
 */

#ifndef OSCO_RXMGRPRIVATE_H
#define OSCO_RXMGRPRIVATE_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"
#include "OSCOConfigDefines.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
/**
 * @brief OSCO RxMgr module internal variables
 */
typedef struct _rxMgrPrivateVars {
    bool initialized;       /**< Flag indicating if the module is initialized */

    OSCOCANMessage_t fifo[OSCO_RX_FIFO_SIZE];
} oscoRxMgrInstance_t;

#endif /* OSCO_RXMGRPRIVATE_H */
