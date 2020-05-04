/**
 * @brief OSCO boot-up message transmission
 * 
 * @file TransmitBootUpMsg.c
 */

/* Includes -------------------------------------------- */
#include "OSCOStateMachine.h"
#include "StateMachinePrivate.h"

/* CAN driver */
#include "OSCOCANDriver.h"

/* OSCO Node ID */
#include "OSCOGenNodeID.h"

/* OSCO public headers */
#include "OSCOPrint.h"
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
static OSCOCANMessage_t sBootUpMsg = {
    id: 0x000U,
    size: 1U,
    data: {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U},
    flags: 0U
};

/* TransmitBootUpMsg function -------------------------- */
oscoErrorCode_t transmitBootUpMsg(void) {
    sBootUpMsg.id = 0x700 + OSCO_NODE_ID; /* TODO : Use variable */

    oscoErrorCode_t lErrorCode = OSCOCANDriverSend(sBootUpMsg.id, sBootUpMsg.size, sBootUpMsg.data, sBootUpMsg.flags);
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <transmitBootUpMsg> OSCOCANDriverSend failed\n");
        return lErrorCode;
    }

    /* TODO : Move this to the HB/NG module or NMT */

    return OSCO_ERROR_NONE;
}
