/**
 * @brief OSCO Heartbeat implementation
 * 
 * @file Heartbeat.c
 */

/* Includes -------------------------------------------- */
#include "OSCOHeartbeat.h"
#include "HeartbeatPrivate.h"

/* Clock */
#include "OSCOClock.h"

/* State machine */
#include "OSCOStateMachine.h"

/* CAN Driver */
#include "OSCOCANDriver.h"

/* OSCO public headers */
#include "OSCO.h"
#include "OSCOTypes.h"
#include "OSCOPrint.h"

/* Defines --------------------------------------------- */
#define HB_BASE_COB_ID 0x700U

#define HB_PRODUCER_TIME_IDX 0x1017U
#define HB_PRODUCER_TIME_SUBIDX 0x00U

/* Type definitions ------------------------------------ */
typedef enum _stateCodes {
    HB_STATE_UNKNOWN = 0xFFU,
    HB_STATE_BOOT_UP = 0x00U,
    HB_STATE_STOPPED = 0x04U,
    HB_STATE_OP      = 0x05U,
    HB_STATE_PREOP   = 0x7FU
} HBStateCode_t;

/* Variable declarations ------------------------------- */
/* Need to init this statically to use as "extern" in other files */
oscoHeartbeatInstance_t hbModule = {
    false,
    0U,
    0U,
    NULL,
    NULL
};

/* Helper functions ------------------------------------ */
static oscoErrorCode_t hbCheckODSettings(void) {
    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    /* Check if the Producer entry is here */
    lErrorCode = OSCOODGetU32(HB_PRODUCER_TIME_IDX, HB_PRODUCER_TIME_SUBIDX, &hbModule.period);
    if(OSCO_ERROR_OD_NOT_FOUND == lErrorCode) {
        hbModule.period   = 0U;
    } else if (OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <syncCheckODSettings> Failed to get the SYNC COB-ID object\n");
        return lErrorCode;
    }

    hbModule.period *= 1000U; /* Convert ms into us */

    hbModule.producer = 0 < hbModule.period ? true : false;

    /* TODO : Check consumer settings */

    return lErrorCode;
}

/* Message sending */
static oscoErrorCode_t sendHB(const uint8_t pStateCode) {
    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    /* Build CAN message */
    OSCOCANMessage_t lMsg = {
        HB_BASE_COB_ID + OSCOGetNodeID(),
        1U,
        {pStateCode, 0U, 0U, 0U, 0U, 0U, 0U, 0U},
        0U
    };

    /* Send the message */
    lErrorCode = OSCOCANDriverSend(lMsg.id, lMsg.size, lMsg.data, lMsg.flags);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <sendHB> OSCOCANDriverSend failed !\n");
        return OSCO_ERROR_DRIVER;
    }

    return lErrorCode;
}

/* Heartbeat module functions -------------------------- */

/* Initialization */
oscoErrorCode_t OSCOHBInit(void) {
    if(hbModule.initialized) {
        eprintf("[ERROR] OSCO <OSCOHBInit> Service is already initialized !\n");
        return OSCO_ERROR_ALREADY_INIT;
    }

    hbModule.period   = 0U;
    hbModule.producer = false;
    hbModule.rxInd    = NULL;
    hbModule.txInd    = NULL;

    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    /* Set/Check the HB settings */
    lErrorCode = hbCheckODSettings();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOHBInit> Failed to set/check HB settings\n");
        hbModule.initialized = false;
        return lErrorCode;
    }

    hbModule.initialized = true;

    return lErrorCode;
}

/* Getters */
bool OSCOHBIsProducer(void) {
    return hbModule.producer;
}

uint32_t OSCOHBGetPeriod(void) {
    return hbModule.producer ? hbModule.period : 0U;
}

/* Indication setters */
oscoErrorCode_t OSCOHBSetRxIndFunction(OSCOHBRxInd_t pIndFct) {
    if(NULL == pIndFct) {
        eprintf("[ERROR] OSCO <OSCOHBSetRxIndFunction> Argument ptr to function is NULL\n");
        return OSCO_ERROR_ARG;
    }

    hbModule.rxInd = pIndFct;

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCOHBSetTxIndFunction(OSCOHBTxInd_t pIndFct) {
    if(NULL == pIndFct) {
        eprintf("[ERROR] OSCO <OSCOHBSetTxIndFunction> Argument ptr to function is NULL\n");
        return OSCO_ERROR_ARG;
    }

    hbModule.txInd = pIndFct;

    return OSCO_ERROR_NONE;
}

/* Process */
oscoErrorCode_t OSCOHBProcess(void) {
    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;
    static uint64_t lNewTicks = 0UL, lOldTicks = 0UL;

    if(!hbModule.initialized) {
        eprintf("[ERROR] OSCO <OSCOHBProcess> Service is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    /* Set/Check the HB settings in case they changed 
     * TODO : Check if they changed before changing.
     * 
     * This is useful in the case where a SDO write occured
     * on this node's HB entries, thus changing the settings.
     */
    lErrorCode = hbCheckODSettings();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOHBProcess> Failed to set/check SYNC settings\n");
        return lErrorCode;
    }

    /* Send HB if this node is a producer and the period isn't 0 */
    if((hbModule.producer) && (0U != hbModule.period)) {
        /* Get ticks to see if it is time to send a SYNC message */
        lErrorCode = OSCOClockGetTicks(&lNewTicks);
        if(OSCO_ERROR_NONE != lErrorCode) {
            eprintf("[ERROR] OSCO <OSCOHBProcess> OSCOClockGetTicks failed !\n");
            return OSCO_ERROR_MODULE;
        }

        if(hbModule.period <= lNewTicks - lOldTicks) {
            /* Get current NMT state */
            oscoState_t lCurrentState = OSCO_STATE_UNKNOWN;
            lErrorCode = OSCOGetCurrentState(&lCurrentState);
            if(OSCO_ERROR_NONE != lErrorCode) {
                eprintf("[ERROR] OSCO <OSCOHBProcess> OSCOGetCurrentState failed\n");
                return OSCO_ERROR_MODULE;
            }

            HBStateCode_t lStateCode = HB_STATE_UNKNOWN;
            switch(lCurrentState) {
                case OSCO_STATE_STOPPED:
                    lStateCode = HB_STATE_STOPPED;
                    break;
                case OSCO_STATE_PREOP:
                    lStateCode = HB_STATE_PREOP;
                    break;
                case OSCO_STATE_OP:
                    lStateCode = HB_STATE_OP;
                    break;
                default:
                    /* We wont be sending out a HB message in this case */
                    break;
            }

            if(HB_STATE_UNKNOWN != lStateCode) {
                /* Send out the HB message */
                lErrorCode = sendHB(lStateCode);
                if(OSCO_ERROR_NONE != lErrorCode) {
                    eprintf("[ERROR] OSCO <OSCOHBProcess> Failed to send the HB message\n");
                    return lErrorCode;
                }
            }

            /* Save the new time of HB emission */
            lOldTicks = lNewTicks;
        }
    }

    return lErrorCode;
}
