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
    bool initialized; /**< Flag indicating if the module is initialized */

    /* Message-per-message FIFO related variables */
    OSCOCANMessage_t fifo[OSCO_RX_FIFO_SIZE];   /**< Message-per-message FIFO buffer */
    size_t rIdx;                                /**< Message-per-message FIFO buffer read index */
    size_t wIdx;                                /**< Message-per-message FIFO buffer write index */
    uint32_t rIdxWrapAround;                    /**< Read index wraparound counter */
    uint32_t wIdxWrapAround;                    /**< Write index wraparound counter */
} oscoRxMgrInstance_t;

#endif /* OSCO_RXMGRPRIVATE_H */
