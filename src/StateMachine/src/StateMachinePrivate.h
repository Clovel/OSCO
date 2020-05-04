/**
 * @brief OSCO state machine private header
 * 
 * @file StateMachinePrivate.h
 */

#ifndef STATEMACHINE_PRIVATE_H
#define STATEMACHINE_PRIVATE_H

/* Includes -------------------------------------------- */
#include "OSCOStateMachine.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
typedef struct _stateMachinePrivateVars {
    bool isInitialized;

    oscoState_t currentState;
    oscoState_t previousState;
} oscoStateMachineInstance_t;

/* Variable declarations ------------------------------- */

/* OSCO State Machine private functions ---------------- */
oscoErrorCode_t transmitBootUpMsg(void);

#endif /* STATEMACHINE_PRIVATE_H */
