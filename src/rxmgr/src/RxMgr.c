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

/* OSCO Reception manager functions -------------------- */
int OSCORxMgrInputMessage(const uint8_t pID, 
    const uint32_t pCOBID,
    const uint8_t pSize,
    const uint8_t * const pData,
    const uint32_t pFlags)
{
    OSCO_LOCK_RXMGR();

    /* Copy the CAN Message */
    (gRxMgr.fifo + gRxMgr.wIdx)->id    = pID;
    (gRxMgr.fifo + gRxMgr.wIdx)->size  = pSize;
    (gRxMgr.fifo + gRxMgr.wIdx)->flags = pFlags;

    for(uint8_t i = 0U; (i < pSize) && (i < CAN_MESSAGE_MAX_SIZE); i++) {
        (gRxMgr.fifo + gRxMgr.wIdx)->data[i] = pData[i];
    }

    /* Increment the write index */
    gRxMgr.wIdx++;
    if(OSCO_RX_FIFO_SIZE <= gRxMgr.wIdx) {
        gRxMgr.wIdx = 0U;
        gRxMgr.wIdxWrapAround++;
    }

    OSCO_UNLOCK_RXMGR();

    return 0; /* TODO : error checking */
}

oscoErrorCode_t OSCORxMgrProcess(const uint8_t pID) {
    //
}
