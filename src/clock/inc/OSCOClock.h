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
/**
 * @brief Initializes the OSCO internal clock.
 * 
 * @param[in]   pResolution     Internal timer/clock's resolution
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOClockInit(const uint32_t pResolution);

/* Re-initialization */
/**
 * @brief Resets the OSCO internal clock.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOClockReset(void);

/* Getters */
/**
 * @brief Returns the current value of
 * the OSCO internal clock counter.
 * 
 * @param[out]  pOut    Pointer to the getter's output.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOClockGetTicks(uint64_t * const pOut);

/**
 * @brief Initializes Returns the value of
 * the OSCO internal clock tick interval, or resolution.
 * 
 * @param[out]  pOut    Pointer to the getter's output.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOClockGetResolution(uint32_t * const pOut);

/* Setters/Modifiers */

#endif /* OSCO_CLOCK_H */
