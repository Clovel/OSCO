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
#include "OSCO.h"
#include "OSCOPrint.h"
#include "OSCOTypes.h"
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
oscoErrorCode_t OSCOCANDriverInit(const bool pThreadedRx) {
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

    gCANDriver.isThreadedRx = pThreadedRx;

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

oscoErrorCode_t OSCOCANDriverIsThreadedRx(bool * const pOut) {
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOCANDriverIsThreadedRx> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    *pOut = gCANDriver.isThreadedRx;

    return OSCO_ERROR_NONE;
}

/* Setters */
oscoErrorCode_t OSCOCANDriverEnable() {
    if(gCANDriver.isThreadedRx) {
        oscoErrorCode_t lResult = gCANDriver.driverFunctions.rxThreadStart();
        if(OSCO_ERROR_NONE != lResult) {
            eprintf("[ERROR] OSCO <OSCOCANDriverEnable> driverRxThreadStart failed !\n");
            return OSCO_ERROR_DRIVER;
        }
    } /* TODO : else */

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

/* Process */
oscoErrorCode_t OSCOCANDriverProcess(void) {
    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    /* Check the recv function pointer */
    if(NULL == gCANDriver.driverFunctions.msgAvail) {
        printf("[ERROR] OSCO <OSCOCANDriverProcess> Driver msgAvail function ptr is NULL\n");
        return OSCO_ERROR_CONFIG;
    }
    if(NULL == gCANDriver.driverFunctions.recv) {
        printf("[ERROR] OSCO <OSCOCANDriverProcess> Driver recv function ptr is NULL\n");
        return OSCO_ERROR_CONFIG;
    }

    /* If threaded, check if the thread is up.
     * If not, attempt to bring it back up.
     */
    if(gCANDriver.isThreadedRx) {
        /* Check thread related driver functions */
        if(NULL == gCANDriver.driverFunctions.isRxThreadOn) {
            printf("[ERROR] OSCO <OSCOCANDriverProcess> Driver isRxThreadOn function ptr is NULL\n");
            return OSCO_ERROR_CONFIG;
        }
        if(NULL == gCANDriver.driverFunctions.rxThreadStart) {
            printf("[ERROR] OSCO <OSCOCANDriverProcess> Driver rxThreadStart function ptr is NULL\n");
            return OSCO_ERROR_CONFIG;
        }

        bool lIsThreadOn = true;
        if(OSCO_ERROR_NONE != gCANDriver.driverFunctions.isRxThreadOn(&lIsThreadOn)) {
            printf("[ERROR] OSCO <OSCOCANDriverProcess> Driver isRxThreadOn failed\n");
            return OSCO_ERROR_DRIVER;
        }

        if(!lIsThreadOn) {
            if(OSCO_ERROR_NONE != gCANDriver.driverFunctions.rxThreadStart()) {
                printf("[ERROR] OSCO <OSCOCANDriverProcess> Failed to start driver reception thread\n");
                return OSCO_ERROR_DRIVER;
            }
        } else {
            /* Driver reception thread is running, nothing to do */
        }
    } else {
        /* Non-threaded reception process required */

        /* Check if message is available */
        bool lMsgAvail = true;
        while(lMsgAvail) {
            lErrorCode = gCANDriver.driverFunctions.msgAvail(&lMsgAvail);
            if(OSCO_ERROR_NONE != lErrorCode) {
                printf("[ERROR] OSCO <OSCOCANDriverProcess> msgAvail failed\n");
                return OSCO_ERROR_DRIVER;
            }

            if(lMsgAvail) {
                /* Message available */

                /* Create message structure */
                OSCOCANMessage_t lMsg;
                memset(&lMsg, 0U, sizeof(OSCOCANMessage_t));

                /* Read message */
                lErrorCode = gCANDriver.driverFunctions.recv(&lMsg.id, &lMsg.size, lMsg.data, &lMsg.flags);
                if(OSCO_ERROR_NONE != lErrorCode) {
                    printf("[ERROR] OSCO <OSCOCANDriverProcess> recv failed\n");
                    return OSCO_ERROR_DRIVER;
                }

                /* Insert the message in the Rx queue */
                int lResult = OSCORxMgrInputMessage(lMsg.id, lMsg.size, lMsg.data, lMsg.flags);
                if(0 != lResult) {
                    printf("[ERROR] OSCO <OSCOCANDriverProcess> OSCORxMgrInputMessage failed\n");
                    return OSCO_ERROR_MODULE;
                }
            } else break;
        }
    }

    return lErrorCode;
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
