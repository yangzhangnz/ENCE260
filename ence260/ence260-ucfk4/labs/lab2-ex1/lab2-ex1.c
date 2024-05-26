#include <avr/io.h>
#include "system.h"
#include "led.h"


int main (void)
{
    system_init ();
    led_init ();
    
    /* TODO: Initialise timer/counter1.  */
    TCCR1A = 0x00;  // No special functionality
    TCCR1B = 0x05;  // Set prescaler to divide by 1024
    TCCR1C = 0x00;  // No forced compare match
    TCNT1 = 0;      // Reset the timer count
    
    // uint8_t ledState = 1;  // Start with LED ON

    // while (1)
    // {
    //     if (TCNT1 >= 39) {  // Check if timer has reached 0.5 seconds (3906 ticks)
    //         led_set (LED1, ledState);  // Toggle LED state
    //         ledState ^= 1;  // Toggle the ledState for next iteration
    //         TCNT1 = 0;  // Reset Timer/Counter1 to count again
    //     }
    // }
    
    uint8_t ledState = 1;
    uint16_t threshold = 20;  // Starting with LED ON (25% duty cycle)

    while (1) {
        if (TCNT1 >= threshold) {
            led_set (LED1, ledState);
            if (ledState) {
                ledState = 0;
                threshold = 59;  // Set threshold for OFF period (75% duty cycle)
            } else {
                ledState = 1;
                threshold = 20;  // Set threshold for ON period (25% duty cycle)
            }
            TCNT1 = 0;
        }
}

}
