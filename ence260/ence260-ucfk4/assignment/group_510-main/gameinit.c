/*******************************************************************************
 * Description:
 *   Initializing the game's system and modules to set up 
 *   the environment for the "Rock, Paper, Scissors" game.
 *
 * Author:
 * - Yang Zhang (yzh365)
 *
 ******************************************************************************/

#include "gameinit.h"

/**
 * Initializes game settings, configurations, and modules.
 * Sets up the display, navigation switch, button, IR communication, 
 * and the game timing.
 */
void initialize_game (void)
{
    // Initialize system and game timing
    system_init();
    pacer_init(LOOP_RATE);

    // Configure display settings
    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    tinygl_text("WELCOME TO ROCK PAPER SCISSOR GAME!");

    // Initialize navigation switch and game button
    navswitch_init();
    button_init ();

    // Initialize IR communication for player interaction
    ir_uart_init();
}

/**
 * Toggles between PLAYER1 and PLAYER2 based on the navigation switch input.
 * If either the NORTH or SOUTH button is pressed, the current player will switch.
 * 
 * @param current_player The current player state.
 * @return The updated player state after considering the button press.
 */
game_player toggle_player(game_player current_player)
{
    // Check for NORTH or SOUTH button press
    if (navswitch_push_event_p (NAVSWITCH_NORTH) || navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        // Toggle between PLAYER1 and PLAYER2
        current_player = (current_player == PLAYER1) ? PLAYER2 : PLAYER1;
    }
    
    return current_player;
}
