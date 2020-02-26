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
 * @param[in]   pID     ID of the module.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOSyncInit(const uint8_t pID);

/* Getters */

/* Setters/Modifiers */
/**
 * @brief Sets the value of the period at which
 * the SYNC message must be sent if the node is a 
 * SYNC producer.
 * 
 * @param[in]   pID         ID of the module.
 * @param[in]   pPeriodMs   Period in ms.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOSyncSetPeriod(const uint8_t pID, const uint32_t pPeriodMs);

/* Process */
/**
 * @brief SYNC service main process
 * 
 * @param[in]   pID     ID of the module.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOSyncProcess(const uint8_t pID);

#endif /* OSCO_SYNC_H */
