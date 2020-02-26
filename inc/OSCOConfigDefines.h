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
#define OSCO_MAX_CAN_DRIVERS 1U /**< Maximum dumber of OSCOCANDriver instances */

#define OSCO_RX_FIFO_SIZE 128U /**< Size of the reception queue */
#define OSCO_TX_FIFO_SIZE 128U /**< Size of the transmission queue */

#define OSCO_SYNC_PRODUCER  1U          /**< Wether or not this node is a SYNC producer or not. 1U if it is, 0U elswise */
#define OSCO_SYNC_PERIOD    1000000U    /**< Period of the SYNC message, in us */
#define OSCO_SYNC_COUNTER_ENABLED 1U    /**< Wether or not to send the sync counter value */

#define OSCO_CLOCK_RESOLUTION 1000U /**< Resolution, in us, of the internal clock's ticks */

/* Macros ---------------------------------------------- */
/** Definition of the mutex lock and unlock functions
 * for multithreaded usage
 */
extern void OSCOMutexLockClock(void);
extern void OSCOMutexUnlockClock(void);

#ifndef OSCO_LOCK_CLOCK
#define OSCO_LOCK_CLOCK() OSCOMutexLockClock()
#endif /* OSCO_LOCK_CLOCK */

#ifndef OSCO_UNLOCK_CLOCK
#define OSCO_UNLOCK_CLOCK() OSCOMutexUnlockClock()
#endif /* OSCO_UNLOCK_CLOCK */

extern void OSCOMutexLockRxMgr(void);
extern void OSCOMutexUnlockRxMgr(void);

#ifndef OSCO_LOCK_RXMGR
#define OSCO_LOCK_RXMGR() OSCOMutexLockRxMgr()
#endif /* OSCO_LOCK_RXMGR */

#ifndef OSCO_UNLOCK_RXMGR
#define OSCO_UNLOCK_RXMGR() OSCOMutexUnlockRxMgr()
#endif /* OSCO_UNLOCK_RXMGR */

/* Type definitions ------------------------------------ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_CONFIGDEFINES_H */
