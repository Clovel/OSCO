/*
 * @brief Private definition of the OSCOSync module's
 * internal variables. 
 * 
 * @file SyncPrivate.h
 */

#ifndef OSCO_SYNCPRIVATE_H
#define OSCO_SYNCPRIVATE_H

/* Includes -------------------------------------------- */
/* OSCO API */
#include "OSCOInd.h"

/* Configuration */
#include "OSCOConfigDefines.h"

/* Types */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/**
 * @brief OSCO Sync module internal variables
 */
typedef struct _syncPrivateVars {
    bool initialized;       /**< Flag indicating if the module is initialized */

    bool producer;          /**< Internal clock tick counter */
    uint32_t period;        /**< Period in ms to send the SYNC message */
    uint32_t cobID;         /**< COB-ID of the syncMessage */

#ifdef OSCO_SYNC_COUNTER_ENABLED
    uint8_t counter;        /**< SYNC Counter */
#endif /* OSCO_SYNC_COUNTER_ENABLED */

    /* Indication functions */
    OSCOSyncRecvInd_t       recvInd;
    OSCOSyncPreSendInd_t    preSendInd;
    OSCOSyncPostSendInd_t   postSendInd;
} oscoSyncInstance_t;

#endif /* OSCO_SYNCPRIVATE_H */
