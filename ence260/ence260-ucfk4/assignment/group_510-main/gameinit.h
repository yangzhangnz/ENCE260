/*******************************************************************************
 * Description:
 *   Initializing the game's system and modules to set up 
 *   the environment for the "Rock, Paper, Scissors" game.
 *
 * Author:
 * - Yang Zhang (yzh365)
 *
 ******************************************************************************/

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font5x7_1.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "button.h"
#include <string.h>
#include "rps_definitions.h"


#define LOOP_RATE 500
#define MESSAGE_RATE 25 /* Text scroll speed */
#ifndef GAMEINIT_H
#define GAMEINIT_H

/**
 * Initializes the game settings and configurations.
 */
void initialize_game(void);

/**
 * Initializes a game_player based on the navswitch inputs.
 *
 * @param current_player: The current game_player choice.
 * @return game_player: Updated game_player choice.
 */
game_player toggle_player(game_player current_player);

#endif // GAMEINIT_H