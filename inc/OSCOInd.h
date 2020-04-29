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

/* Indication function setters ------------- */
/* SYNC indication setters */
oscoErrorCode_t OSCOSyncSetRecvIndFunction(OSCOSyncRecvInd_t pIndFct);
oscoErrorCode_t OSCOSyncSetPreSendIndFunction(OSCOSyncPreSendInd_t pIndFct);
oscoErrorCode_t OSCOSyncSetPostSendIndFunction(OSCOSyncPostSendInd_t pIndFct);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_IND_H */
