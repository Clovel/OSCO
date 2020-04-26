/*
 * @brief Reception manager interface
 * 
 * @file OSCORxMgr.h
 */

#ifndef OSCO_RXMGR_H
#define OSCO_RXMGR_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"
#include "OSCOErrorCodes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* OSCO Reception manager functions -------------------- */
/**
 * @brief Inserts a new message into the RxFifo.
 * 
 * @details This function can be given to a CAN Driver
 * stack for example.
 * 
 * @param[in]   pCOBID  COB-ID of the incoming message
 * @param[in]   pSize   DLC of the incoming message
 * @param[in]   pData   Payload of the incoming message
 * @param[in]   pFlags  Flags of the incoming message
 * 
 * @return Error code (Int for the user code can undestant the return type)
 */
int OSCORxMgrInputMessage(const uint32_t pCOBID,
    const uint8_t pSize,
    const uint8_t * const pData,
    const uint32_t pFlags);

/**
 * @brief Reception manager initialization
 * 
 * @return Error code
 */
oscoErrorCode_t OSCORxMgrInit(void);

/**
 * @brief Reception manager process
 * 
 * @return Error code
 */
oscoErrorCode_t OSCORxMgrProcess(void);


#endif /* OSCO_RXMGR_H */
