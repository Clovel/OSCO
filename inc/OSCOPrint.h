/*
 * @brief Header defining the print methods for OSCO
 * 
 * @file OSCOPrint.h
 */

#ifndef OSCO_PRINT_H
#define OSCO_PRINT_H

/* Includes -------------------------------------------- */
#include <stdio.h>

/* Defines --------------------------------------------- */
#ifndef _WIN32
#define eprintf(...) fprintf (stderr, ##__VA_ARGS__)
//under GCC
#else /* _WIN32 */
#define eprintf(...) fprintf (stderr, ##__VA_ARGS__)
//under MSVC
#endif /* _WIN32 */

#endif /* OSCO_PRINT_H */
