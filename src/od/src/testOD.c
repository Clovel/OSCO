/*
 * @brief Test OD
 * 
 * @file testOD.c
 */

/* Includes -------------------------------------------- */
/* OSCO OD module */
#include "OSCOOD.h"
#include "testOD.h"

/* OSCO public includes */
#include "OSCOConfigDefines.h"
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Default value declarations -------------------------- */
extern const uint8_t  defValU8[];
extern const uint16_t defValU16[];
extern const uint32_t defValU32[];
extern const uint64_t defValU64[];

/* Object value declarations --------------------------- */
extern const uint8_t  objValU8[];
extern const uint16_t objValU16[];
extern const uint32_t objValU32[];
extern const uint64_t objValU64[];

/* Max value declarations ------------------------------ */
extern const uint8_t  maxValU8[];
extern const uint16_t maxValU16[];
extern const uint32_t maxValU32[];
extern const uint64_t maxValU64[];

/* Min value declarations ------------------------------ */
extern const uint8_t  minValU8[];
extern const uint16_t minValU16[];
extern const uint32_t minValU32[];
extern const uint64_t minValU64[];

/* CANOpen Object Dictionary declaration --------------- */
OSCOODElement_t gOD[OD_OBJECT_COUNT] = {
    /* Device Type */
    {
        0x1000U,
        0x00U,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RO,
        (objValU32 + 0U),
        (defValU32 + 0U),
        NULL,
        NULL
    },
    /* Error Register */
    {
        0x1001U,
        0x00U,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RO,
        (objValU32 + 1U),
        NULL,
        NULL,
        NULL
    },
    /* SYNC COB OD */
    {
        0x1005U,
        0x00,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (objValU32 + 2U),
        (defValU32 + 1U),
        NULL,
        NULL
    },
    /* Communication Cycle Period */
    {
        0x1006U,
        0x00,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (objValU32 + 3U),
        (defValU32 + 2U),
        NULL,
        NULL
    }
};
