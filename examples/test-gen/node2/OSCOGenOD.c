/*
 * @brief Generated OD
 * 
 * @file OSCOGenOD.c
 */

/* Includes -------------------------------------------- */
/* OSCO OD module */
#include "OSCOOD.h"
#include "OSCOGenOD.h"

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
        0x1000,
        0x00,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU32 + 0),
        (void *)(defValU32 + 0),
        NULL,
        NULL,
    },
    /* Error Register */
    {
        0x1001,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU8 + 0),
        (void *)(defValU8 + 0),
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x1016,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 1),
        (void *)(defValU8 + 1),
        NULL,
        NULL,
    },
    /* Consumer Heartbeat Time 1 */
    {
        0x1016,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 1),
        (void *)(defValU32 + 1),
        NULL,
        NULL,
    },
    /* Producer Heartbeat Time */
    {
        0x1017,
        0x00,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 0),
        (void *)(defValU16 + 0),
        NULL,
        NULL,
    },
    /* Number of entries */
    {
        0x1018,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU8 + 2),
        (void *)(defValU8 + 2),
        NULL,
        NULL,
    },
    /* Vendor Id */
    {
        0x1018,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU32 + 2),
        (void *)(defValU32 + 2),
        NULL,
        NULL,
    },
    /* Product Code */
    {
        0x1018,
        0x02,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU32 + 3),
        (void *)(defValU32 + 3),
        NULL,
        NULL,
    },
    /* Revision number */
    {
        0x1018,
        0x03,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU32 + 4),
        (void *)(defValU32 + 4),
        NULL,
        NULL,
    },
    /* Serial number */
    {
        0x1018,
        0x04,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU32 + 5),
        NULL,
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x1200,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 3),
        (void *)(defValU8 + 3),
        NULL,
        NULL,
    },
    /* COB-ID client to server */
    {
        0x1200,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 6),
        (void *)(defValU32 + 5),
        NULL,
        NULL,
    },
    /* COB-ID server to client */
    {
        0x1200,
        0x02,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU32 + 7),
        (void *)(defValU32 + 6),
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x1280,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 4),
        (void *)(defValU8 + 4),
        NULL,
        NULL,
    },
    /* COB-ID client -> server */
    {
        0x1280,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 8),
        (void *)(defValU32 + 7),
        NULL,
        NULL,
    },
    /* COB-ID server -> client */
    {
        0x1280,
        0x02,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 9),
        (void *)(defValU32 + 8),
        NULL,
        NULL,
    },
    /* Node-ID of the SDO server */
    {
        0x1280,
        0x03,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 5),
        NULL,
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x1400,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 6),
        (void *)(defValU8 + 5),
        NULL,
        NULL,
    },
    /* COB-ID used by RPDO */
    {
        0x1400,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 10),
        (void *)(defValU32 + 9),
        NULL,
        NULL,
    },
    /* Transmission type */
    {
        0x1400,
        0x02,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 7),
        (void *)(defValU8 + 6),
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1400,
        0x03,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 1),
        NULL,
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1400,
        0x04,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 8),
        NULL,
        NULL,
        NULL,
    },
    /* Event timer */
    {
        0x1400,
        0x05,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 2),
        NULL,
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x1401,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 9),
        (void *)(defValU8 + 7),
        NULL,
        NULL,
    },
    /* COB-ID used by RPDO */
    {
        0x1401,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 11),
        (void *)(defValU32 + 10),
        NULL,
        NULL,
    },
    /* Transmission type */
    {
        0x1401,
        0x02,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 10),
        (void *)(defValU8 + 8),
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1401,
        0x03,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 3),
        NULL,
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1401,
        0x04,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 11),
        NULL,
        NULL,
        NULL,
    },
    /* Event timer */
    {
        0x1401,
        0x05,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 4),
        NULL,
        NULL,
        NULL,
    },
    /* Number of mapped application objects in PDO */
    {
        0x1600,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 12),
        (void *)(defValU8 + 9),
        NULL,
        NULL,
    },
    /* Mapping Entry 1 */
    {
        0x1600,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 12),
        (void *)(defValU32 + 11),
        NULL,
        NULL,
    },
    /* Number of mapped application objects in PDO */
    {
        0x1601,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 13),
        (void *)(defValU8 + 10),
        NULL,
        NULL,
    },
    /* Mapping Entry 1 */
    {
        0x1601,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 13),
        (void *)(defValU32 + 12),
        NULL,
        NULL,
    },
    /* Mapping Entry 2 */
    {
        0x1601,
        0x02,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 14),
        (void *)(defValU32 + 13),
        NULL,
        NULL,
    },
    /* Mapping Entry 3 */
    {
        0x1601,
        0x03,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 15),
        (void *)(defValU32 + 14),
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x1800,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 14),
        (void *)(defValU8 + 11),
        NULL,
        NULL,
    },
    /* COB-ID used by TPDO */
    {
        0x1800,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 16),
        (void *)(defValU32 + 15),
        NULL,
        NULL,
    },
    /* Transmission type */
    {
        0x1800,
        0x02,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 15),
        (void *)(defValU8 + 12),
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1800,
        0x03,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 5),
        NULL,
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1800,
        0x04,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 16),
        NULL,
        NULL,
        NULL,
    },
    /* Event timer */
    {
        0x1800,
        0x05,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 6),
        NULL,
        NULL,
        NULL,
    },
    /* SYNC start value */
    {
        0x1800,
        0x06,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 17),
        NULL,
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x1801,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 18),
        (void *)(defValU8 + 13),
        NULL,
        NULL,
    },
    /* COB-ID used by TPDO */
    {
        0x1801,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 17),
        (void *)(defValU32 + 16),
        NULL,
        NULL,
    },
    /* Transmission type */
    {
        0x1801,
        0x02,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 19),
        (void *)(defValU8 + 14),
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1801,
        0x03,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 7),
        NULL,
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1801,
        0x04,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 20),
        NULL,
        NULL,
        NULL,
    },
    /* Event timer */
    {
        0x1801,
        0x05,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 8),
        NULL,
        NULL,
        NULL,
    },
    /* SYNC start value */
    {
        0x1801,
        0x06,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 21),
        NULL,
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x1802,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 22),
        (void *)(defValU8 + 15),
        NULL,
        NULL,
    },
    /* COB-ID used by TPDO */
    {
        0x1802,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 18),
        (void *)(defValU32 + 17),
        NULL,
        NULL,
    },
    /* Transmission type */
    {
        0x1802,
        0x02,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 23),
        (void *)(defValU8 + 16),
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1802,
        0x03,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 9),
        NULL,
        NULL,
        NULL,
    },
    /* Inhibit time */
    {
        0x1802,
        0x04,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 24),
        NULL,
        NULL,
        NULL,
    },
    /* Event timer */
    {
        0x1802,
        0x05,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 10),
        NULL,
        NULL,
        NULL,
    },
    /* SYNC start value */
    {
        0x1802,
        0x06,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 25),
        NULL,
        NULL,
        NULL,
    },
    /* Number of mapped application objects in TPDO */
    {
        0x1A00,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 26),
        (void *)(defValU8 + 17),
        NULL,
        NULL,
    },
    /* Mapping Entry 1 */
    {
        0x1A00,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 19),
        (void *)(defValU32 + 18),
        NULL,
        NULL,
    },
    /* Mapping Entry 2 */
    {
        0x1A00,
        0x02,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 20),
        (void *)(defValU32 + 19),
        NULL,
        NULL,
    },
    /* Mapping Entry 3 */
    {
        0x1A00,
        0x03,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 21),
        (void *)(defValU32 + 20),
        NULL,
        NULL,
    },
    /* Number of mapped application objects in TPDO */
    {
        0x1A01,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 27),
        (void *)(defValU8 + 18),
        NULL,
        NULL,
    },
    /* Application object */
    {
        0x1A01,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 22),
        NULL,
        NULL,
        NULL,
    },
    /* Number of mapped application objects in TPDO */
    {
        0x1A02,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU8 + 28),
        (void *)(defValU8 + 19),
        NULL,
        NULL,
    },
    /* Application object */
    {
        0x1A02,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 23),
        NULL,
        NULL,
        NULL,
    },
    /* Application object 2 */
    {
        0x1A02,
        0x02,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 24),
        NULL,
        NULL,
        NULL,
    },
    /* Application object 3 */
    {
        0x1A02,
        0x03,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValU32 + 25),
        NULL,
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x2000,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU8 + 29),
        (void *)(defValU8 + 20),
        NULL,
        NULL,
    },
    /* CPU load */
    {
        0x2000,
        0x01,
        OD_BASIC_TYPE_REAL32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValReal32 + 0),
        NULL,
        NULL,
        NULL,
    },
    /* Available Memory */
    {
        0x2000,
        0x02,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 11),
        NULL,
        NULL,
        NULL,
    },
    /* Used Memory */
    {
        0x2000,
        0x03,
        OD_BASIC_TYPE_UNSIGNED16,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU16 + 12),
        NULL,
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x2010,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU8 + 30),
        (void *)(defValU8 + 21),
        NULL,
        NULL,
    },
    /* Slave counter */
    {
        0x2010,
        0x01,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 26),
        NULL,
        NULL,
        NULL,
    },
    /* Master counter */
    {
        0x2010,
        0x02,
        OD_BASIC_TYPE_UNSIGNED32,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU32 + 27),
        NULL,
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x2020,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU8 + 31),
        (void *)(defValU8 + 22),
        NULL,
        NULL,
    },
    /* LED 1 control */
    {
        0x2020,
        0x01,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 32),
        NULL,
        NULL,
        NULL,
    },
    /* LED 2 control */
    {
        0x2020,
        0x02,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 33),
        NULL,
        NULL,
        NULL,
    },
    /* LED 3 control */
    {
        0x2020,
        0x03,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 34),
        NULL,
        NULL,
        NULL,
    },
    /* Highest sub-index supported */
    {
        0x2021,
        0x00,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RO,
        (void *)(objValU8 + 35),
        (void *)(defValU8 + 23),
        NULL,
        NULL,
    },
    /* LED 1 status */
    {
        0x2021,
        0x01,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 36),
        NULL,
        NULL,
        NULL,
    },
    /* LED 2 status */
    {
        0x2021,
        0x02,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 37),
        NULL,
        NULL,
        NULL,
    },
    /* LED 3 status */
    {
        0x2021,
        0x03,
        OD_BASIC_TYPE_UNSIGNED8,
        OD_ACCESS_TYPE_RW,
        (void *)(objValU8 + 38),
        NULL,
        NULL,
        NULL,
    },
    /* OSCO-test */
    {
        0x2100,
        0x00,
        OD_BASIC_TYPE_VISIBLE_STRING,
        OD_ACCESS_TYPE_CONST,
        (void *)(objValVisStr + 0),
        (void *)(defValVisStr + 0),
        @@OBJECT_MAX_VAL_PTR@@,
        @@OBJECT_MIN_VAL_PTR@@,
    },

};
