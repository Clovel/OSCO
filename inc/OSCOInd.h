/*
 * @brief OSCO API for indication functions
 * 
 * @file OSCOInd.h
 */

#ifndef OSCO_IND_H
#define OSCO_IND_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes -------------------------------------------- */
#include "OSCOConfigDefines.h"
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
/* SYNC indication types */
typedef void (*OSCOSyncRecvInd_t)(const uint8_t);
typedef void (*OSCOSyncPreSendInd_t)(uint8_t * const);
typedef void (*OSCOSyncPostSendInd_t)(uint8_t * const);

/* Heartbeat indication types */
typedef void (*OSCOHBRxInd_t)(const uint8_t, const uint8_t);
typedef void (*OSCOHBTxInd_t)(const uint8_t);

/* PDO indication types */
typedef oscoErrorCode_t (*OSCOPDOPreSendInd_t)(const uint16_t, const uint8_t, void * const);
typedef oscoErrorCode_t (*OSCOPDOPostSendInd_t)(const uint16_t, const uint8_t, void * const);
typedef oscoErrorCode_t (*OSCOPDOPreRecvInd_t)(const uint16_t, const uint8_t, void * const);
typedef oscoErrorCode_t (*OSCOPDOPostRecvInd_t)(const uint16_t, const uint8_t, void * const);

/* Indication function setters ------------- */
/* SYNC indication setters */
oscoErrorCode_t OSCOSyncSetRecvIndFunction(OSCOSyncRecvInd_t pIndFct);
oscoErrorCode_t OSCOSyncSetPreSendIndFunction(OSCOSyncPreSendInd_t pIndFct);
oscoErrorCode_t OSCOSyncSetPostSendIndFunction(OSCOSyncPostSendInd_t pIndFct);

/* Heartbeat indication setters */
oscoErrorCode_t OSCOHBSetRxIndFunction(OSCOHBRxInd_t pIndFct);
oscoErrorCode_t OSCOHBSetTxIndFunction(OSCOHBTxInd_t pIndFct);

/* PDO indication setters */
oscoErrorCode_t OSCOPSOSetPreSendIndFunction(OSCOHBRxInd_t pIndFct);
oscoErrorCode_t OSCOPSOSetPostSendIndFunction(OSCOHBTxInd_t pIndFct);
oscoErrorCode_t OSCOPSOSetPreRecvIndFunction(OSCOHBRxInd_t pIndFct);
oscoErrorCode_t OSCOPSOSetPostRecvIndFunction(OSCOHBTxInd_t pIndFct);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_IND_H */
