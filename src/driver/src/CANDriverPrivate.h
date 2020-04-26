/*
 * @brief Private definition of the CANDriver module's
 * internal variables. 
 * 
 * @file CANDriverPrivate.h
 */

#ifndef OSCO_CANDRIVERPRIVATE_H
#define OSCO_CANDRIVERPRIVATE_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
typedef struct _canDriverPrivateVars {
    uint8_t driverID;
    bool initialized;
    bool enabled;

    uint32_t bitRate;
} oscoCANDriverInstance_t;

#endif /* OSCO_CANDRIVERPRIVATE_H */
