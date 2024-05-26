/*******************************************************************************
 * Description:
 *   The main entry point to the program.
 *   Handles game initialisation and runs the main game loop.
 *
 * Author:
 * - Yang Zhang (yzh365)
 * 
 ******************************************************************************/

#include "rules.h"
#include "action.h"
#include "gameinit.h"
#include "rps_definitions.h"


#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font5x7_1.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "button.h"
#include <stdbool.h>

#define IR_RATE 250
#define LOOP_RATE 500

/* Helper function to check if the received choice is valid */
bool is_valid_choice(letter choice) {
    return (choice == PAPER || choice == ROCK || choice == SCISSOR);
}

int main (void)
{
    /* Initialize game status variables */
    char game_started = 0;     /* Indicates the status of the game (0: not started, 1: started) */
    char letter_sent = 0;      /* Indicates if the letter has been sent or not (0: not sent, 1: sent) */
    char letter_received = 1;  /* Indicates if the letter has been received from game_player 2 (0: not received, 1: received) */
    char player_ready = 1;     /* Indicates if game_player 1 is ready (0: not ready, 1: ready) */
    char game_result = 0;      /* Indicates the result of the game (0: not decided, 1: decided) */

    /* Initialization of game_player letters */
    letter aletter = EMPTY;
    letter first_player = EMPTY;
    letter second_player = EMPTY;

    /* Initialize IR communication */
    uint8_t ir_ticks = 0;

    /* Initialize game settings and configurations */
    initialize_game();

    /* There is the main logic loops of this game */
    while (1)
    {
        /* System updates */
        pacer_wait();
        navswitch_update();
        button_update();
        tinygl_update();

        /* Press the left button to start the game */
        if (game_started == 0 && button_push_event_p (BUTTON1)) {
            game_started = 1; /* Set the status of game as started */
            player_ready = 0; /* Set the status of game_player 1 as not ready */
        }

        /* Push the button to reset game */
        if (game_result && button_push_event_p(BUTTON1)) {
            player_ready = 1;
            first_player = EMPTY;
            aletter = EMPTY;
            letter_sent = 0;
            second_player = EMPTY;
            letter_received = 1;
            game_started = 0;
            game_result = 0;
            ir_ticks = 0;
            tinygl_clear();
            initialize_game();
        }

        /* When the game started and player 1 is not ready (before make a choice) */
        if (player_ready == 0) {

            first_player = select_letter_using_navswitch(first_player); /* Choose a letter from R/P/S by using navigtor button */
            display_letter(first_player);                   /* Display the choosen letter on the LED */

            if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
                if (first_player != EMPTY) {
                    tinygl_clear(); 
                    letter_sent = 1;
                    letter_received = 0;
                    player_ready = 1;
                } else {
                    first_player = PAPER; /* If players do nothing then the default letter is P (Paper) */
                    player_ready = 1;
                }
            }
        } else if (player_ready == 1) { /* When the game started and player 1 is ready as well, wait player 2 to ready */
            ir_ticks++;
            /* Check if it's time to handle IR communication based on the LOOP_RATE and IR_RATE */
            if (ir_ticks >= (LOOP_RATE / IR_RATE)) {
                /* If there's data available for reading from the IR channel */
                if (ir_uart_read_ready_p ()) {
                    aletter = ir_uart_getc(); /* Receive the choice of the opponent from the IR channel */
                    ir_uart_putc(first_player); /* Send the current player's choice to the opponent via the IR channel */
                    /* Validate the received choice to ensure it's one of the valid game options */
                    if (is_valid_choice(aletter)) {
                        second_player = aletter; // Store the opponent's choice
                        letter_received = 1;     // Set flag indicating a valid choice has been received
                    }
                }
            }
        }
        
        /* Display waiting infomation "W" if Player 2's choice hasn't been received */
        if (letter_received == 0) {
            display_letter(WAIT);
        }

        /*  According to the rule(first_player, second_player) from rules.c to display the coutcome on the LED */
        if (game_result == 0){
            if (letter_sent == 1 && letter_received == 1) {
                uint8_t results = rules(first_player, second_player);

                if (results == WIN) {
                    tinygl_clear();
                    tinygl_text("WINNER!");
                    game_result = 1;
                } else if (results == LOST) {
                    tinygl_clear();
                    tinygl_text("LOSER!");
                    game_result = 1;
                } else if (results == TIED){
                    tinygl_clear();
                    tinygl_text("DRAW!");
                    game_result = 1;
                }
            }
        }
    }
    return 0;
}