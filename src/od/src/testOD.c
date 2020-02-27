/*
 * @brief Test OD
 * 
 * @file testOD.c
 */

/* Includes -------------------------------------------- */
/* OSCO OD module */
#include "OSCOOD.h"

/* OSCO public includes */
#include "OSCOConfigDefines.h"
#include "OSCOTypes.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* Default value declarations -------------------------- */
extern const uint8_t defValU8[];
extern const uint8_t defValU16[];
extern const uint8_t defValU32[];
extern const uint8_t defValU64[];

/* Object value declarations --------------------------- */
extern const uint8_t objValU8[];
extern const uint8_t objValU16[];
extern const uint8_t objValU32[];
extern const uint8_t objValU64[];

/* Max value declarations ------------------------------ */
extern const uint8_t maxValU8[];
extern const uint8_t maxValU16[];
extern const uint8_t maxValU32[];
extern const uint8_t maxValU64[];

/* Min value declarations ------------------------------ */
extern const uint8_t minValU8[];
extern const uint8_t minValU16[];
extern const uint8_t minValU32[];
extern const uint8_t minValU64[];

/* CANOpen Object Dictionary declaration --------------- */
OSCOODElement_t gOD[] = {
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
    }
};
