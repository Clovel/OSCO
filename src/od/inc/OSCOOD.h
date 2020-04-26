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
typedef enum _odDataTypes {
    OD_UNKNOWN_TYPE                 = 0U,
    OD_BASIC_TYPE_BOOLEAN           = 0x0001U,
    OD_BASIC_TYPE_INTEGER8          = 0x0002U,
    OD_BASIC_TYPE_INTEGER16         = 0x0003U,
    OD_BASIC_TYPE_INTEGER24         = 0x0010U,
    OD_BASIC_TYPE_INTEGER32         = 0x0004U,
    OD_BASIC_TYPE_INTEGER40         = 0x0012U,
    OD_BASIC_TYPE_INTEGER48         = 0x0013U,
    OD_BASIC_TYPE_INTEGER56         = 0x0014U,
    OD_BASIC_TYPE_INTEGER64         = 0x0015U,
    OD_BASIC_TYPE_UNSIGNED8         = 0x0005U,
    OD_BASIC_TYPE_UNSIGNED16        = 0x0006U,
    OD_BASIC_TYPE_UNSIGNED24        = 0x0016U,
    OD_BASIC_TYPE_UNSIGNED32        = 0x0007U,
    OD_BASIC_TYPE_UNSIGNED40        = 0x0018U,
    OD_BASIC_TYPE_UNSIGNED48        = 0x0019U,
    OD_BASIC_TYPE_UNSIGNED56        = 0x001AU,
    OD_BASIC_TYPE_UNSIGNED64        = 0x001BU,
    OD_BASIC_TYPE_REAL32            = 0x0008U,
    OD_BASIC_TYPE_REAL64            = 0x0011U,
    OD_BASIC_TYPE_OCTET_STRING      = 0x000AU,
    OD_BASIC_TYPE_VISIBLE_STRING    = 0x0009U,
    OD_BASIC_TYPE_UNICODE_STRING    = 0x000BU,
    OD_BASIC_TYPE_TIME_OF_DAY       = 0x000CU,
    OD_BASIC_TYPE_DOMAIN            = 0x000FU,
    OD_COMPLEX_TYPE_PDOCOMMPARAM    = 0x0020U,
    OD_COMPLEX_TYPE_PDOMAPPING      = 0x0021U,
    OD_COMPLEX_TYPE_SDOPARAM        = 0x0022U,
    OD_COMPLEX_TYPE_IDENTITY,
    OD_COMPLEX_TYPE_DEBUGGERPARAM,
    OD_COMPLEX_TYPE_CMDPARAM,
    OD_BASIC_TYPE_VOID,
} OSCOODDataType_t;

typedef enum _odObjectTypes {
    OD_OBJ_TYPE_UNKNOWN = 0U,
    /* TODO : Get OD_OBJ_TYPE_NULL value */
    OD_OBJ_TYPE_NULL,           /**< No data fields */
    /* TODO : Get OD_OBJ_TYPE_DOMAIN value */
    OD_OBJ_TYPE_DOMAIN,         /**< A large amount of data */
    /* TODO : Get OD_OBJ_TYPE_DEFTYPE value */
    OD_OBJ_TYPE_DEFTYPE,        /**< Defines a standard data type */
    /* TODO : Get OD_OBJ_TYPE_DEFSTRUCT value */
    OD_OBJ_TYPE_DEFSTRUCT,      /**< Defines a complex data type */
    OD_OBJ_TYPE_VAR = 0x7U,     /**< A single value */
    OD_OBJ_TYPE_ARRAY = 0x8U,   /**< An entry with more than one Subindex, with each Subindex (except 0x00) having the same data type */
    OD_OBJ_TYPE_RECORD = 0x9U,  /**< An entry with more than one Subindex, with each Subindex (except 0x00) having differing data type */
} OSCOODObjectType_t;

typedef enum _odAccessTypes {
    OD_ACCESS_TYPE_UNKNOWN = 0U,
    OD_ACCESS_TYPE_RO,      /**< read only */
    OD_ACCESS_TYPE_WO,      /**< write only */
    OD_ACCESS_TYPE_RW,      /**< read/write */
    OD_ACCESS_TYPE_CONST,   /**< constant value */
    OD_ACCESS_TYPE_RWW,     /**< read/write on process input */
    OD_ACCESS_TYPE_RWR      /**< read/write on process output */
} OSCOODAccessType_t;

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

/**
 * @brief Attempt at a OD structure definition
 * 
 * TODO : WIP
 */
typedef struct _odElmt {
    uint16_t            idx;
    uint8_t             subIdx;
    OSCOODDataType_t    type;
    OSCOODAccessType_t  access;
    void               *ptr;
    const void         *defaultValuePtr;
    const void         *maxValPtr;
    const void         *minValPtr;
} OSCOODElement_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_OD_PRIVATE_H */
