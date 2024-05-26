#include "system.h"
#include "pio.h"
#include "pacer.h"

#define LED_MATRIX_ROW1 PA0_PIO
#define LED_MATRIX_ROW2 PA1_PIO
#define LED_MATRIX_COL1 PB0_PIO
#define LED_MATRIX_COL2 PB1_PIO

static bool toggleState = false;

int main (void)
{
    system_init ();
    
    // Initialize the pins of the LED matrix as outputs and set to high (off state).
    pio_config_set(LED_MATRIX_ROW1, PIO_OUTPUT_HIGH);
    pio_config_set(LED_MATRIX_ROW2, PIO_OUTPUT_HIGH);
    pio_config_set(LED_MATRIX_COL1, PIO_OUTPUT_HIGH);
    pio_config_set(LED_MATRIX_COL2, PIO_OUTPUT_HIGH);

    // Set up pacer with a frequency of 100 Hz.
    pacer_init (100);

    while (1)
    {
        // Pace the loop.
        pacer_wait ();
        
        if (toggleState)
        {
            // Configuration 1: Set first and last row pins low, first column low.
            pio_output_low(LED_MATRIX_ROW1);
            pio_output_low(LED_MATRIX_ROW2);
            pio_output_low(LED_MATRIX_COL1);
            pio_output_high(LED_MATRIX_COL2);
        }
        else
        {
            // Configuration 2: Set only first row low, last column low.
            pio_output_low(LED_MATRIX_ROW1);
            pio_output_high(LED_MATRIX_ROW2);
            pio_output_high(LED_MATRIX_COL1);
            pio_output_low(LED_MATRIX_COL2);
        }
        toggleState = !toggleState;  // Toggle the state for the next iteration.
    }
}
