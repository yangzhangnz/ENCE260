#include <avr/io.h>
#include "led.h"


/** Turn LED1 on.  */
void led_on (void)
{
    // Set the state of pin #2 of port C to HIGH, turning the LED on
    PORTC |= (1 << 2);
}


/** Turn LED1 off.  */
void led_off (void)
{
    // Clear the state of pin #2 of port C, turning the LED off
    PORTC &= ~(1 << 2);
}


/** Initialise LED1.  */
void led_init (void)
{
    // Configure pin #2 of port C as an output
    DDRC |= (1 << 2);
}
