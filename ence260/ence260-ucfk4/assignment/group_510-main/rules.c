/*******************************************************************************
 * Description:
 *   The rules of players who win, lost or tied of the game
 *
 * Author:
 * - Yang Zhang (yzh365)
 *
 ******************************************************************************/

#include "rules.h"
#include "rps_definitions.h"

#include "pacer.h"
#include "tinygl.h"

/**
 * Determines the outcome of the "Rock, Paper, Scissors" game based on the letters 
 * chosen by the players.
 * 
 * @param first_player: The choice of Player 1 (one of ROCK, PAPER, SCISSORS).
 * @param second_player: The choice of Player 2 (one of ROCK, PAPER, SCISSORS).
 * @return: The outcome of the game (WIN, LOST, TIED, UNDECIDED).
 */
game_outcome rules(letter first_player, letter second_player)
{
    
    // Player 1 wins
    if ((first_player == SCISSOR && second_player == PAPER) ||
        (first_player == PAPER && second_player == ROCK) ||
        (first_player == ROCK && second_player == SCISSOR)) 
    {
        return WIN;
    }

    // Player 2 wins
    if ((first_player == SCISSOR && second_player == ROCK) || 
               (first_player == ROCK && second_player == PAPER) ||
               (first_player == PAPER && second_player == SCISSOR))
    {
        return LOST;
    }
    
    // Game is tied
    return TIED;
}