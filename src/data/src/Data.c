/**
 * @brief OSCO data implementation
 * 
 * @file Data.c
 */

/* Includes -------------------------------------------- */
#include "OSCOData.h"
#include "DataPrivate.h"

/* OSCO public headers */
#include "OSCOTypes.h"
#include "OSCOPrint.h"

/* Generated OD */
#include "OSCOGenNodeID.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
/* Need to init this statically to use as "extern" in other files */
oscoStateMachineInstance_t data = {
    OSCO_NODE_ID
};

/* Getters */
uint8_t OSCOGetNodeID(void) {
    return data.nodeID;
}

/* Setters */
oscoErrorCode_t OSCOSetNodeID(const uint8_t pNodeID) {
    if((1U > pNodeID) || (127U < pNodeID)) {
        eprintf("[ERROR] OSCO <OSCODataSetNodeID> Node ID out of bounds (%u)\n", (uint16_t)pNodeID);
        return OSCO_ERROR_ARG;
    }

    data.nodeID = pNodeID;

    return OSCO_ERROR_NONE;
}
