#include "pio.h"
#include "system.h"


int main (void)
{
    system_init ();

    // pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_HIGH);
    // pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_HIGH);

    // pio_output_low(LEDMAT_ROW1_PIO);
    // pio_output_low(LEDMAT_COL1_PIO);

    // Configure all rows and the first column for output
    pio_config_set(LEDMAT_ROW1_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW2_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW3_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW4_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW5_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW6_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_ROW7_PIO, PIO_OUTPUT_HIGH);
    pio_config_set(LEDMAT_COL1_PIO, PIO_OUTPUT_HIGH);

    // Drive all rows and the first column low
    pio_output_low(LEDMAT_ROW1_PIO);
    pio_output_low(LEDMAT_ROW2_PIO);
    pio_output_low(LEDMAT_ROW3_PIO);
    pio_output_low(LEDMAT_ROW4_PIO);
    pio_output_low(LEDMAT_ROW5_PIO);
    pio_output_low(LEDMAT_ROW6_PIO);
    pio_output_low(LEDMAT_ROW7_PIO);
    pio_output_low(LEDMAT_COL1_PIO);

    while (1)
    {

        /* TODO.  Use PIO module to turn on LEDs in
           LED matrix.  */

    }
}
