/**
 * @brief OSCO basic example
 * 
 * @file main.cpp
 */

/* Includes -------------------------------------------- */
/* OSCO stack */
#include "OSCO.h"

/* CAN Driver wrapper */
#include "CANDriverWrapper.h"

/* TimerThread */
#include "TimerThread.hxx"

/* C++ system */
#include <iostream>

/* C system */
#include <unistd.h>

/* Defines --------------------------------------------- */
#define NODE_ID 0x05U

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

    /* Link the OSCO stack w/ the CAN Driver */
    const OSCOCANDriverCallbacks_t lDriverFcts = {
        init          : initCANDriver,
        reset         : resetCANDriver,
        disable       : disableCANDriver,
        send          : sendCANMsg,
        recv          : recvCANMsg,
        rxThreadStart : startCANDriverRxThread,
        msgAvail      : CANMsgAvail,
        isRxThreadOn  : startCANDriverIsRxThreadOn,
    };

    if(OSCO_ERROR_NONE != OSCOSetCANDriverFunctionSet(lDriverFcts)) {
        std::cerr << "[ERROR] OSCOSetCANDriverFunctionSet failed w/ error code " << lErrorCode << std::endl;
        exit(EXIT_FAILURE);
    }

    /* Initialize the OSCO stack */
    if(OSCO_ERROR_NONE != (lErrorCode = OSCOInit(true))) {
        std::cerr << "[ERROR] OSCOInit failed w/ error code " << lErrorCode << std::endl;
        exit(EXIT_FAILURE);
    }

    if(OSCO_ERROR_NONE != OSCOSetNodeID(NODE_ID)) {
        std::cerr << "[ERROR] OSCOSetNodeID failed w/ error code " << lErrorCode << std::endl;
        exit(EXIT_FAILURE);
    }

    if(OSCO_ERROR_NONE != setPutMsgClbk()) {
        std::cerr << "[ERROR] setPutMsgClbk failed w/ error code " << lErrorCode << std::endl;
        exit(EXIT_FAILURE);
    }

    if(OSCO_ERROR_NONE != OSCOCANDriverEnable()) {
        std::cerr << "[ERROR]  OSCOCANDriverEnable failed with error code " << lErrorCode << std::endl;
        return OSCO_ERROR_DRIVER;
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

    uint8_t i = 0U;
    while(true) {
        /* Call the CANOpen stack main process routine */
        lErrorCode = OSCOProcess();
        if(OSCO_ERROR_NONE != lErrorCode) {
            std::cerr << "[DEBUG] OSCOProcess failed !" << std::endl;
            return EXIT_FAILURE;
        }

        if(0U == i) {
            lErrorCode = OSCORequestState(OSCO_STATE_PREOP);
            if(OSCO_ERROR_NONE != lErrorCode) {
                std::cerr << "[DEBUG] OSCORequestState PREOP failed !" << std::endl;
                return EXIT_FAILURE;
            }

            ++i;
        }

        if(2U == i) {
            lErrorCode = OSCORequestState(OSCO_STATE_OP);
            if(OSCO_ERROR_NONE != lErrorCode) {
                std::cerr << "[DEBUG] OSCORequestState OP failed !" << std::endl;
                return EXIT_FAILURE;
            }

            ++i;
        }

        if(1U == i) ++i;

        usleep(250U);
    }

    return EXIT_SUCCESS;
}
