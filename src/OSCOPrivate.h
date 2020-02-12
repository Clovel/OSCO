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
    uint8_t canDriverID;
} oscoInstance_t;

#endif /* OSCO_PRIVATE_H */
