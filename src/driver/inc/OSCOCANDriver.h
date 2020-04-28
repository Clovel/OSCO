/*
 * @brief Interface between the CO stack and the CAN Driver
 * 
 * @file OSCOCANDriver.h
 */

#ifndef OSCO_CANDRIVER_H
#define OSCO_CANDRIVER_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* OSCO CAN Driver functions --------------------------- */
/* Initialization */
oscoErrorCode_t OSCOCANDriverInit(const bool pThreadedRx);

/* Re-initialization */
oscoErrorCode_t OSCOCANDriverReset(void);

/* Getters */
oscoErrorCode_t OSCOCANDriverID(uint8_t * const pOut);
oscoErrorCode_t OSCOCANDriverIsInitialized(bool * const pOut);
oscoErrorCode_t OSCOCANDriverIsEnabled(bool * const pOut);
oscoErrorCode_t OSCOCANDriverBitRate(uint32_t * const pOut);
oscoErrorCode_t OSCOCANDriverIsThreadedRx(bool * const pOut);

/* Setters */
oscoErrorCode_t OSCOCANDriverSetBitRate(const uint32_t pBitRate);

/* Process */
oscoErrorCode_t OSCOCANDriverProcess(void);

/* Send CAN message */
oscoErrorCode_t OSCOCANDriverSend(const uint32_t pMsgID,
    const uint8_t pSize,
    const uint8_t * const pData,
    const uint32_t pFlags);

#endif /* OSCO_CANDRIVER_H */
