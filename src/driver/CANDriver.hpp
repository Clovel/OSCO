/**
 * @brief Interface between the CO stack and the CAN Driver
 * 
 * @file CANDriver.hpp
 */

#ifndef OSCO_DRIVER_CANDRIVER_HPP
#define OSCO_DRIVER_CANDRIVER_HPP

/* Includes -------------------------------------------- */
#include "OSCOErrorCodes.hpp"

#include <stdint.h>  /* TODO : Delete this and use custom types */

/* Defines --------------------------------------------- */
#define CAN_MESSAGE_MAX_SIZE 8U

/* Type definitions ------------------------------------ */
typedef struct _canMessage {
    uint32_t id;
    uint8_t size;
    uint8_t data[CAN_MESSAGE_MAX_SIZE];
    uint8_t flags;
} canMessage_t;

namespace osco::driver {
/* Driver class definition ----------------------------- */
    class CANDriver {
        public:
            /* Constructor */
            CANDriver(const uint8_t &pID);

            /* Destructor */
            virtual ~CANDriver();

            /* Initialization */
            oscoErrorCode_t init(const uint16_t pBitRate);

            /* Re-initialization */
            oscoErrorCode_t reinit(const uint16_t pBitRate);

            /* Getters */
            uint8_t  id(void) const;
            uint16_t bitRate(void) const;
            bool     isInitialized(void) const;
            bool     isEnabled(void) const;

            /* Setters */
            oscoErrorCode_t setBitRate(const uint16_t &pBitRate);
            oscoErrorCode_t enable(void);
            oscoErrorCode_t disable(void);

            /* Send CAN message */
            oscoErrorCode_t send(const uint32_t);

        private:
            uint8_t mID;
            bool    mInitialized;
            bool    mEnabled;

            uint16_t mBitRate;
    }
}

#endif /* OSCO_DRIVER_CANDRIVER_HPP */
