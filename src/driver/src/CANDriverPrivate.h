/*
 * @brief Interface between the CO stack and the CAN Driver
 * 
 * @file osco_can_driver.h
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
} oscoCANDriverInstance_t;

#endif /* OSCO_CANDRIVERPRIVATE_H */
