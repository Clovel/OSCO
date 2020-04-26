/*
 * @brief Interface of the SYNC service
 * 
 * @file OSCOSync.h
 */

#ifndef OSCO_SYNC_H
#define OSCO_SYNC_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* OSCO SYNC functions --------------------------------- */
/* Initialization */
/**
 * @brief Initializes the OSCO SYNC service.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOSyncInit(void);

/* Getters */

/* Setters/Modifiers */
/**
 * @brief Sets the value of the period at which
 * the SYNC message must be sent if the node is a 
 * SYNC producer.
 * 
 * @param[in]   pPeriodMs   Period in ms.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOSyncSetPeriod(const uint32_t pPeriodMs);

/* Process */
/**
 * @brief SYNC service main process
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOSyncProcess(void);

#endif /* OSCO_SYNC_H */
