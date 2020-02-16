/*
 * @brief OSCI custom public types
 * 
 * @file OSCOTypes.h
 */

#ifndef OSCO_TYPES_H
#define OSCO_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes -------------------------------------------- */
#include "OSCOErrorCodes.h"

#include <stdint.h>   /* TODO : Delete this and use custom types */
#include <stdbool.h>  /* TODO : Delete this and use custom types */

/* Defines --------------------------------------------- */
#define NULL (void *)0U

#define CAN_MESSAGE_MAX_SIZE 8U

/* Type definitions ------------------------------------ */
typedef struct _oscoCANMessage {
    uint32_t id;
    uint8_t  size;
    uint8_t  data[CAN_MESSAGE_MAX_SIZE];
    uint32_t flags;
} OSCOCANMessage_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_TYPES_H */
