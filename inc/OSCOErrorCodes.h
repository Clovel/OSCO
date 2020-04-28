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
    OSCO_ERROR_UNKNOWN = 0U,
    OSCO_ERROR_NONE,
    OSCO_ERROR_ARG,
    OSCO_ERROR_CONFIG,
    OSCO_ERROR_SYS,
    OSCO_ERROR_NET,
    OSCO_ERROR_ALREADY_INIT,
    OSCO_ERROR_NOT_INIT,
    OSCO_ERROR_STOPPED,
    OSCO_ERROR_DRIVER,
    OSCO_ERROR_WARN,
    OSCO_ERROR_MODULE,
    OSCO_ERROR_OD,
    OSCO_ERROR_OD_NOT_FOUND,
    OSCO_ERROR_OD_ACCESS_DENIED,
} oscoErrorCode_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_ERRORCODES_H */
