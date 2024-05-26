/*******************************************************************************
 * Description:
 *   Provide pacer_init() and pacer_wait()
 *
 * Author:
 * - Yang Zhang (yzh365)
 *
 ******************************************************************************/

#include "pacer.h"

/* Defining Clock Frequency for the AVR */
#define F_CPU 16000000 // clock frequency = 16 MHz

/* Defining Timer1 Prescaler value */
#define TIMER1_PRESCALE 1024 // Prescalers are used to divide the clock frequency to a desired rate

/* Variable to hold the period for pacing */
static uint16_t pacer_period;

/**
 * @brief Initialize the timing module with a specific frequency.
 *
 * @param pacer_frequency Desired frequency in Hz for the timing.
 */
void pacer_init(uint16_t pacer_frequency) 
{
    TCNT1 = 0;                              // Reset Timer1 counter
    TCCR1A = 0x00;                          // Configure Timer1 for normal mode (no waveform generation)
    TCCR1B = 0x05;                          // Set the prescaler to 1024
    TCCR1C = 0x00;                          // No forced output comparisons
    pacer_period = (1000 / pacer_frequency);// Calculate the timing period (in milliseconds) based on the desired frequency
}

/**
 * @brief Pause execution to achieve a consistent timing.
 *
 * This function will block until the specified timing period has elapsed.
 */
void pacer_wait(void) 
{
    /* Calculate the number of timer ticks required to achieve the desired delay duration. */
    uint16_t ticks_required = pacer_period * ((F_CPU / TIMER1_PRESCALE) / 1000);

    /* Block execution until Timer1 has counted up to the required number of ticks. */
    while (TCNT1 < ticks_required) 
    {
        continue;
    }

    TCNT1 = 0; // Reset Timer1 counter for the next round
}
