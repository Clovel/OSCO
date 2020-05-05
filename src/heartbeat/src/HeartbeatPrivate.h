/**
 * @brief OSCO Heartbeat private header
 * 
 * @file HeartbeatPrivate.h
 */

#ifndef HEARTBEAT_PRIVATE_H
#define HEARTBEAT_PRIVATE_H

/* Includes -------------------------------------------- */
#include "OSCOHeartbeat.h"

/* OSCO Public */
#include "OSCOInd.h"
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
typedef struct _heartbeatPrivateVars {
    bool initialized;

    bool producer;          /**< Internal clock tick counter */
    uint32_t period;        /**< Period in ms to send the HB message */

    /* Indication functions */
    OSCOHBRxInd_t rxInd;
    OSCOHBTxInd_t txInd;
} oscoHeartbeatInstance_t;

/* Variable declarations ------------------------------- */

/* OSCO Heartbeat private functions -------------------- */


#endif /* HEARTBEAT_PRIVATE_H */
