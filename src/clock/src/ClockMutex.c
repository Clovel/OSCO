/*
 * @brief Weak implementation of the Clock module's 
 * mutex functions.
 * 
 * @file ClockMutex.c
 */

/* Includes -------------------------------------------- */

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */

/* OSCO CAN Driver functions --------------------------- */
__attribute__((weak)) void OSCOMutexLockClock(void) {
    /* Empty */
}

__attribute__((weak)) void OSCOMutexUnlockClock(void) {
    /* Empty */
}
