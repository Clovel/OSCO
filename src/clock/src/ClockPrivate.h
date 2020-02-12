/*
 * @brief Private definition of the OSCOClock module's
 * internal variables. 
 * 
 * @file ClockPrivate.h
 */

#ifndef OSCO_CLOCKPRIVATE_H
#define OSCO_CLOCKPRIVATE_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
/**
 * @brief OSCO Clock module internal variables
 */
typedef struct _canDriverPrivateVars {
    bool initialized;       /**< Flag indicating if the module is initialized */
    uint64_t ticks;         /**< Internal clock tick counter */
    uint32_t resolution;    /**< Internal clock tick time interval */
} oscoCANDriverInstance_t;

#endif /* OSCO_CLOCKPRIVATE_H */
