/*
 * @brief Private definition of the CANDriver module's
 * internal variables. 
 * 
 * @file CANDriverPrivate.h
 */

#ifndef OSCO_CLOCKPRIVATE_H
#define OSCO_CLOCKPRIVATE_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
typedef struct _canDriverPrivateVars {
    bool initialized;

    uint64_t ticks;
    uint32_t resolution;
} oscoCANDriverInstance_t;

#endif /* OSCO_CLOCKPRIVATE_H */
