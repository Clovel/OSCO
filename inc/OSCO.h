/*
 * @brief OSCO API 
 * 
 * @file OSCO.h
 */

#ifndef OSCO_H
#define OSCO_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Initialization functions ---------------------------- */
/**
 * @brief Initialized the OSCO stack.
 * 
 * @details Initialized the following modules : 
 *  - OSCOClock
 *  - OSCOCANDriver
 * 
 * @param[in]   pID     ID of the CAN Driver uses (CAN Line)
 *
 * @return Error code
 */
oscoErrorCode_t OSCOInit(const uint8_t pID);

/* Process functions ----------------------------------- */
/**
 * @brief Main OSCO stack process.
 * 
 * @details Processes the following modules : 
 *  - OSCOClock
 *  - OSCOCANDriver
 * 
 * @param[in]   pID     ID of the CAN Driver uses (CAN Line)
 *
 * @return Error code
 */
oscoErrorCode_t OSCOProcess(const uint8_t pID);

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

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_H */
