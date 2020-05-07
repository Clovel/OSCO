/*
 * @brief OSCO API 
 * 
 * @file OSCO.h
 */

#ifndef OSCO_H
#define OSCO_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes -------------------------------------------- */
/* API headers */
#include "OSCOInd.h"

/* Configuration */
#include "OSCOConfigDefines.h"

/* Types */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* CAN driver functions -------------------------------- */
/**
 * @brief Sets the functions for the CAN Driver layer of the
 * OSCO stack.
 * 
 * @details This allows the user to build his own functions
 * with the driver of his choosing.
 *
 * @param[in]   pFunctionSet    Set of CAN driver functions
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOSetCANDriverFunctionSet(const OSCOCANDriverCallbacks_t pFunctionSet);
oscoErrorCode_t OSCOCANDriverIsInitialized(bool * const pOut);
oscoErrorCode_t OSCOCANDriverIsEnabled(bool * const pOut);
oscoErrorCode_t OSCOCANDriverEnable(void);
oscoErrorCode_t OSCOCANDriverDisable(void);

/* Initialization functions ---------------------------- */
/**
 * @brief Initialized the OSCO stack.
 * 
 * @details Initialized the following modules : 
 *  - OSCOClock
 *  - OSCOCANDriver
 * 
 * @param[in]   pThreadedRx     Indicates if a threaded reception process
 *      is to be used by the OSCO stack.
 *
 * @return Error code
 */
oscoErrorCode_t OSCOInit(const bool pThreadedRx);

/* Process functions ----------------------------------- */
/**
 * @brief Main OSCO stack process.
 * 
 * @details Processes the following modules : 
 *  - OSCOClock
 *  - OSCOCANDriver
 *
 * @return Error code
 */
oscoErrorCode_t OSCOProcess(void);

/* Internal stack clock functions ---------------------- */
/**
 * @brief This function increments the OSCO stack's
 * internal clock/counter. 
 * 
 * @details This function must be called at regular intervals
 * for the stack to stays synchronized and for it to
 * manager internal timed events like timeouts or
 * inhibit times.
 * Call this function several times to catch up if you are late
 * on non-threaded embedded systems for example.
 * 
 * @return Error code
 */
oscoErrorCode_t OSCOClockTick(void);

/* Stack data access functions ------------------------- */
/* Getters */
uint8_t OSCOGetNodeID(void);

/* Stack state machine functions ----------------------- */
oscoErrorCode_t OSCORequestState(const oscoState_t pRequestedState);

/* Setters */
oscoErrorCode_t OSCOSetNodeID(const uint8_t pNodeID);

/* OD Access functions --------------------------------- */
oscoErrorCode_t OSCOODGetU8(const uint16_t pIdx,
    const uint8_t pSubIdx,
    uint8_t * const pOut);

oscoErrorCode_t OSCOODGetU16(const uint16_t pIdx,
    const uint8_t pSubIdx,
    uint16_t * const pOut);

oscoErrorCode_t OSCOODGetU32(const uint16_t pIdx,
    const uint8_t pSubIdx,
    uint32_t * const pOut);

oscoErrorCode_t OSCOODGetU64(const uint16_t pIdx,
    const uint8_t pSubIdx,
    uint64_t * const pOut);

oscoErrorCode_t OSCOODGetI8(const uint16_t pIdx,
    const uint8_t pSubIdx,
    int8_t * const pOut);

oscoErrorCode_t OSCOODGetI16(const uint16_t pIdx,
    const uint8_t pSubIdx,
    int16_t * const pOut);

oscoErrorCode_t OSCOODGetI32(const uint16_t pIdx,
    const uint8_t pSubIdx,
    int32_t * const pOut);

oscoErrorCode_t OSCOODGetI64(const uint16_t pIdx,
    const uint8_t pSubIdx,
    int64_t * const pOut);

/* Reception manager functions ------------------------- */
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
oscoErrorCode_t OSCORxMgrInputMessage(const uint32_t pCOBID,
    const uint8_t pSize,
    const uint8_t * const pData,
    const uint32_t pFlags);

/* PDO functions --------------------------------------- */
oscoErrorCode_t OSCOTriggerTPDOs(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_H */
