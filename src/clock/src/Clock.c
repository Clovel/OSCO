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
#include <limits.h>

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoCANDriverInstance_t clock;

/* OSCO CAN Driver functions --------------------------- */
/* Initialization */
oscoErrorCode_t OSCOClockInit(void) {
    clock.ticks = 0UL;
    clock.resolution = 0U;

    /* TODO */

    clock.initialized = true;

    return OSCO_ERROR_NONE;
}

/* Re-initialization */
oscoErrorCode_t OSCOClockReinit(void) {
    clock.ticks = 0UL;

    /* TODO */

    oscoErrorCode_t lResult = OSCOClockInit();
    if(OSCO_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOClockReinit> OSCOClockInit failed with error code %u", lResult);
        return lResult;
    }

    return lResult;
}

/* Getters */
oscoErrorCode_t OSCOClockGetTicks(uint64_t * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOClockGetTicks> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = clock.ticks;

    return OSCO_ERROR_NONE;
}

/* Setters/Modifiers */
oscoErrorCode_t OSCOClockTick(void) {
    /* check if the counter is not overflowing, 
     * ven though this is very unlikely. */
    if(UINT64_MAX <= clock.ticks) {
        eprintf("[WARN ] OSCO <OSCOClockTick> The clock counter is overflowing, reseting it. !\n");
        eprintf("[ERROR] OSCO <OSCOClockTick> Resetting the clock counter to 0 is unsupported !\n");
        return OSCO_ERROR_SYS;
    }
    clock.ticks++;

    return OSCO_ERROR_NONE;
}
