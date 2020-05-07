/**
 * @brief OSCO TPDO implementation
 * 
 * @file TPDO.c
 */

/* Includes -------------------------------------------- */
#include "OSCOPDO.h"
#include "PDOPrivate.h"

/* OSCO public headers */
#include "OSCO.h"
#include "OSCOTypes.h"
#include "OSCOPrint.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */
extern oscoPDOInstance_t pdoModule;

/* Helper functions ------------------------------------ */

/* TPDO functions -------------------------------------- */
oscoErrorCode_t TPDOCheckODSettings(void) {
    oscoErrorCode_t lErrorCode = OSCO_ERROR_NONE;

    /* TODO */

    return lErrorCode;
}

oscoErrorCode_t OSCOTriggerTPDOs(void) {
    /* TODO */
}
