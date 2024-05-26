#include <avr/io.h>
#include "pacer.h"

static uint16_t pacer_period;

void pacer_init (uint16_t pacer_frequency)
{
    // Here, I assume the same timer configuration as the previous exercise.
    // You might need to adjust for your specific setup.
    TCCR1A = 0x00;
    TCCR1B = 0x05;  // Prescaler set to divide by 1024.
    TCCR1C = 0x00;
    
    // Calculate period for the given frequency.
    // TCNT1 will increment every 128us as per the previous calculations.
    // 1 second = 1,000,000us. Hence, 1 second divided by desired frequency gives period in microseconds.
    pacer_period = (1000000 / pacer_frequency) / 128;
}

void pacer_wait (void)
{
    while (TCNT1 < pacer_period);
    TCNT1 = 0;  // Reset the timer.
}
