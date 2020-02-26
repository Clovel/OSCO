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
#include <stddef.h>   /* TODO : Delete this and use custom types */

/* Defines --------------------------------------------- */
#ifndef NULL
#define NULL (void *)0U
#endif /* NULL */

#define CAN_MESSAGE_MAX_SIZE 8U

/* Type definitions ------------------------------------ */
typedef struct _oscoCANMessage {
    uint32_t id;
    uint8_t  size;
    uint8_t  data[CAN_MESSAGE_MAX_SIZE];
    uint32_t flags;
} OSCOCANMessage_t;

typedef uint8_t * visibleStr_t;
typedef uint8_t * octetStr_t;
typedef uint8_t * domain_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_TYPES_H */
