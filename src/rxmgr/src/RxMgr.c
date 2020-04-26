/*
 * @brief Reception manager implementation
 * 
 * @file OSCORxMgr.c
 */

/* Includes -------------------------------------------- */
/* OSCO Module includes */
#include "OSCORxMgr.h"
/* OSCO Module private includes */
#include "RxMgrPrivate.h"

/* OSCO public includes */
#include "OSCOPrint.h"
#include "OSCOTypes.h"
#include "OSCOConfigDefines.h"

/* Defines --------------------------------------------- */
#ifndef OSCO_LOCK_RXMGR
#define OSCO_LOCK_RXMGR()
#endif /* OSCO_LOCK_RXMGR */

#ifndef OSCO_UNLOCK_RXMGR
#define OSCO_UNLOCK_RXMGR()
#endif /* OSCO_UNLOCK_RXMGR */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
oscoRxMgrInstance_t gRxMgr;

/**
 * @brief Defines the state of the FIFO
 */
typedef enum _fifoState {
    FIFO_OK = 0U,   /**< FIFO is neither full nor empty */
    FIFO_FULL,      /**< FIFO is full */
    FIFO_EMPTY,     /**< FIFO is empty */
} fifoState_t;

/* OSCO Reception manager functions -------------------- */
static fifoState_t getFifoState(void) {
    /* Check if the FIFO is full */
    if(gRxMgr.rIdx == gRxMgr.wIdx) {
        /* Either empty or full */
        if(gRxMgr.rIdxWrapAround != gRxMgr.wIdxWrapAround) {
            /* The FIFO is full, return error */
            return FIFO_FULL;
        } else {
            /* The fifo is empty */
            return FIFO_EMPTY;
        }
    } else {
        /* The FIFO is not empty nor full */
        return FIFO_OK;
    }
}

static oscoErrorCode_t getMsgFromFifo(OSCOCANMessage_t * const pMsg) {
    if(!gRxMgr.initialized) {
        eprintf("[ERROR] OSCO <getMsgFromFifo> Service is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    if(NULL == pMsg) {
        eprintf("[ERROR] OSCO <getMsgFromFifo> Output pointer parameter is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    /* Copy a message from the FIFO into our message */
    OSCO_LOCK_RXMGR();

    pMsg->id    = (gRxMgr.fifo + gRxMgr.rIdx)->id;
    pMsg->size  = (gRxMgr.fifo + gRxMgr.rIdx)->size;
    pMsg->flags = (gRxMgr.fifo + gRxMgr.rIdx)->flags;

    for(uint8_t i = 0U; (i < pMsg->size) && (i < CAN_MESSAGE_MAX_SIZE); i++) {
        pMsg->data[i] = (gRxMgr.fifo + gRxMgr.rIdx)->data[i];
    }

    /* Increment the read index of the FIFO */
    gRxMgr.rIdx++;
    if(OSCO_RX_FIFO_SIZE <= gRxMgr.rIdx) {
        gRxMgr.rIdx = 0U;
        gRxMgr.rIdxWrapAround = !gRxMgr.rIdxWrapAround;
    }

    OSCO_UNLOCK_RXMGR();

    return OSCO_ERROR_NONE;
}

int OSCORxMgrInputMessage(const uint32_t pCOBID,
    const uint8_t pSize,
    const uint8_t * const pData,
    const uint32_t pFlags)
{
    if(!gRxMgr.initialized) {
        eprintf("[ERROR] OSCO <OSCORxMgrInputMessage> Service is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    OSCO_LOCK_RXMGR();

    if(FIFO_FULL == getFifoState()) {
        eprintf("[ERROR] OSCO <OSCORxMgrInputMessage> Rx FIFO is full !\n");
        return 1;
    }

    /* Copy the CAN Message */
    (gRxMgr.fifo + gRxMgr.wIdx)->id    = pCOBID;
    (gRxMgr.fifo + gRxMgr.wIdx)->size  = pSize;
    (gRxMgr.fifo + gRxMgr.wIdx)->flags = pFlags;

    for(uint8_t i = 0U; (i < pSize) && (i < CAN_MESSAGE_MAX_SIZE); i++) {
        (gRxMgr.fifo + gRxMgr.wIdx)->data[i] = pData[i];
    }

    /* Increment the write index of the FIFO */
    gRxMgr.wIdx++;
    if(OSCO_RX_FIFO_SIZE <= gRxMgr.wIdx) {
        gRxMgr.wIdx = 0U;
        gRxMgr.wIdxWrapAround = !gRxMgr.wIdxWrapAround;
    }

    OSCO_UNLOCK_RXMGR();

    return 0; /* TODO : error checking */
}

oscoErrorCode_t OSCORxMgrInit(void) {
    if(gRxMgr.initialized) {
        eprintf("[ERROR] OSCO <OSCORxMgrInit> Service is already initialized !\n");
        return OSCO_ERROR_ALREADY_INIT;
    }

    gRxMgr.initialized = true;

    /* TODO : Zero out the FIFO buffers */

    return OSCO_ERROR_NONE;
}

oscoErrorCode_t OSCORxMgrProcess(void) {
    if(!gRxMgr.initialized) {
        eprintf("[ERROR] OSCO <OSCORxMgrProcess> Service is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    /* Check if new messages are available */
    if(FIFO_EMPTY == getFifoState()) {
        /* No new messages, return w/o any error */
        return OSCO_ERROR_NONE;
    }

    /* Get a message from the FIFO */
    OSCOCANMessage_t lMsg;
    if(OSCO_ERROR_NONE != getMsgFromFifo(&lMsg)) {
        eprintf("[ERROR] OSCO <OSCORxMgrProcess> OSCORxMgrGetMsgFromFifo failed !\n");
        return OSCO_ERROR_MODULE;
    }

    /* TODO : Switch case on the COB-ID */
#ifdef CAN_PRINT_SHORT
    CAN_PRINT_SHORT(&lMsg);
#endif /* CAN_PRINT_SHORT */

    return OSCO_ERROR_NONE;
}
