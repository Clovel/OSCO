/**
 * @brief OSCO basic example
 * 
 * @file main.cpp
 */

/* Includes -------------------------------------------- */
#include "OSCO.h"

#include "TimerThread.hxx"

#include <iostream>

#include <unistd.h>

/* Defines --------------------------------------------- */
#define OSCO_ID 0U

/* Notes ----------------------------------------------- */

/* Variable declaration -------------------------------- */

/* Type definitions ------------------------------------ */

/* Support functions ----------------------------------- */
void printMessageShort(const OSCOCANMessage_t * const pMsg) {
    printf("0x%03X [%u] ", pMsg->id, pMsg->size);
    for(uint8_t i = 0U; (i < pMsg->size) && (i < 8U); i++) {
        printf("%02X ", pMsg->data[i]);
    }
    printf("0x%08X\n", pMsg->flags);
}

/* ----------------------------------------------------- */
/* Main ------------------------------------------------ */
/* ----------------------------------------------------- */
int main(const int argc, const char * const * const argv) {
    (void)argc;
    (void)argv;

    unsigned int lErrorCode = 0U;

    /* Initialize the CAN over IP module */
    if(OSCO_ERROR_NONE != (lErrorCode = OSCOInit(OSCO_ID))) {
        std::cerr << "[ERROR] OSCOInit failed w/ error code " << lErrorCode << std::endl;
        exit(EXIT_FAILURE);
    }

    /* Initialize TimerThread */
    TimerThread *timerThread = new TimerThread;

    timerThread->addTimer(0U, OSCO_CLOCK_RESOLUTION,
                            [](){
        //std::cout << "[DEBUG] <TimerThread> Ticking !" << std::endl << std::flush;
        unsigned int llErrorCode = OSCOClockTick();
        if(OSCO_ERROR_NONE != llErrorCode) {
            std::cerr << "[DEBUG] <TimerThread> OSCOClockTick failed !" << std::endl << std::flush;
        }
    });

    while(true) {
        /* Call the CANOpen stack main process routine */
        lErrorCode = OSCOProcess(OSCO_ID);
        if(OSCO_ERROR_NONE != lErrorCode) {
            std::cerr << "[DEBUG] OSCOProcess failed !" << std::endl;
            return EXIT_FAILURE;
        }

        usleep(250U);
    }

    return EXIT_SUCCESS;
}
