/**
 * @brief CAN over IP main test file
 * 
 * @file main.c
 */

/* Includes -------------------------------------------- */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Defines --------------------------------------------- */

/* Notes ----------------------------------------------- */

/* Variable declaration -------------------------------- */

/* Type definitions ------------------------------------ */

/* Support functions ----------------------------------- */
static void print_usage(const char * const pProgName)
{
    printf("[USAGE] %s test#\n", pProgName);
    printf("        Test -1 : default/no test\n");
}

/* ----------------------------------------------------- */
/* Main tests ------------------------------------------ */
/* ----------------------------------------------------- */
int main(const int argc, const char * const * const argv) {
    /* Test function initialization */
    int32_t lTestNum;
    int16_t lResult = 0;

    if ((argc < 2) || (strcmp(argv[1], "--help") == 0)) {
        print_usage(argv[0]);
        return -1;
    }

    lTestNum = strtol(argv[1], NULL, 10);

    printf("[TEST ] Executing test #%d\n", lTestNum);

    /* Executing test */
    switch (lTestNum) {
        default:
            (void)lResult;
            printf("[INFO ] test #%d not available", lTestNum);
            fflush(stdout);
            break;
    }

    return EXIT_SUCCESS;
}