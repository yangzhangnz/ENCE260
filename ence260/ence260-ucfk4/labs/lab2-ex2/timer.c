#include <avr/io.h>
#include "timer.h"

/* Initialise timer.  */
void timer_init (void)
{
    TCCR1A = 0x00; // No special functionality
    TCCR1B = 0x05; // Set prescaler to divide by 1024
    TCCR1C = 0x00; // No forced compare match
    TCNT1 = 0;     // Reset the timer count

}


/* Wait for the specified length of time.  */
void timer_delay_ms (uint16_t milliseconds)
{
    // Calculate the number of ticks required
    // 0.128ms is the time period for one tick at 1024 prescaler with 8MHz clock
    uint16_t ticks = (milliseconds / 0.128);
    TCNT1 = 0;  // Reset the timer count

    // Wait until the timer count reaches the desired number of ticks
    while (TCNT1 < ticks);
}
