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
#define CAN_MESSAGE_MAX_SIZE 8U

/* Type definitions ------------------------------------ */

/* OSCO CAN Driver functions --------------------------- */
/* Initialization */
oscoErrorCode_t OSCOCANDriverInit(const uint8_t pID);

/* Re-initialization */
oscoErrorCode_t OSCOCANDriverReinit(const uint8_t pID);

/* Getters */
uint8_t OSCOCANDriverID(const uint8_t pID, uint8_t * const pOut);
uint16_t OSCOCANDriverBitRate(const uint8_t pID, uint32_t * const pOut);
bool OSCOCANDriverIsInitialized(const uint8_t pID, bool * const pOut);
bool OSCOCANDriverIsEnabled(const uint8_t pID, bool * const pOut);

/* Setters */
oscoErrorCode_t OSCOCANDriverSetBitRate(const uint8_t pID, const uint32_t pBitRate);
oscoErrorCode_t OSCOCANDriverEnable(const uint8_t pID);
oscoErrorCode_t OSCOCANDriverDisable(const uint8_t pID);

/* Send CAN message */
oscoErrorCode_t OSCOCANDriverSend(const uint8_t pID, 
    const uint32_t pMsgID,
    const uint8_t pSize,
    const uint8_t * const pData,
    const uint32_t pFlags);

#endif /* OSCO_CANDRIVER_H */
