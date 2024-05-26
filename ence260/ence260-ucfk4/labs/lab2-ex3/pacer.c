#include <avr/io.h>
#include "pacer.h"

static uint16_t pacer_period;

/* Initialise the pacer module.  */
void pacer_init (uint16_t pacer_frequency)
{
    /* TODO: initialise timer/counter peripheral the
       same way as in lab2/lab2-ex2/timer.c but also calculate 
       the timer/counter value from the pacer frequency */
    // Initialize timer/counter1
    TCCR1A = 0x00; // No special functionality
    TCCR1B = 0x05; // Set prescaler to divide by 1024
    TCCR1C = 0x00; // No forced compare match
    TCNT1 = 0;     // Reset the timer count

    uint16_t period_ms = 1000 / pacer_frequency; // Convert frequency to period in milliseconds
    pacer_period = (period_ms / 0.128);  // Calculate ticks required using 0.128ms tick time (from 1024 prescaler with 8MHz clock)
}


/* Pace a while loop.  */
void pacer_wait (void)
{

    /* TODO: Implement the same way as the timer_delay () function 
       lab2-except reset TCNT1 after the while loop. */
    while (TCNT1 < pacer_period);  // Wait until the timer count reaches the desired number of ticks
    TCNT1 = 0;  // Reset the timer after waiting for the desired time
}
