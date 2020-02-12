/*
 * @brief Interface of the stack's internal clock
 * 
 * @file OSCOClock.h
 */

#ifndef OSCO_CLOCK_H
#define OSCO_CLOCK_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* OSCO Clock functions -------------------------------- */
/* Initialization */
oscoErrorCode_t OSCOClockInit(void);

/* Re-initialization */
oscoErrorCode_t OSCOClockReset(void);

/* Getters */
oscoErrorCode_t OSCOClockGetTicks(uint64_t * const pOut);
oscoErrorCode_t OSCOClockGetResolution(uint32_t * const pOut);

/* Setters/Modifiers */

#endif /* OSCO_CLOCK_H */
