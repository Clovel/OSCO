/*
 * @brief Implementation of the stack's internal clock.
 * 
 * @file Clock.c
 */

/* Includes -------------------------------------------- */
/* OSCO Module includes */
#include "OSCOClock.h"

/* OSCO Module private includes */
#include "ClockPrivate.h"

/* OSCO public includes */
#include "OSCOTypes.h"
#include "OSCOPrint.h"
#include "OSCOConfigDefines.h"
#include "OSCO.h"

/* C system */

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoCANDriverInstance_t clock;

/* OSCO CAN Driver functions --------------------------- */
/* Initialization */
oscoErrorCode_t OSCOClockInit(void) {
    clock.ticks = 0UL;

    /* TODO */

    return OSCO_ERROR_NONE;
}

/* Re-initialization */
oscoErrorCode_t OSCOClockReinit(void) {
    clock.ticks = 0UL;

    /* TODO */

    return OSCO_ERROR_NONE;
}

/* Getters */
oscoErrorCode_t OSCOClockGetTicks(uint64_t * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOClockTick> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = clock.ticks;

    return OSCO_ERROR_NONE;
}

/* Setters/Modifiers */
oscoErrorCode_t OSCOClockTick(void) {
    clock.ticks++;

    return OSCO_ERROR_NONE;
}
