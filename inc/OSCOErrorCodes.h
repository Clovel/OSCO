/**
 * @brief OSCO error codes
 * 
 * @file OSCOErrorCodes.h
 */

#ifndef OSCO_ERRORCODES_H
#define OSCO_ERRORCODES_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes -------------------------------------------- */

/* Defines --------------------------------------------- */

/* Type definitions ------------------------------------ */
typedef enum _oscoErrorCodes {
    OSCO_ERROR_UNKNOWN      = 0U,
    OSCO_ERROR_NONE         = 1,
    OSCO_ERROR_ARG          = 2,
    OSCO_ERROR_SYS          = 3,
    OSCO_ERROR_NET          = 4,
    OSCO_ERROR_ALREADY_INIT = 5,
    OSCO_ERROR_NOT_INIT     = 6,
    OSCO_ERROR_STOPPED      = 7,
    OSCO_ERROR_DRIVER       = 8,
    OSCO_ERROR_WARN         = 9,
    OSCO_ERROR_MODULE       = 10
} oscoErrorCode_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_ERRORCODES_H */
