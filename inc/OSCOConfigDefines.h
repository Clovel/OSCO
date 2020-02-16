/*
 * @brief Compile time configuration defines for OSCO
 * 
 * @details These are compilation-time configuration parameters. 
 * Change them to better fit your needs.
 * 
 * @file osco_can_driver.h
 */

#ifndef OSCO_CONFIGDEFINES_H
#define OSCO_CONFIGDEFINES_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes -------------------------------------------- */

/* Defines --------------------------------------------- */
#define OSCO_MAX_CAN_DRIVERS 1U /**< MAximum dumber of OSCOCANDriver instances */

/* Macros ---------------------------------------------- */
/** Definition of the mutex lock and unlock functions
 * For multithreaded usage
 */
extern void OSCOMutexLockClock(void);
extern void OSCOMutexUnlockClock(void);

#ifndef OSCO_LOCK_CLOCK
#define OSCO_LOCK_CLOCK() OSCOMutexLockClock()
#endif /* OSCO_LOCK_CLOCK */

#ifndef OSCO_UNLOCK_CLOCK
#define OSCO_UNLOCK_CLOCK() OSCOMutexUnlockClock()
#endif /* OSCO_UNLOCK_CLOCK */

/* Type definitions ------------------------------------ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_CONFIGDEFINES_H */
