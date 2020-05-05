/**
 * @brief OSCO Heartbeat header
 * 
 * @file OSCOHeartbeat.h
 */

#ifndef OSCO_HEARTBEAT_H
#define OSCO_HEARTBEAT_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Variable declarations ------------------------------- */

/* OSCO Heartbeat public functions --------------------- */
/* Initialization */
oscoErrorCode_t OSCOHBInit(void);

/* Getters */
bool OSCOHBIsProducer(void);
uint32_t OSCOHBGetPeriod(void);

/* Process */
oscoErrorCode_t OSCOHBProcess(void);

#endif /* OSCO_HEARTBEAT_H */
