/**
 * @brief OSCO PDO process implementation
 * 
 * @file PDOProcess.c
 */

/* Includes -------------------------------------------- */
#include "PDOPrivate.h"
#include "OSCOPDO.h"

/* OSCO public headers */
#include "OSCO.h"
#include "OSCOPrint.h"
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
extern oscoPDOInstance_t pdoModule;

/* Helper functions ------------------------------------ */

/* PDO process ----------------------------------------- */
oscoErrorCode_t OSCOPDOProcess(void) {
    if(!pdoModule.initialized) {
        eprintf("[ERROR] OSCO <OSCOPDOProcess> Service is not initialized !\n");
        return OSCO_ERROR_NOT_INIT;
    }

    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    /* Set/Check the T/RPDO settings in case they changed 
     * TODO : Check if they changed before changing.
     * 
     * This is useful in the case where a SDO write occured
     * on this node's T/RPDO entries, thus changing the settings.
     */
    lErrorCode = RPDOCheckODSettings();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOPDOProcess> Failed to set/check RPDO settings\n");
        return lErrorCode;
    }
    lErrorCode = TPDOCheckODSettings();
    if(OSCO_ERROR_NONE != lErrorCode) {
        eprintf("[ERROR] OSCO <OSCOPDOProcess> Failed to set/check TPDO settings\n");
        return lErrorCode;
    }

    /* TODO */

    return lErrorCode;
}
