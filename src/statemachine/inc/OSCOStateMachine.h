/**
 * @brief OSCO state machine header
 * 
 * @file OSCOStateMachine.h
 */

#ifndef OSCO_STATEMACHINE_H
#define OSCO_STATEMACHINE_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */

/* OSCO State Machine public functions ----------------- */
/**
 * @brief OSCO state machine initialization.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOStateMachineInit(void);

/**
 * @brief OSCO state machine reset.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOStateMachineReset(void);

/**
 * @brief Getter for the OSCO stack state machine's current state.
 * 
 * @param[out]  pOut    Output pointer
 *
 * @return Error code
 */
oscoErrorCode_t OSCOGetCurrentState(oscoState_t * const pOut);

/**
 * @brief Getter for the OSCO stack state machine's previous state.
 * 
 * @param[out]  pOut    Output pointer
 *
 * @return Error code
 */
oscoErrorCode_t OSCOGetPreviousState(oscoState_t * const pOut);

/**
 * @brief OSCO StateMachine process
 * 
 * @return Error Code
 */
oscoErrorCode_t OSCOStateMachineProcess(void);

#endif /* OSCO_STATEMACHINE_H */
