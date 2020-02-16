/*
 * @brief Private definition of the OSCOSync module's
 * internal variables. 
 * 
 * @file SyncPrivate.h
 */

#ifndef OSCO_SYNCPRIVATE_H
#define OSCO_SYNCPRIVATE_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
/**
 * @brief OSCO Clock module internal variables
 */
typedef struct _syncPrivateVars {
    bool initialized;       /**< Flag indicating if the module is initialized */

    bool producer;          /**< Internal clock tick counter */
    uint32_t period;        /**< Period in ms to send the SYNC message */
    uint32_t cobID;     /**< COB-ID of the syncMessage */
} oscoSyncInstance_t;

#endif /* OSCO_SYNCPRIVATE_H */
