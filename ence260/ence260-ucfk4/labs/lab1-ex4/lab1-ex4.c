#include "pio.h"

#define LED_PIO PIO_DEFINE(PORT_C, 2)
#define BUTTON_PIO PIO_DEFINE(PORT_D, 7)

static int led_state = 0; // 0 means off, 1 means on

int main(void)
{
    system_init();
    led_init();
    button_init();

    int prev_button_state = 0;

    while (1)
    {
        int current_button_state = button_pressed_p();

        if (prev_button_state == 0 && current_button_state == 1) // Detecting rising edge
        {
            if (led_state == 0)
            {
                led_on();
                led_state = 1;
            }
            else
            {
                led_off();
                led_state = 0;
            }
        }
        prev_button_state = current_button_state;
    }
}
