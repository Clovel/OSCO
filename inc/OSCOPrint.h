/*
 * @brief Header defining the print methods for OSCO
 * 
 * @file OSCOPrint.h
 */

#ifndef OSCO_PRINT_H
#define OSCO_PRINT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes -------------------------------------------- */
#include <stdio.h>

/* Defines --------------------------------------------- */
#ifdef __APPLE__
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
//under GCC
#endif /* _WIN32 */
#if (_WIN32 || __linux__)
#define eprintf(...) fprintf (stderr, ##__VA_ARGS__)
//under MSVC
#endif /* (_WIN32 || __linux__) */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* OSCO_PRINT_H */
