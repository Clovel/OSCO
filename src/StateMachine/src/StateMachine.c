/**
 * @brief OSCO state machine implementation
 * 
 * @file StateMachine.c
 */

/* Includes -------------------------------------------- */
#include "OSCOStateMachine.h"
#include "StateMachinePrivate.h"

/* OSCO public headers */
#include "OSCOPrint.h"
#include "OSCOTypes.h"

/* C system */
#include <string.h> /* memset */

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoStateMachineInstance_t stateMachine;

/* OSCO State Machine private functions ---------------- */
oscoErrorCode_t OSCOStateMachineInit(void) {
    memset(&stateMachine, 0U, sizeof(oscoStateMachineInstance_t));

    stateMachine.previousState = OSCO_STATE_UNKNOWN;
    stateMachine.currentState  = OSCO_STATE_POWER_ON_RESET;

    stateMachine.isInitialized = true;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOStateMachineReset(void) {
    oscoState_t lPreviousState = stateMachine.currentState;

    oscoErrorCode_t lErrorCode = OSCOStateMachineInit();

    stateMachine.previousState = lPreviousState;

    return lErrorCode;
}

oscoErrorCode_t OSCOGetCurrentState(oscoState_t * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOGetCurrentState> Output argument is NULL\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = stateMachine.currentState;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOGetPreviousState(oscoState_t * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOGetCurrentState> Output argument is NULL\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = stateMachine.previousState;

    return OSCO_ERROR_NONE;
}
