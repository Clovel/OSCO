/*
 * @brief Implementation of interface between 
 * the CO stack and the CAN Driver.
 * 
 * @file CANDriver.c
 */

/* Includes -------------------------------------------- */
/* OSCO Module includes */
#include "OSCOCANDriver.h"

/* OSCO Module includes */
#include "OSCORxMgr.h"

/* OSCO Module private includes */
#include "CANDriverPrivate.h"

/* OSCO public includes */
#include "OSCOTypes.h"
#include "OSCOPrint.h"
#include "OSCOConfigDefines.h"

/* C system */
#include <string.h> /* TODO : This is for memcpy. Create a toolbox for these functions */

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoCANDriverInstance_t gCANDriver;

/* OSCO CAN Driver functions --------------------------- */
/* Setup */
oscoErrorCode_t OSCOSetCANDriverFunctionSet(const OSCOCANDriverCallbacks_t pFunctionSet) {
    gCANDriver.driverFunctions = pFunctionSet;

    return OSCO_ERROR_NONE;
}

/* Initialization */
oscoErrorCode_t OSCOCANDriverInit(void) {
    oscoErrorCode_t lResult = gCANDriver.driverFunctions.init();
    if(OSCO_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOCANDriverInit> driverInit failed !\n");
        return OSCO_ERROR_DRIVER;
    }

    gCANDriver.initialized = true;

#ifdef DEBUG
    /* Set up test CAN message */
    const OSCOCANMessage_t lMsg = {
        0x987U,
        8U,
        {
            0x01U,
            0x23U,
            0x45U,
            0x67U,
            0x89U,
            0xABU,
            0xCDU,
            0xEFU
        },
        0x00000000U
    };

    lResult = gCANDriver.driverFunctions.send(lMsg.id, lMsg.size, lMsg.data, lMsg.flags);
    if(OSCO_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOCANDriverInit> driverSend failed !\n");
        return OSCO_ERROR_DRIVER;
    }
#endif /* DEBUG */

    return OSCO_ERROR_NONE;
}

/* Re-initialization */
oscoErrorCode_t OSCOCANDriverReset(void) {
    /* TODO */

    gCANDriver.driverFunctions.init          = NULL;
    gCANDriver.driverFunctions.reset         = NULL;
    gCANDriver.driverFunctions.disable       = NULL;
    gCANDriver.driverFunctions.send          = NULL;
    gCANDriver.driverFunctions.recv          = NULL;
    gCANDriver.driverFunctions.rxThreadStart = NULL;
    gCANDriver.driverFunctions.msgAvail      = NULL;

    return OSCO_ERROR_NONE;
}

/* Getters */
oscoErrorCode_t OSCOCANDriverID(uint8_t * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOCANDriverID> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    /* pID should be equal to gCANDriver.id */
    *pOut = gCANDriver.driverID;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOCANDriverIsInitialized(bool * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOCANDriverIsInitialized> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = gCANDriver.initialized;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOCANDriverIsEnabled(bool * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOCANDriverIsEnabled> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = gCANDriver.enabled;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOCANDriverBitRate(uint32_t * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOCANDriverBitRate> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = gCANDriver.bitRate;

    return OSCO_ERROR_NONE;
}

/* Setters */
oscoErrorCode_t OSCOCANDriverEnable() {
    oscoErrorCode_t lResult = gCANDriver.driverFunctions.rxThreadStart();
    if(OSCO_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOCANDriverEnable> driverRxThreadStart failed !\n");
        return OSCO_ERROR_DRIVER;
    }

    gCANDriver.enabled = true;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOCANDriverDisable() {
    /* TODO */
    oscoErrorCode_t lResult = gCANDriver.driverFunctions.disable();
    if(OSCO_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOCANDriverDisable> driverDisable failed !\n");
        return OSCO_ERROR_DRIVER;
    }

    gCANDriver.enabled = false;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOCANDriverSetBitRate(const uint32_t pBitRate) {
    /* TODO */

    gCANDriver.bitRate = pBitRate;

    return OSCO_ERROR_NONE;
}

/* Send CAN message */
oscoErrorCode_t OSCOCANDriverSend(const uint32_t pMsgID,
    const uint8_t pSize,
    const uint8_t * const pData,
    const uint32_t pFlags)
{
    if(!gCANDriver.initialized) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSend> Driver is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    if(!gCANDriver.enabled) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSend> Driver is not enabled !\n");
        return OSCO_ERROR_STOPPED;
    }

    if(NULL == pData && 0U < pSize) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSend> Data pointer is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    oscoErrorCode_t lResult = gCANDriver.driverFunctions.send(pMsgID, pSize, pData, pFlags);
    if(OSCO_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSend> CIP_send failed with error code %u !\n", lResult);
        return OSCO_ERROR_DRIVER;
    }

    return OSCO_ERROR_NONE;
}
