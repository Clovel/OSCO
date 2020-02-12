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
    uint8_t id;
    bool initialized;
    bool enabled;

    uint32_t bitRate;

    uint8_t line;
} oscoCANDriverInstance_t;

#endif /* OSCO_CANDRIVERPRIVATE_H */
