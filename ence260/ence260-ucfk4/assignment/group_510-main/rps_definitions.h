/*******************************************************************************
 * Description:
 *   Centralizes definitions of the game's letters and players. Facilitates 
 *   potential game modifications without changing code in multiple places.
 *
 * Author:
 * - Yang Zhang (yzh365)
 *
 ******************************************************************************/

#ifndef LETTERS_H
#define LETTERS_H

/**
 * @file rps_definitions.h
 * @brief Defines the letters and game_player types used in the game.
 */

/**
 * @brief Enum representing the letters (choices) in the game.
 *
 * Each letter corresponds to a choice in the Rock, Paper, Scissors game, 
 * with additional states for EMPTY (indicating no choice) and WAIT 
 * (indicating that the game_player is waiting for some action).
 */
typedef enum {
    ROCK      = 'R',   /* Represents the Rock choice. */
    PAPER     = 'P',   /* Represents the Paper choice. */
    SCISSOR   = 'S',   /* Represents the Scissors choice. */
    EMPTY     = 'E',   /* Represents no choice made by the game_player. */
    WAIT      = 'W'    /* Represents a waiting state for the game_player. */
} letter;

/**
 * @brief Enum representing the players in the game.
 *
 * Defines identifiers for Player 1, Player 2
 * state to indicate an undefined or invalid game_player.
 */
typedef enum {
    PLAYER1   = '1',   /* Represents Player 1. */
    PLAYER2   = '2',   /* Represents Player 2. */
} game_player;

#endif // RPS_DEFINITIONS_H