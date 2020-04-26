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
/**
 * @brief The CAN frame structure type
 */
typedef struct _oscoCANMessage {
    uint32_t id;
    uint8_t  size;
    uint8_t  data[CAN_MESSAGE_MAX_SIZE];
    uint32_t flags;
} OSCOCANMessage_t;

/* Object Dictionary types */
typedef uint8_t * visibleStr_t;
typedef uint8_t * octetStr_t;
typedef uint8_t * domain_t;

/* CAN Driver function types */
typedef uint16_t (*OSCOCANDriverInitFct_t)(const uint8_t);
typedef uint16_t (*OSCOCANDriverResetFct_t)(const uint8_t);
typedef uint16_t (*OSCOCANDriverDisableFct_t)(const uint8_t);
typedef uint16_t (*OSCOCANDriverSetPutClbkFct_t)(const uint8_t, const uint8_t, int (*)(const uint8_t, const uint32_t, const uint8_t, const uint8_t * const, const uint32_t));
typedef uint16_t (*OSCOCANDriverSendFct_t)(const uint8_t, const uint32_t, const uint8_t, const uint8_t * const, const uint32_t);
typedef uint16_t (*OSCOCANDriverRecvFct_t)(const uint8_t, uint32_t * const, uint8_t * const, uint8_t * const, uint32_t * const);
typedef uint16_t (*OSCOCANDriverRxThreadStartFct_t)(const uint8_t);

typedef struct _CanDriverCallbacks {
    OSCOCANDriverInitFct_t          driverInit;
    OSCOCANDriverResetFct_t         driverReset;
    OSCOCANDriverDisableFct_t       driverDisable;
    OSCOCANDriverSetPutClbkFct_t    driverSetPutClbk;
    OSCOCANDriverSendFct_t          driverSend;
    OSCOCANDriverRecvFct_t          driverRecv;
    OSCOCANDriverRxThreadStartFct_t driverRxThreadStart;
} OSCOCANDriverCallbacks_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_TYPES_H */
