/**
 * @brief OSCO basic example
 * 
 * @file main.cpp
 */

/* Includes -------------------------------------------- */
#include "OSCO.h"

#include <iostream>

/* Defines --------------------------------------------- */
#define OSCO_ID 0U

/* Notes ----------------------------------------------- */

/* Variable declaration -------------------------------- */

/* Type definitions ------------------------------------ */

/* Support functions ----------------------------------- */

/* ----------------------------------------------------- */
/* Main ------------------------------------------------ */
/* ----------------------------------------------------- */
int main(const int argc, const char * const * const argv) {
    (void)argc;
    (void)argv;

    unsigned int lErrorCode = 0U;

    /* Initialize the CAN over IP module */
    if(OSCO_ERROR_NONE != (lErrorCode = OSCOInit(OSCO_ID))) {
        std::cout << "[ERROR] OSCOInit failed w/ error code " << lErrorCode << std::endl;
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
