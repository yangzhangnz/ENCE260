#include "system.h"
#include "pio.h"
#include "pacer.h"


/** Define PIO pins driving LED matrix rows.  */
static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO, 
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};


/** Define PIO pins driving LED matrix columns.  */
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};


static const uint8_t bitmap[] =
{
    0x30, 0x46, 0x40, 0x46, 0x30
};



static void display_column(uint8_t row_pattern, uint8_t current_column)
{
    static int8_t previous_column = -1;  // To keep track of the previously lit column

    if (previous_column != -1) 
    {
        pio_output_high(cols[previous_column]);  // Turn off the previous column
    }

    for (int i = 0; i < LEDMAT_ROWS_NUM; i++)
    {
        if ((row_pattern >> i) & 1)  // Check if the ith bit of row_pattern is set
        {
            pio_output_low(rows[i]);
        }
        else
        {
            pio_output_high(rows[i]);
        }
    }

    pio_output_low(cols[current_column]);  // Turn on the current column

    previous_column = current_column;  // Update the previous column
}



int main (void)
{
    uint8_t current_column = 0;
  
    system_init ();
    pacer_init (500);
    
    /* TODO: Initialise LED matrix pins.  */
    for (int i = 0; i < LEDMAT_ROWS_NUM; i++)
    {
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }

    for (int i = 0; i < LEDMAT_COLS_NUM; i++)
    {
        pio_config_set(cols[i], PIO_OUTPUT_HIGH);
    }

    

    while (1)
    {
        pacer_wait ();
        
        display_column (bitmap[current_column], current_column);
    
        current_column++;
    
        if (current_column > (LEDMAT_COLS_NUM - 1))
        {
            current_column = 0;
        }           
    }
}
