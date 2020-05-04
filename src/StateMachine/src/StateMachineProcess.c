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

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
extern oscoStateMachineInstance_t stateMachine;

/* Helper functions ------------------------------------ */
static void changeState(const oscoState_t pNewState) {
    stateMachine.previousState = stateMachine.currentState;
    stateMachine.currentState  = pNewState;
}

/* OSCO State Machine process functions ---------------- */
static oscoErrorCode_t powerOnResetProcess(void) {
    static bool lFirstCall = true;

    /* Check the current state */
    if(OSCO_STATE_POWER_ON_RESET != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in POWER ON RESET state\n");
        return OSCO_ERROR_MODULE;
    }

    if(lFirstCall) {
        /* Specific action to do when entering this state */

        lFirstCall = false;
    }

    /*
     * State change causes :
     * - Automatic
     */

    /* Switch to Initializing state */
    changeState(OSCO_STATE_INIT);

    /* Reset the "first call" flag for next time */
    lFirstCall = true;

    /* TODO : State change conditions */

    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t initProcess(void) {
    static bool lFirstCall = true;

    /* Check the current state */
    if(OSCO_STATE_INIT != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in INITIALIZING state\n");
        return OSCO_ERROR_MODULE;
    }

    /* TODO : Initialize stack */
    
    if(lFirstCall) {
        /* Transmit Boot-Up message (once) */
        if(OSCO_ERROR_NONE != transmitBootUpMsg()) {
            eprintf("[ERROR] OSCO <initProcess> Failed to send out the Boot-Up message\n");
            return OSCO_ERROR_DRIVER;
        }

        lFirstCall = false;
    }

    /*
     * Three possible state change causes : 
     * - Automatic
     * - User triggered change via function call
     */
    /* TODO : Check if auto-startup is enabled */
    if((OSCO_STATE_PREOP == stateMachine.requestedState) 
        || (false /* TODO : Auto-startup */))
    {
        /* State change requested (PRE OPERATIONNAL) */

        /* Switch to pre-operationnal state */
        changeState(OSCO_STATE_PREOP);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;

        /* Reset the "first call" flag for next time */
        lFirstCall = true;
    }


    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t preOperationnalProcess(void) {
    static bool lFirstCall = true;

    /* Check the current state */
    if(OSCO_STATE_PREOP != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in PRE OPERATIONNAL state\n");
        return OSCO_ERROR_MODULE;
    }

    if(lFirstCall) {
        /* Specific action to do when entering this state */

        lFirstCall = false;
    }
    
    /* Switches to Operationnal :
     * - Auto operationnal
     * - User triggered change via function call
     * - Reception of the "Start remote node" command
     */
    if((OSCO_STATE_OP == stateMachine.requestedState)
        || (false /* TODO : Auto operationnal state change */))
    {
        /* State change requested (OPERATIONNAL) */

        /* Switch to operationnal state */
        changeState(OSCO_STATE_OP);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }
    /* Switches to Stopped :
     * - Reception of "Stop remote node" command
     * - User triggered change via function call
     */
    else if(OSCO_STATE_STOPPED == stateMachine.requestedState)
    {
        /* State change requested (STOPPED) */

        /* Switch to stopped state */
        changeState(OSCO_STATE_STOPPED);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }
    /* Switches to Reset Comm :
     * - Reception of the "Reset communication" command
     * - User triggered change via function call
     */
    else if(OSCO_STATE_RESET_COMM == stateMachine.requestedState)
    {
        /* State change requested (RESET COMM) */

        /* Switch to reset comm state */
        changeState(OSCO_STATE_RESET_COMM);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }
    /* Switches to Reset Node :
     * - Reception of the "Reset node" command
     * - User triggered change via function call
     */
    else if(OSCO_STATE_RESET_NODE == stateMachine.requestedState)
    {
        /* State change requested (RESET NODE) */

        /* Switch to reset node state */
        changeState(OSCO_STATE_RESET_NODE);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }

    if(OSCO_STATE_PREOP != stateMachine.currentState) {
        /* Changing state, reset first call flag for next time */
        lFirstCall = true;
    }

    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t operationnalProcess(void) {
    static bool lFirstCall = true;

    /* Check the current state */
    if(OSCO_STATE_OP != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in OPERATIONNAL state\n");
        return OSCO_ERROR_MODULE;
    }
    
    /* Switches to pre-perationnal :
     * - User triggered change via function call
     * - Reception of the "Enter pre-operational state" command
     */
    if(OSCO_STATE_PREOP == stateMachine.requestedState)
    {
        /* State change requested (PRE OPERATIONNAL) */

        /* Switch to pre-operationnal state */
        changeState(OSCO_STATE_PREOP);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }
    /* Switches to Stopped :
     * - Reception of "Stop remote node" command
     * - User triggered change via function call
     */
    else if(OSCO_STATE_STOPPED == stateMachine.requestedState)
    {
        /* State change requested (STOPPED) */

        /* Switch to stopped state */
        changeState(OSCO_STATE_STOPPED);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }
    /* Switches to Reset Comm :
     * - Reception of the "Reset communication" command
     * - User triggered change via function call
     */
    else if(OSCO_STATE_RESET_COMM == stateMachine.requestedState)
    {
        /* State change requested (RESET COMM) */

        /* Switch to reset comm state */
        changeState(OSCO_STATE_RESET_COMM);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }
    /* Switches to Reset Node :
     * - Reception of the "Reset node" command
     * - User triggered change via function call
     */
    else if(OSCO_STATE_RESET_NODE == stateMachine.requestedState)
    {
        /* State change requested (RESET NODE) */

        /* Switch to reset node state */
        changeState(OSCO_STATE_RESET_NODE);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }

    if(OSCO_STATE_OP != stateMachine.currentState) {
        /* Changing state, reset first call flag for next time */
        lFirstCall = true;
    }

    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t stoppedProcess(void) {
    static bool lFirstCall = true;
    /* Check the current state */
    if(OSCO_STATE_STOPPED != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in STOPPED state\n");
        return OSCO_ERROR_MODULE;
    }
    
    /* Switches to pre-perationnal :
     * - User triggered change via function call
     * - Reception of the "Enter pre-operational state" command
     */
    if(OSCO_STATE_PREOP == stateMachine.requestedState)
    {
        /* State change requested (PRE OPERATIONNAL) */

        /* Switch to pre-operationnal state */
        changeState(OSCO_STATE_PREOP);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }
    /* Switches to Operationnal :
     * - Auto operationnal
     * - User triggered change via function call
     * - Reception of the "Start remote node" command
     */
    else if((OSCO_STATE_OP == stateMachine.requestedState)
        || (false /* TODO : Auto operationnal state change */))
    {
        /* State change requested (OPERATIONNAL) */

        /* Switch to operationnal state */
        changeState(OSCO_STATE_OP);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }
    /* Switches to Reset Comm :
     * - Reception of the "Reset communication" command
     * - User triggered change via function call
     */
    else if(OSCO_STATE_RESET_COMM == stateMachine.requestedState)
    {
        /* State change requested (RESET COMM) */

        /* Switch to reset comm state */
        changeState(OSCO_STATE_RESET_COMM);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }
    /* Switches to Reset Node :
     * - Reception of the "Reset node" command
     * - User triggered change via function call
     */
    else if(OSCO_STATE_RESET_NODE == stateMachine.requestedState)
    {
        /* State change requested (RESET NODE) */

        /* Switch to reset node state */
        changeState(OSCO_STATE_RESET_NODE);
        stateMachine.requestedState = OSCO_STATE_UNKNOWN;
    }

    if(OSCO_STATE_OP != stateMachine.currentState) {
        /* Changing state, reset first call flag for next time */
        lFirstCall = true;
    }

    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t resetCommProcess(void) {
    /* Check the current state */
    if(OSCO_STATE_RESET_COMM != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in RESET COMM state\n");
        return OSCO_ERROR_MODULE;
    }
    
    /* TODO : Reset OSCO stack */

    /* Switch to initializing state */
    changeState(OSCO_STATE_INIT);

    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t resetNodeProcess(void) {
    /* Check the current state */
    if(OSCO_STATE_RESET_NODE != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in RESET NODE state\n");
        return OSCO_ERROR_MODULE;
    }
    
    /* TODO : Reset OSCO stack AND application */

    /* Switch to initializing state */
    changeState(OSCO_STATE_POWER_ON_RESET);

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOStateMachineProcess(void) {
    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    switch(stateMachine.currentState) {
        case OSCO_STATE_POWER_ON_RESET:
            lErrorCode = powerOnResetProcess();
            break;
        case OSCO_STATE_INIT:
            lErrorCode = initProcess();
            break;
        case OSCO_STATE_PREOP:
            lErrorCode = preOperationnalProcess();
            break;
        case OSCO_STATE_OP:
            lErrorCode = operationnalProcess();
            break;
        case OSCO_STATE_STOPPED:
            lErrorCode = stoppedProcess();
            break;
        case OSCO_STATE_RESET_COMM:
            lErrorCode = resetCommProcess();
            break;
        case OSCO_STATE_RESET_NODE:
            lErrorCode = resetNodeProcess();
            break;
        case OSCO_STATE_UNKNOWN:
        default:
            eprintf("[ERROR] OSCO <OSCOStateMachineProcess> Unknown state (%u) \n", stateMachine.currentState);
            lErrorCode = OSCO_ERROR_SYS;
    }

    return lErrorCode;
}
