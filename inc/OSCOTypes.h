/*
 * @brief OSCO custom public types
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
typedef oscoErrorCode_t (*OSCOCANDriverInitFct_t)(void);
typedef oscoErrorCode_t (*OSCOCANDriverResetFct_t)(void);
typedef oscoErrorCode_t (*OSCOCANDriverDisableFct_t)(void);
typedef oscoErrorCode_t (*OSCOCANDriverSendFct_t)(const uint32_t, const uint8_t, const uint8_t * const, const uint32_t);
typedef oscoErrorCode_t (*OSCOCANDriverRecvFct_t)(uint32_t * const, uint8_t * const, uint8_t * const, uint32_t * const);
typedef oscoErrorCode_t (*OSCOCANDriverRxThreadStartFct_t)(void);
typedef oscoErrorCode_t (*OSCOCANDriverMsgAvailable_t)(bool * const);
typedef oscoErrorCode_t (*OSCOCANDriverIsRxThreadOn_t)(bool * const);

typedef struct _CanDriverCallbacks {
    OSCOCANDriverInitFct_t          init;
    OSCOCANDriverResetFct_t         reset;
    OSCOCANDriverDisableFct_t       disable;
    OSCOCANDriverSendFct_t          send;
    OSCOCANDriverRecvFct_t          recv;
    OSCOCANDriverRxThreadStartFct_t rxThreadStart;
    OSCOCANDriverMsgAvailable_t     msgAvail;
    OSCOCANDriverIsRxThreadOn_t     isRxThreadOn;
} OSCOCANDriverCallbacks_t;

typedef enum _canopenStates {
    OSCO_STATE_UNKNOWN = 0U,
    OSCO_STATE_POWER_ON_RESET,
    OSCO_STATE_INIT,
    OSCO_STATE_PREOP,
    OSCO_STATE_OP,
    OSCO_STATE_STOPPED,
    OSCO_STATE_RESET_COMM,
    OSCO_STATE_RESET_NODE
} oscoState_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_TYPES_H */
