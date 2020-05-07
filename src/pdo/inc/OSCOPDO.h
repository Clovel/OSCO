/**
 * @brief OSCO PDO header
 * 
 * @file OSCOPDO.h
 */

#ifndef OSCO_PDO_H
#define OSCO_PDO_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */

/* OSCO PDO public functions --------------------- */
/* Initialization */
oscoErrorCode_t OSCOPDOInit(void);

/* Getters */

/* Process */
oscoErrorCode_t OSCOPDOProcess(void);

#endif /* OSCO_PDO_H */
