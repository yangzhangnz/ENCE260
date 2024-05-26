/*******************************************************************************
 * Description:
 *   This header file contains the function prototypes for the pacing 
 *   functionality of the system.
 *
 * Author:
 * - Yang Zhang (yzh365)
 *
 ******************************************************************************/

#ifndef PACER_H
#define PACER_H

#include "system.h"

/**
 * @file pacer.h
 * @brief Timing pacing module for timed communication routines.
 */

/**
 * @brief Initialise the timing pacing module.
 *
 * This function sets up the timing pacer to a specified frequency. 
 * The frequency determines the pace at which the communication routines will operate.
 *
 * @param timing_frequency The frequency in Hz at which the communication should be paced.
 */
void pacer_init (uint16_t timing_frequency);

/**
 * @brief Wait for the next communication cycle.
 * 
 * This function is used inside a loop to ensure that the communication routines 
 * run at the frequency set during the initialization of the timing module. 
 * This can be used to make sure certain communication operations run at a consistent rate.
 */
void pacer_wait (void);

#endif // PACER_H