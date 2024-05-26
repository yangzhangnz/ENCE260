#include <avr/io.h>
#include "system.h"

// Initialize LED pin
static void led_init (void)
{
    /* Initialise port to drive LED 1.  */

    // Configure pin #2 of port C as an output
    DDRC |= (1 << 2);
}

// Turn on the LED
static void led_on (void)
{
    /* Set port to turn LED 1 on.  */

    // Set the state of pin #2 of port C to HIGH, turning the LED on
    PORTC |= (1 << 2);
}

// Turn off the LED
static void led_off (void)
{
    /* Set port to turn LED 1 off.  */

    // Clear the state of pin #2 of port C, turning the LED off
    PORTC &= ~(1 << 2);
}

// Initialize button pin for input
static void button_init (void)
{
    /* Initialise port to read button 1.  */

    // Configure pin #7 of port D as an input
    DDRD &= ~(1 << 7);
}

// Check if button is pressed
static int button_pressed_p (void)
{
    /* Return non-zero if button pressed_p.  */
    return PIND & (1 << 7);
}


int main (void)
{
    system_init ();

    led_init ();
    button_init ();

    while (1)
    {
        if (button_pressed_p ())
        {
            led_on ();
        }
        else
        {
            led_off ();
        }
    }
}
