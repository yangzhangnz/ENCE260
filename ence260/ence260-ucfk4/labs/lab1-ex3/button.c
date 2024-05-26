#include <avr/io.h>
#include "button.h"


/** Return non-zero if button pressed.  */
int button_pressed_p (void)
{
    /* Return non-zero if button pressed_p.  */
    return PIND & (1 << 7);
}


/** Initialise button1.  */
void button_init (void)
{
    // Configure pin #7 of port D as an input
    DDRD &= ~(1 << 7);
}

