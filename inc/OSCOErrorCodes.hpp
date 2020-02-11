/**
 * @brief OSCO error codes
 * 
 * @file OSCOErrorCodes.hpp
 */

#ifndef OSCO_ERRORCODES_HPP
#define OSCO_ERRORCODES_HPP

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
    OSCO_ERROR_DRIVER       = 8
} oscoErrorCode_t;

#endif /* OSCO_ERRORCODES_HPP */
