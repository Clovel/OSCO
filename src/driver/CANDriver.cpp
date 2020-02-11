/**
 * @brief CAN Driver interface implementation
 * 
 * @details This file is to be modified by the developpers
 * to adapt to their CAN Driver. 
 * 
 * @file CANDriver.hpp
 */

/* Includes -------------------------------------------- */
/* Custom CAN Driver API */
#include "can_ip.h"

/* OSCO Includes */
#include "CANDriver.hpp"

/* C++ system */
#include <iostream>

/* C tools */
#include <string.h> /* TODO : This is for memcpy. Create a toolbox for these functions */

/* Defines --------------------------------------------- */

namespace osco::driver {
/* Driver class implementation ------------------------- */

    /* Constructor */
    CANDriver::CANDriver(const uint8_t &pID) :
        mID(pID)
    {
        /* Empty */
    }

    /* Destructor */
    CANDriver::~CANDriver() {
        /* Empty */
    }

    /* Initialization */
    oscoErrorCode_t CANDriver::init(const uint16_t &pBitRate) {
        int lResult = 0;

        mBitRate = pBitRate;

        lResult = CIP_createModule(mID);
        if(CAN_IP_ERROR_NONE != lResult) {
            std::cerr << "[ERROR] OSCO <CANDriver::init> CIP_createModule failed !" << std::endl;
            return OSCO_ERROR_DRIVER;
        }

        lResult = CIP_init(mID, CAN_IP_MODE_NORMAL, 15024); /* TODO : Mode and port as stack members */
        if(CAN_IP_ERROR_NONE != lResult) {
            std::cerr << "[ERROR] OSCO <CANDriver::init> CIP_createModule failed !" << std::endl;
            return OSCO_ERROR_DRIVER;
        }

        return OSCO_ERROR_NONE;
    }

    /* Re-initialization */
    oscoErrorCode_t CANDriver::reinit(const uint16_t &pBitRate) {
        mBitRate = pBitRate;

        return OSCO_ERROR_NONE;
    }

    /* Getters */
    uint8_t  CANDriver::id(void) const {
        return mID;
    }

    uint16_t CANDriver::bitRate(void) const {
        return mBitRate;
    }

    bool     CANDriver::isEnabled(void) const {
        return mEnabled;
    }

    /* Setters */
    oscoErrorCode_t CANDriver::setBitRate(const uint16_t &pBitRate) {
        mBitRate = pBitRate;

        return OSCO_ERROR_NONE;
    }

    oscoErrorCode_t CANDriver::enable(void) {
        mEnabled = true;

        return OSCO_ERROR_NONE;
    }

    oscoErrorCode_t CANDriver::disable(void) {
        mEnabled = false;

        return OSCO_ERROR_NONE;
    }

    /* Send CAN message */
    oscoErrorCode_t CANDriver::send(const uint32_t &pMsgID,
                const uint8_t &pSize,
                const uint8_t * const pData,
                const uint32_t &pFlags)
    {
        if(!mInitialized) {
            std::cerr << "[ERROR] OSCO <CANDriver::send> Driver is not initialized !" << std::endl;
            return OSCO_ERROR_NOT_INIT;
        }

        if(!mEnabled) {
            std::cerr << "[ERROR] OSCO <CANDriver::send> Driver is not enabled !" << std::endl;
            return OSCO_ERROR_STOPPED;
        }

        if(nullptr == pData) {
            std::cerr << "[ERROR] OSCO <CANDriver::send> Driver is not enabled !" << std::endl;
            return OSCO_ERROR_ARG;
        }

        canMessage_t lMsg = {
            .id = pMsgID,
            .size = pSize,
            .flags = pFlags
        };
        memcpy(lMsg.data, pData, pSize);

        cipErrorCode_t lCIPError = CAN_IP_ERROR_UNKNOWN;

        lCIPError = CIP_send(mID, &lMsg);
        if(CAN_IP_ERROR_NONE != lCIPError) {
            std::cerr << "[ERROR] OSCO <CANDriver::send> CIP_send failed !" << std::endl;
            return OSCO_ERROR_DRIVER;
        }

        return OSCO_ERROR_NONE;
    }
}
