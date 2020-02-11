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
        mBitRate = pBitRate;

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
    oscoErrorCode_t CANDriver::send(const uint32_t) {
        /* TODO */

        return OSCO_ERROR_NONE;
    }
}
