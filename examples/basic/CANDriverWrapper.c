/**
 * @brief CAN Driver wrapper for the OSCO stack
 * 
 * @details The expected types are available in the OSCOTypes.h header
 *
 * @file CANDriverWrapper.c
 */

/* Includes -------------------------------------------- */
/* OSCO */
#include "OSCO.h" /* For OSCORxMgrInputMessage */
#include "OSCOTypes.h"

/* CAN Driver */
#include "can_ip.h"

/* Defines --------------------------------------------- */
#define CIP_ID   0U
#define CIP_PORT 15024
#define CIP_MODE CAN_IP_MODE_NORMAL

/* Type definitions ------------------------------------ */

/* Wrapper functions ----------------------------------- */
oscoErrorCode_t errorCodeTranslator(const cipErrorCode_t pErrorCode) {
    switch(pErrorCode) {
        case CAN_IP_ERROR_NONE:
            return OSCO_ERROR_NONE;
        case CAN_IP_ERROR_ARG:
            return OSCO_ERROR_ARG;
        case CAN_IP_ERROR_SYS:
            return OSCO_ERROR_SYS;
        case CAN_IP_ERROR_NET:
            return OSCO_ERROR_NET;
        case CAN_IP_ERROR_ALREADY_INIT:
            return OSCO_ERROR_ALREADY_INIT;
        case CAN_IP_ERROR_NOT_INIT:
            return OSCO_ERROR_NOT_INIT;
        case CAN_IP_ERROR_STOPPED:
            return OSCO_ERROR_STOPPED;
        case CAN_IP_ERROR_CONFIG:
            return OSCO_ERROR_DRIVER;
        default: /* Including CAN_IP_ERROR_UNKNOWN */
            return OSCO_ERROR_UNKNOWN;
    }
}

oscoErrorCode_t initCANDriver(void) {
    return errorCodeTranslator(CIP_init(CIP_ID, CIP_MODE, CIP_PORT));
}

oscoErrorCode_t resetCANDriver(void) {
    return errorCodeTranslator(CIP_reset(CIP_ID, CIP_MODE));
}

oscoErrorCode_t disableCANDriver(void) {
    return errorCodeTranslator(CIP_stop(CIP_ID));
}

oscoErrorCode_t setPutMsgClbk(void) {
    return errorCodeTranslator(CIP_setPutMessageFunction(CIP_ID, OSCORxMgrInputMessage));
}

oscoErrorCode_t sendCANMsg(const uint32_t pCOBID, const uint8_t pLen, const uint8_t * const pData, const uint32_t pFlags) {
    return errorCodeTranslator(CIP_send(CIP_ID, pCOBID, pLen, pData, pFlags));
}

oscoErrorCode_t CANMsgAvail(bool * const pMsgAvail) {
    return errorCodeTranslator(CIP_msgAvail(CIP_ID, pMsgAvail));
}

oscoErrorCode_t recvCANMsg(uint32_t * const pCOBID,
    uint8_t * const pLen,
    uint8_t * const pData,
    uint32_t * const pFlags)
{
    ssize_t lReadBytes = 0;
    oscoErrorCode_t lErrorCode = errorCodeTranslator(CIP_recv(CIP_ID, pCOBID, pLen, pData, pFlags, &lReadBytes));
    (void)lReadBytes;
    return lErrorCode;
}

oscoErrorCode_t startCANDriverRxThread(void) {
    return errorCodeTranslator(CIP_startRxThread(CIP_ID));
}

oscoErrorCode_t startCANDriverIsRxThreadOn(bool * const pRxIsThreadOn) {
    return errorCodeTranslator(CIP_isRxThreadOn(CIP_ID, pRxIsThreadOn));
}
