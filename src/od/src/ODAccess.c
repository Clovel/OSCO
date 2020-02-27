/*
 * @brief OD Getters and setters
 * 
 * @file ODAccess.c
 */

/* Includes -------------------------------------------- */
/* OSCO OD module */
#include "OSCOOD.h"

/* OSCO public includes */
#include "OSCOTypes.h"
#include "OSCOErrorCodes.h"
#include "OSCOPrint.h"
#include "OSCO.h"

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */

/* External variable declarations ---------------------- */
extern OSCOODElement_t gOD[];

/* OD pointer getters ---------------------------------- */
static oscoErrorCode_t getObjPtr(const uint8_t pID,
    const uint16_t pIdx,
    const uint8_t pSubIdx,
    void **pOut)
{
    (void)pID;

    for(uint8_t i = 0U; i < OD_OBJECT_COUNT; i++) {
        if((pIdx == gOD[i].idx) && (pSubIdx == gOD[i].subIdx)) {
            /* We found our object */
            
            switch(gOD[i].access) {
                case OD_ACCESS_TYPE_RO:
                case OD_ACCESS_TYPE_RW:
                    /* We can read this object */
                    *pOut = gOD[i].ptr;
                    return OSCO_ERROR_NONE;
                default:
                    /* We can't read this object */
                    eprintf("[ERROR] OSCO <getObjPtr> 0x%04X:0x%02X : Access denied !\n", pIdx, pSubIdx);
                    *pOut = NULL;
                    return OSCO_ERROR_OD_ACCESS_DENIED;
            }
        }
    }

    eprintf("[ERROR] OSCO <getObjPtr> 0x%04X:0x%02X : Object not found !\n", pIdx, pSubIdx);
    pOut = NULL;

    return OSCO_ERROR_OD_NOT_FOUND;
}

/* OD Getters ------------------------------------------ */
oscoErrorCode_t OSCOODGetU8(const uint8_t pID,
    const uint16_t pIdx,
    const uint8_t pSubIdx,
    uint8_t * const pOut)
{
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOODGetU8> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    void *lObjectPtr = NULL;

    /* Get the pointer to the objects data */
    oscoErrorCode_t lErrorCode = getObjPtr(pID, pIdx, pSubIdx, &lObjectPtr);
    switch(lErrorCode) {
        case OSCO_ERROR_NONE:
            /* We found the object, and we can read it */
            if(NULL == lObjectPtr) {
                /* We shouldn't be in this case, something went wrong */
                eprintf("[ERROR] OSCO <OSCOODGetU8> 0x%04X:0x%02X : getObjPtr returned a NULL pointer !\n", pIdx, pSubIdx);
                return OSCO_ERROR_OD;
            }
            *pOut = *(uint8_t *)lObjectPtr;
            return OSCO_ERROR_NONE;
        case OSCO_ERROR_OD_ACCESS_DENIED:
            eprintf("[ERROR] OSCO <OSCOODGetU8> 0x%04X:0x%02X : Access denied !\n", pIdx, pSubIdx);
            return lErrorCode;
        case OSCO_ERROR_OD_NOT_FOUND:
            eprintf("[ERROR] OSCO <OSCOODGetU8> 0x%04X:0x%02X : Object not found !\n", pIdx, pSubIdx);
            return lErrorCode;
        default:
            /* We shouldn't be here, something went wrong */
            eprintf("[ERROR] OSCO <OSCOODGetU8> 0x%04X:0x%02X : Unknown error from getObjPtr (%u) !\n", pIdx, pSubIdx, lErrorCode);
            return OSCO_ERROR_UNKNOWN; /* TODO : Find better return code */
    }

    eprintf("[ERROR] OSCO <OSCOODGetU8> 0x%04X:0x%02X : Object not found !\n", pIdx, pSubIdx);

    return OSCO_ERROR_OD_NOT_FOUND;
}

oscoErrorCode_t OSCOODGetU16(const uint8_t pID,
    const uint16_t pIdx,
    const uint8_t pSubIdx,
    uint16_t * const pOut)
{
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOODGetU16> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    void *lObjectPtr = NULL;

    /* Get the pointer to the objects data */
    oscoErrorCode_t lErrorCode = getObjPtr(pID, pIdx, pSubIdx, &lObjectPtr);
    switch(lErrorCode) {
        case OSCO_ERROR_NONE:
            /* We found the object, and we can read it */
            if(NULL == lObjectPtr) {
                /* We shouldn't be in this case, something went wrong */
                eprintf("[ERROR] OSCO <OSCOODGetU16> 0x%04X:0x%02X : getObjPtr returned a NULL pointer !\n", pIdx, pSubIdx);
                return OSCO_ERROR_OD;
            }
            *pOut = *(uint16_t *)lObjectPtr;
            return OSCO_ERROR_NONE;
        case OSCO_ERROR_OD_ACCESS_DENIED:
            eprintf("[ERROR] OSCO <OSCOODGetU16> 0x%04X:0x%02X : Access denied !\n", pIdx, pSubIdx);
            return lErrorCode;
        case OSCO_ERROR_OD_NOT_FOUND:
            eprintf("[ERROR] OSCO <OSCOODGetU16> 0x%04X:0x%02X : Object not found !\n", pIdx, pSubIdx);
            return lErrorCode;
        default:
            /* We shouldn't be here, something went wrong */
            eprintf("[ERROR] OSCO <OSCOODGetU16> 0x%04X:0x%02X : Unknown error from getObjPtr (%u) !\n", pIdx, pSubIdx, lErrorCode);
            return OSCO_ERROR_UNKNOWN; /* TODO : Find better return code */
    }

    eprintf("[ERROR] OSCO <OSCOODGetU16> 0x%04X:0x%02X : Object not found !\n", pIdx, pSubIdx);

    return OSCO_ERROR_OD_NOT_FOUND;
}

oscoErrorCode_t OSCOODGetU32(const uint8_t pID,
    const uint16_t pIdx,
    const uint8_t pSubIdx,
    uint32_t * const pOut)
{
    if(NULL == pOut) {
        eprintf("[ERROR] OSCO <OSCOODGetU32> Output ptr is NULL !\n");
        return OSCO_ERROR_ARG;
    }

    void *lObjectPtr = NULL;

    /* Get the pointer to the objects data */
    oscoErrorCode_t lErrorCode = getObjPtr(pID, pIdx, pSubIdx, &lObjectPtr);
    switch(lErrorCode) {
        case OSCO_ERROR_NONE:
            /* We found the object, and we can read it */
            if(NULL == lObjectPtr) {
                /* We shouldn't be in this case, something went wrong */
                eprintf("[ERROR] OSCO <OSCOODGetU32> 0x%04X:0x%02X : getObjPtr returned a NULL pointer !\n", pIdx, pSubIdx);
                return OSCO_ERROR_OD;
            }
            *pOut = *(uint32_t *)lObjectPtr;
            return OSCO_ERROR_NONE;
        case OSCO_ERROR_OD_ACCESS_DENIED:
            eprintf("[ERROR] OSCO <OSCOODGetU32> 0x%04X:0x%02X : Access denied !\n", pIdx, pSubIdx);
            return lErrorCode;
        case OSCO_ERROR_OD_NOT_FOUND:
            eprintf("[ERROR] OSCO <OSCOODGetU32> 0x%04X:0x%02X : Object not found !\n", pIdx, pSubIdx);
            return lErrorCode;
        default:
            /* We shouldn't be here, something went wrong */
            eprintf("[ERROR] OSCO <OSCOODGetU32> 0x%04X:0x%02X : Unknown error from getObjPtr (%u) !\n", pIdx, pSubIdx, lErrorCode);
            return OSCO_ERROR_UNKNOWN; /* TODO : Find better return code */
    }

    eprintf("[ERROR] OSCO <OSCOODGetU32> 0x%04X:0x%02X : Object not found !\n", pIdx, pSubIdx);

    return OSCO_ERROR_OD_NOT_FOUND;
}
