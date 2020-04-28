/*
 * @brief Reception manager interface
 * 
 * @file OSCORxMgr.h
 */

#ifndef OSCO_RXMGR_H
#define OSCO_RXMGR_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"
#include "OSCOErrorCodes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* OSCO Reception manager functions -------------------- */
/**
 * @brief Reception manager initialization
 * 
 * @return Error code
 */
oscoErrorCode_t OSCORxMgrInit(void);

/**
 * @brief Reception manager process
 * 
 * @return Error code
 */
oscoErrorCode_t OSCORxMgrProcess(void);


#endif /* OSCO_RXMGR_H */
