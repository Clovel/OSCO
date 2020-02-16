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
#include "OSCOPrint.h"
#include "OSCO.h"

/* C system */
#include <limits.h>

/* Defines --------------------------------------------- */
#ifndef OSCO_LOCK_CLOCK
#define OSCO_LOCK_CLOCK()
#endif /* OSCO_LOCK_CLOCK */

#ifndef OSCO_UNLOCK_CLOCK
#define OSCO_UNLOCK_CLOCK()
#endif /* OSCO_UNLOCK_CLOCK */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoClockInstance_t clock;

/* OSCO CAN Driver functions --------------------------- */
/* Initialization */
oscoErrorCode_t OSCOClockInit(const uint32_t pResolution) {
    OSCO_LOCK_CLOCK();

    if(clock.initialized) {
        eprintf("[ERROR] OSCO <OSCOClockInit> Clock is already initialized !\n");
        return OSCO_ERROR_ALREADY_INIT;
    }

    clock.ticks = 0UL;
    clock.resolution = pResolution;

    /* TODO */

    clock.initialized = true;

    OSCO_UNLOCK_CLOCK();

    return OSCO_ERROR_NONE;
}

/* Re-initialization */
oscoErrorCode_t OSCOClockReset(void) {
    OSCO_LOCK_CLOCK();

    if(!clock.initialized) {
        eprintf("[ERROR] OSCO <OSCOClockReset> Clock is not initialized !\n");

        OSCO_UNLOCK_CLOCK();

        return OSCO_ERROR_NOT_INIT;
    }

    clock.ticks = 0UL;

    /* TODO */

    oscoErrorCode_t lResult = OSCOClockInit(clock.resolution);
    if(OSCO_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOClockReset> OSCOClockInit failed with error code %u", lResult);

        OSCO_UNLOCK_CLOCK();

        return lResult;
    }

    OSCO_UNLOCK_CLOCK();

    return lResult;
}

/* Getters */
oscoErrorCode_t OSCOClockGetTicks(uint64_t * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOClockGetTicks> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    OSCO_LOCK_CLOCK();

    *pOut = clock.ticks;

    OSCO_UNLOCK_CLOCK();

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOClockGetResolution(uint32_t * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOClockGetTicks> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    OSCO_LOCK_CLOCK();

    *pOut = clock.resolution;

    OSCO_UNLOCK_CLOCK();

    return OSCO_ERROR_NONE;
}

/* Setters/Modifiers */
oscoErrorCode_t OSCOClockTick(void) {
    OSCO_LOCK_CLOCK();

    if(!clock.initialized) {
        eprintf("[ERROR] OSCO <OSCOClockTick> Clock is not initialized !\n");

        OSCO_UNLOCK_CLOCK();

        return OSCO_ERROR_NOT_INIT;
    }

    /* check if the counter is not overflowing, 
     * ven though this is very unlikely. */
    if(UINT64_MAX <= clock.ticks + clock.resolution) {
        eprintf("[WARN ] OSCO <OSCOClockTick> The clock counter is overflowing, reseting it. !\n");
        eprintf("[ERROR] OSCO <OSCOClockTick> Resetting the clock counter to 0 is unsupported !\n");

        OSCO_UNLOCK_CLOCK();

        return OSCO_ERROR_SYS;
    }

    clock.ticks += clock.resolution;

    OSCO_UNLOCK_CLOCK();

    return OSCO_ERROR_NONE;
}
