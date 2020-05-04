/*
 * @brief Private definition of the OSCO stack's
 * internal variables. 
 * 
 * @file OSCOPrivate.h
 */

#ifndef OSCO_PRIVATE_H
#define OSCO_PRIVATE_H

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
typedef struct _oscoPrivateVars {
    bool initialized;       /**< Flag indicating if the stack is initialized */
    uint8_t canDriverID;    /**< ID of the CAN driver used. Also the CAN line identifier */
} oscoInstance_t;

#endif /* OSCO_PRIVATE_H */
