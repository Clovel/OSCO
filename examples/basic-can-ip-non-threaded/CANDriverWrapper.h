/**
 * @brief CAN Driver wrapper for the OSCO stack
 * 
 * @details The expected types are available in the OSCOTypes.h header
 *
 * @file CANDriverWrapper.h
 */

#ifndef CANDRIVERWRAPPER_H
#define CANDRIVERWRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes -------------------------------------------- */
/* OSCO */
#include "OSCOTypes.h"

/* CAN Driver */
#include "can_ip.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Wrapper functions ----------------------------------- */
oscoErrorCode_t errorCodeTranslator(const cipErrorCode_t pErrorCode);
oscoErrorCode_t initCANDriver(void);
oscoErrorCode_t resetCANDriver(void);
oscoErrorCode_t disableCANDriver(void);
oscoErrorCode_t setPutMsgClbk(void);
oscoErrorCode_t sendCANMsg(const uint32_t pCOBID,
    const uint8_t pLen,
    const uint8_t * const pData,
    const uint32_t pFlags);
oscoErrorCode_t CANMsgAvail(bool * const pMsgAvail);
oscoErrorCode_t recvCANMsg(uint32_t * const pCOBID,
    uint8_t * const pLen,
    uint8_t * const pData,
    uint32_t * const pFlags);
oscoErrorCode_t startCANDriverRxThread(void);
oscoErrorCode_t startCANDriverIsRxThreadOn(bool * const pRxIsThreadOn);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*  CANDRIVERWRAPPER_H */
