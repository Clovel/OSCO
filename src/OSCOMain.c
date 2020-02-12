/*
 * @brief Main OSCO implementation file
 * 
 * @file CANDriver.c
 */

/* Includes -------------------------------------------- */
/* OSCO Driver */
#include "OSCOCANDriver.h"

/* OSCO public includes */
#include "OSCOTypes.h"
#include "OSCOPrint.h"
#include "OSCOConfigDefines.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */

/* OSCO Main functions --------------------------------- */

/**
 * @brief This is a placeholder function
 */
void placeHolder(void){
    /* Nothing to do, this is a placeholder */
    oscoErrorCode_t lResult = OSCOCANDriverInit(0U, 1000000U);
    (void)lResult;
}
