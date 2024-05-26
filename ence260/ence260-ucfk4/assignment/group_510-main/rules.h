/*******************************************************************************
 * Description:
 *   The rules of players who win, lost or even of the game
 *
 * Author:
 * - Yang Zhang (yzh365)
 *
 ******************************************************************************/

#ifndef RULES_H
#define RULES_H

#include "rps_definitions.h"

// Enumerating possible game results
typedef enum {
    WIN,     
    LOST,    
    TIED,    
} game_outcome;

/**
 * Determines the outcome of the "Rock, Paper, Scissors" game based on the letters 
 * chosen by the players.
 * 
 * @param first_player: The choice of Player 1 (one of ROCK, PAPER, SCISSORS).
 * @param second_player: The choice of Player 2 (one of ROCK, PAPER, SCISSORS).
 * @return: The outcome of the game (WIN, LOST, TIED).
 */
game_outcome rules(letter first_player, letter second_player);

#endif // RULES_H