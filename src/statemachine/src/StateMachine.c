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
/* Need to init this statically to use as "extern" in other files */
oscoStateMachineInstance_t stateMachine = {
    false
};

/* OSCO State Machine private functions ---------------- */
oscoErrorCode_t OSCOStateMachineInit(void) {
    memset(&stateMachine, 0U, sizeof(oscoStateMachineInstance_t));

    stateMachine.previousState  = OSCO_STATE_UNKNOWN;
    stateMachine.currentState   = OSCO_STATE_POWER_ON_RESET;
    stateMachine.requestedState = OSCO_STATE_UNKNOWN; 

    stateMachine.isInitialized = true;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOStateMachineReset(void) {
    oscoState_t lPreviousState = stateMachine.currentState;

    oscoErrorCode_t lErrorCode = OSCOStateMachineInit();

    stateMachine.previousState = lPreviousState;

    return lErrorCode;
}

/* Getters */
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

/* Setters */
oscoErrorCode_t OSCORequestState(const oscoState_t pRequestedState) {
    if(stateMachine.currentState == pRequestedState) {
        /* No need to request this, the stack is already in the requested state */
        return OSCO_ERROR_NONE;
    }

    switch(pRequestedState) {
        case OSCO_STATE_PREOP:
        case OSCO_STATE_OP:
        case OSCO_STATE_STOPPED:
            stateMachine.requestedState = pRequestedState;
            break;
        case OSCO_STATE_RESET_COMM:
            if(OSCO_STATE_RESET_NODE == stateMachine.currentState) {
                eprintf("[ERROR] OSCO <OSCORequestState> Cannot request RESET_COMM state while in RESET_NODE state\n");
                return OSCO_ERROR_ARG;
            }
            stateMachine.requestedState = pRequestedState;
            break;
        case OSCO_STATE_RESET_NODE:
            if(OSCO_STATE_RESET_COMM == stateMachine.currentState) {
                eprintf("[ERROR] OSCO <OSCORequestState> Cannot request RESET_NODE state while in RESET_COMM state\n");
                return OSCO_ERROR_ARG;
            }
            stateMachine.requestedState = pRequestedState;
            break;
        case OSCO_STATE_POWER_ON_RESET:
        case OSCO_STATE_INIT:
            eprintf("[ERROR] OSCO <OSCORequestState> Cannot request this state (%u)\n", pRequestedState);
            return OSCO_ERROR_ARG;
        case OSCO_STATE_UNKNOWN:
        default:
            eprintf("[ERROR] OSCO <OSCORequestState> Unknown state (%u)\n", pRequestedState);
            return OSCO_ERROR_ARG;
    }

    return OSCO_ERROR_NONE;
}
