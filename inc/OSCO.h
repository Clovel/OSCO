/*
 * @brief OSCO API 
 * 
 * @file OSCO.h
 */

#ifndef OSCO_H
#define OSCO_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Initialization functions ---------------------------- */

/* Internal stack clock functions ---------------------- */
/**
 * @brief This function increments the OSCO stack's
 * internal clock/counter. 
 * 
 * @details This function must be called at regular intervals
 * for the stack to stays synchronized and for it to
 * manager internal timed events like timeouts or
 * inhibit times.
 * Call this function several times to catch up if you are late
 * on non-threaded embedded systems for example.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOClockTick(void);

#endif /* OSCO_H */
