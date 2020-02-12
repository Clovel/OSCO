/*
 * @brief Implementation of interface between 
 * the CO stack and the CAN Driver.
 * 
 * @file CANDriver.c
 */

/* Includes -------------------------------------------- */
/* Custom CAN Driver API */
#include "can_ip.h"

/* OSCO Module includes */
#include "OSCOCANDriver.h"

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
oscoCANDriverInstance_t canDrivers[OSCO_MAX_CAN_DRIVERS];

/* OSCO CAN Driver functions --------------------------- */
/* Initialization */
oscoErrorCode_t OSCOCANDriverInit(const uint8_t pID, const uint16_t pBitRate) {
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverInit> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    canDrivers[pID].bitRate = pBitRate;

    cipErrorCode_t lResult = CIP_createModule(pID);
    if(CAN_IP_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOCANDriverInit> CIP_createModule failed !\n");
        return OSCO_ERROR_DRIVER;
    }

    lResult = CIP_init(pID, CAN_IP_MODE_NORMAL, 15024); /* TODO : Mode and port as stack members */
    if(CAN_IP_ERROR_NONE != lResult) {
        eprintf("[ERROR] OSCO <OSCOCANDriverInit> CIP_createModule failed !\n");
        return OSCO_ERROR_DRIVER;
    }

    return OSCO_ERROR_NONE;
}

/* Re-initialization */
oscoErrorCode_t OSCOCANDriverReinit(const uint8_t pID, const uint16_t pBitRate) {
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverReinit> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    /* TODO */

    canDrivers[pID].bitRate = pBitRate;

    return OSCO_ERROR_NONE;
}

/* Getters */
uint8_t OSCOCANDriverID(const uint8_t pID, uint8_t * const pOut) {
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverID> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOCANDriverID> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    /* pID should be equal to canDrivers[pID].id */
    *pOut = canDrivers[pID].id;

    return OSCO_ERROR_NONE;
}

uint16_t OSCOCANDriverBitRate(const uint8_t pID, uint16_t * const pOut) {
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverBitRate> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOCANDriverID> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = canDrivers[pID].bitRate;

    return OSCO_ERROR_NONE;
}

bool OSCOCANDriverIsInitialized(const uint8_t pID, bool * const pOut) {
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverIsInitialized> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOCANDriverID> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = canDrivers[pID].initialized;

    return OSCO_ERROR_NONE;
}

bool OSCOCANDriverIsEnabled(const uint8_t pID, bool * const pOut) {
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverIsEnabled> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOCANDriverID> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = canDrivers[pID].enabled;

    return OSCO_ERROR_NONE;
}

/* Setters */
oscoErrorCode_t OSCOCANDriverSetBitRate(const uint8_t pID, const uint16_t pBitRate) {
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSetBitRate> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    /* TODO */

    canDrivers[pID].bitRate = pBitRate;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOCANDriverEnable(const uint8_t pID) {
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverEnable> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    /* TODO */

    canDrivers[pID].enabled = true;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOCANDriverDisable(const uint8_t pID) {
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverDisable> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    /* TODO */

    canDrivers[pID].enabled = false;

    return OSCO_ERROR_NONE;
}

/* Send CAN message */
oscoErrorCode_t OSCOCANDriverSend(const uint8_t pID, 
    const uint32_t pMsgID,
    const uint8_t pSize,
    const uint8_t * const pData,
    const uint32_t pFlags)
{
    if(OSCO_MAX_CAN_DRIVERS <= pID) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSend> ID out of bounds !\n");
        return OSCO_ERROR_ARG;
    }

    if(!canDrivers[pID].initialized) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSend> Driver is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    if(!canDrivers[pID].enabled) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSend> Driver is not enabled !\n");
        return OSCO_ERROR_STOPPED;
    }

    if(NULL == pData) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSend> Driver is not enabled !\n");
        return OSCO_ERROR_ARG;
    }

    canMessage_t lMsg = {
        .id = pMsgID,
        .size = pSize,
        .flags = pFlags
    };
    memcpy(lMsg.data, pData, pSize);

    cipErrorCode_t lCIPError = CAN_IP_ERROR_UNKNOWN;

    lCIPError = CIP_send(pID, &lMsg);
    if(CAN_IP_ERROR_NONE != lCIPError) {
        eprintf("[ERROR] OSCO <OSCOCANDriverSend> CIP_send failed !\n");
        return OSCO_ERROR_DRIVER;
    }

    return OSCO_ERROR_NONE;
}