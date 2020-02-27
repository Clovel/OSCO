/*
 * @brief ODPrivate header
 * 
 * @file OSPrivate.h
 */

#ifndef OSCO_OD_PRIVATE_H
#define OSCO_OD_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes -------------------------------------------- */
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */
/* Baic type indexes */
#define OD_BASIC_TYPE_BOOLEAN_IDX       0x0001U

/* Baic uint type indexes */
#define OD_BASIC_TYPE_UNSIGNED8_IDX     0x0005U
#define OD_BASIC_TYPE_UNSIGNED16_IDX    0x0006U
#define OD_BASIC_TYPE_UNSIGNED32_IDX    0x000CU

/* Special uint types indexes */
#define OD_BASIC_TYPE_UNSIGNED24_IDX    0x0016U
#define OD_BASIC_TYPE_UNSIGNED40_IDX    0x0018U
#define OD_BASIC_TYPE_UNSIGNED48_IDX    0x0019U
#define OD_BASIC_TYPE_UNSIGNED56_IDX    0x001AU
#define OD_BASIC_TYPE_UNSIGNED64_IDX    0x001BU

/* Baic sint type indexes */
#define OD_BASIC_TYPE_INTEGER8_IDX      0x0002U
#define OD_BASIC_TYPE_INTEGER16_IDX     0x0003U
#define OD_BASIC_TYPE_INTEGER32_IDX     0x0004U

/* Special sint types indexes */
#define OD_BASIC_TYPE_INTEGER24_IDX     0x0010U
#define OD_BASIC_TYPE_INTEGER40_IDX     0x0012U
#define OD_BASIC_TYPE_INTEGER48_IDX     0x0013U
#define OD_BASIC_TYPE_INTEGER56_IDX     0x0014U
#define OD_BASIC_TYPE_INTEGER64_IDX     0x0015U

/* Baic floating point type indexes */
#define OD_BASIC_TYPE_REAL32_IDX        0x0008U
#define OD_BASIC_TYPE_REAL64_IDX        0x0011U

/* Extended types indexes */
#define OD_BASIC_TYPE_OCTET_STRING_IDX      0x000AU
#define OD_BASIC_TYPE_VISIBLE_STRING_IDX    0x0009U
#define OD_BASIC_TYPE_UNICODE_STRING_IDX    0x000BU
#define OD_BASIC_TYPE_TIME_OF_DAY_IDX       0x000CU
#define OD_BASIC_TYPE_DOMAIN_IDX            0x000FU

/* Complex datat types indexes */
#define OD_COMPLEX_TYPE_PDOCOMMPARAM_IDX    0x0020U
#define OD_COMPLEX_TYPE_SDOPARAM_IDX        0x0022U
#define OD_COMPLEX_TYPE_IDENTITY_IDX        0x0023U
#define OD_COMPLEX_TYPE_DEBUGGERPARAM_IDX   0x0024U
#define OD_COMPLEX_TYPE_CMDPARAM_IDX        0x0025U

/* Type definitions ------------------------------------ */
typedef enum _odTypes {
    OD_UNKNOWN_TYPE = 0U,
    OD_BASIC_TYPE_VOID,
    OD_BASIC_TYPE_BOOLEAN,
    OD_BASIC_TYPE_UNSIGNED8,
    OD_BASIC_TYPE_UNSIGNED16,
    OD_BASIC_TYPE_UNSIGNED24,
    OD_BASIC_TYPE_UNSIGNED32,
    OD_BASIC_TYPE_UNSIGNED40,
    OD_BASIC_TYPE_UNSIGNED48,
    OD_BASIC_TYPE_UNSIGNED56,
    OD_BASIC_TYPE_UNSIGNED64,
    OD_BASIC_TYPE_INTEGER8,
    OD_BASIC_TYPE_INTEGER16,
    OD_BASIC_TYPE_INTEGER24,
    OD_BASIC_TYPE_INTEGER32,
    OD_BASIC_TYPE_INTEGER40,
    OD_BASIC_TYPE_INTEGER48,
    OD_BASIC_TYPE_INTEGER56,
    OD_BASIC_TYPE_INTEGER64,
    OD_BASIC_TYPE_REAL32,
    OD_BASIC_TYPE_REAL64,
    OD_BASIC_TYPE_OCTET_STRING,
    OD_BASIC_TYPE_VISIBLE_STRING,
    OD_BASIC_TYPE_UNICODE_STRING,
    OD_BASIC_TYPE_TIME_OF_DAY,
    OD_BASIC_TYPE_DOMAIN,
    OD_COMPLEX_TYPE_PDOCOMMPARAM,
    OD_COMPLEX_TYPE_SDOPARAM,
    OD_COMPLEX_TYPE_IDENTITY,
    OD_COMPLEX_TYPE_DEBUGGERPARAM,
    OD_COMPLEX_TYPE_CMDPARAM
} OSCOODElmtType_t;

typedef struct _timeOfDay {
    uint32_t ms;    /* 4 last bits are reserved */
    uint16_t days;
} OSCOODTimeOfDay_t;

typedef struct _odTimeDiff {
    uint32_t ms;    /* 4 last bits are reserved */
    uint16_t days;
} OSCOODTimeDiff_t;

typedef struct _odPDOCommParamRecord {
    uint8_t  nbEntries;
    uint32_t cobID;
    uint8_t  transType;
    uint16_t inhibitTime;
    uint8_t  reserved;
    uint16_t eventTimer;
} OSCOPDOCommParamRecord_t;

typedef struct _odSDOParamRecord {
    uint8_t  nbEntries;
    uint32_t clientToServerCobID;
    uint32_t serverToClientCobID;
    uint8_t  nodeID;
} OSCOSDOParamRecord_t;

typedef struct _odIdentity {
    uint8_t  nbEntries;
    uint32_t vendorID;
    uint32_t pn;    /**< Product code/number */
    uint32_t rn;    /**< Revision number */
    uint32_t sn;    /**< Serial number */
} OSCOIdentity_t;

typedef struct _odDebuggerParamRecord {
    uint8_t     nbEntries;
    octetStr_t  cmd;
    uint8_t     status;
    octetStr_t  reply;
} OSCODebuggerParamRecord_t;

typedef struct _odCmdParamRecord {
    uint8_t     nbEntries;
    octetStr_t  cmd;
    uint8_t     status;
    octetStr_t  reply;
} OSCOCmdParamRecord_t;

typedef enum _odAccessTypes {
    OD_ACCESS_TYPE_UNKNOWN = 0U,
    OD_ACCESS_TYPE_RO,
    OD_ACCESS_TYPE_WO,
    OD_ACCESS_TYPE_RW
} OSCOODAccessType_t;

/**
 * @brief Attempt at a OD structure definition
 * 
 * TODO : WIP
 */
typedef struct _od {
    uint16_t            idx;
    uint8_t             subIdx;
    OSCOODElmtType_t    type;
    OSCOODAccessType_t  access;
    void               *ptr;
    void               *defaultValuePtr;
    void               *maxValPtr;
    void               *minValPtr;
} OSCOOD_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_OD_PRIVATE_H */
