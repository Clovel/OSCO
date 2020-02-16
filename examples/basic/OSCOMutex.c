/**
 * @brief OSCO mutex external functions
 * 
 * @details This file must be implemented by the OSCO library user.
 * 
 * @file OSCOMutex.c
 */
/* Includes -------------------------------------------- */
/* C System */
#include <pthread.h>
#include <stdio.h>

/* Defines --------------------------------------------- */

/* Notes ----------------------------------------------- */

/* Variable declaration -------------------------------- */
/** @brief pthread_mutex_t oscoClockMutex
 * This mutex is used by the emotas CANOpen Clock.
 * 
 * @details A lock and unlock function should be defined
 * in the custom/application-specific definition section
 * of the CANOpen OD :
 * - OSCO_LOCK_CLOCK()
 * - OSCO_UNLOCK_CLOCK()
 */
static pthread_mutex_t oscoClockMutex = PTHREAD_MUTEX_INITIALIZER;

/* Type definitions ------------------------------------ */

/* Mutex functions ------------------------------------- */
void OSCOMutexLockClock(void) {
    //printf("[DEBUG] <OSCOMutexLockClock> Clock lock function called !\n");
    pthread_mutex_lock(&oscoClockMutex);
}

void OSCOMutexUnlockClock(void) {
    //printf("[DEBUG] <OSCOMutexLockClock> Clock unlock function called !\n");
    pthread_mutex_unlock(&oscoClockMutex);
}
