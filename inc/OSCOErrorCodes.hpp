/**
 * @brief OSCO error codes
 * 
 * @file OSCOErrorCodes.h
 */

#ifndef CAN_IP_ERROR_CODES_H
#define CAN_IP_ERROR_CODES_H

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
        OSCO_ERROR_STOPPED      = 7
    } oscoErrorCode_t;

#endif /* CAN_IP_ERROR_CODES_H */
