/*******************************************************************************
 * Description:
 *   Serves as the interface for letter-related user actions in the 
 *   "Rock, Paper, Scissors" game. It provides function prototypes related to 
 *   the selection and display of game letters (ROCK, PAPER, SCISSOR) on the screen. 
 *   Specifically, it enables a user to cycle through game letters using external 
 *   inputs (like a navigation switch) and display the currently selected letter.
 *
 * Author:
 * - Yang Zhang (yzh365)
 *
 ******************************************************************************/

#ifndef ACTION_H
#define ACTION_H

#include "rps_definitions.h"

/* Displays the letter on the screen. */
void display_letter(letter a_letter);

/* 
 * Retrieve the current letter and it will be changed 
 * whenever NORTH or SOUTH is pressed.
 */
letter select_letter_using_navswitch(letter current_letter);

#endif // ACTION_H
