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

/* OSCO State Machine process functions ---------------- */
static oscoErrorCode_t powerOnResetProcess(void) {
    /* Check the current state */
    if(OSCO_STATE_POWER_ON_RESET != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in POWER ON RESET state\n");
        return OSCO_ERROR_MODULE;
    }

    /* Check if we got here after a Node reset */
    if(OSCO_STATE_RESET_NODE != stateMachine.previousState) {
        /* TODO : Reset node (OSCO stack AND app) */
    }

    /* Switch to Initializing state */
    stateMachine.previousState = stateMachine.currentState;
    stateMachine.currentState  = OSCO_STATE_INIT;

    /* TODO : State change conditions */

    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t initProcess(void) {
    /* Check the current state */
    if(OSCO_STATE_INIT != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in INITIALIZING state\n");
        return OSCO_ERROR_MODULE;
    }

    /* Check if we got here after a Comm reset */
    if(OSCO_STATE_RESET_COMM != stateMachine.previousState) {
        /* TODO : Reset OSCO stack */
    }

    /*
     * Three possible state change causes : 
     * - Automatic
     * - User triggered change via function call
     */
    /* TODO : Check if auto-startup is enabled */
    /* TODO : Check if state change requested */

    /* Transmit Boot-Up message */
    if(OSCO_ERROR_NONE != transmitBootUpMsg()) {
        eprintf("[ERROR] OSCO <initProcess> Failed to send out the Boot-Up message\n");
        return OSCO_ERROR_DRIVER;
    }

    /* Switch to pre-operationnal state */
    stateMachine.previousState = stateMachine.currentState;
    stateMachine.currentState  = OSCO_STATE_PREOP;

    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t preOperationnalProcess(void) {
    /* Check the current state */
    if(OSCO_STATE_PREOP != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in PRE OPERATIONNAL state\n");
        return OSCO_ERROR_MODULE;
    }
    
    /* Switches to Operationnal :
     * - Auto operationnal
     * - User triggered change via function call
     * - Reception of the "Start remote node" command
     */
    /* TODO */
    /* Switches to Stopped :
     * - Reception of "Stop remote node" command
     * - User triggered change via function call
     */
    /* TODO */
    /* Switches to Reset Comm :
     * - Reception of the "Reset communication" command
     * - User triggered change via function call
     */
    /* TODO */
    /* Switches to Reset Node :
     * - Reception of the "Reset node" command
     * - User triggered change via function call
     */
    /* TODO */

    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t operationnalProcess(void) {
    /* Check the current state */
    if(OSCO_STATE_OP != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in OPERATIONNAL state\n");
        return OSCO_ERROR_MODULE;
    }
    
    /* Switches to pre-perationnal :
     * - User triggered change via function call
     * - Reception of the "Enter pre-operational state" command
     */
    /* Switches to Stopped :
     * - Reception of "Stop remote node" command
     * - User triggered change via function call
     */
    /* TODO */
    /* Switches to Reset Comm :
     * - Reception of the "Reset communication" command
     * - User triggered change via function call
     */
    /* TODO */
    /* Switches to Reset Node :
     * - Reception of the "Reset node" command
     * - User triggered change via function call
     */
    /* TODO */

    return OSCO_ERROR_NONE;
}

static oscoErrorCode_t stoppedProcess(void) {
    /* Check the current state */
    if(OSCO_STATE_STOPPED != stateMachine.currentState) {
        eprintf("[ERROR] OSCO <powerOnResetProcess> Not currently in STOPPED state\n");
        return OSCO_ERROR_MODULE;
    }
    
    /* Switches to pre-perationnal :
     * - User triggered change via function call
     * - Reception of the "Enter pre-operational state" command
     */
    /* TODO */
    /* Switches to Operationnal :
     * - Auto operationnal
     * - User triggered change via function call
     * - Reception of the "Start remote node" command
     */
    /* TODO */
    /* Switches to Reset Comm :
     * - Reception of the "Reset communication" command
     * - User triggered change via function call
     */
    /* TODO */
    /* Switches to Reset Node :
     * - Reception of the "Reset node" command
     * - User triggered change via function call
     */
    /* TODO */

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
    stateMachine.previousState = stateMachine.currentState;
    stateMachine.currentState  = OSCO_STATE_INIT;

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
    stateMachine.previousState = stateMachine.currentState;
    stateMachine.currentState  = OSCO_STATE_POWER_ON_RESET;

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
            eprintf("[ERROR] OSCO <OSCOStateMachineProcess> Unknown state");
            lErrorCode = OSCO_ERROR_SYS;
    }

    return lErrorCode;
}
