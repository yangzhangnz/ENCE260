/*******************************************************************************
 * Description:
 *   Provides the implementation for the user actions outlined in action.h. 
 *   It utilizes various system utilities, such as tinygl for screen rendering 
 *   and navswitch for navigation switch input detection, to effectively handle 
 *   and display game letters.
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
#include "action.h"
#include "rps_definitions.h"

/**
 * Displays the given letter on the screen.
 * 
 * @param aletter The letter to be displayed.
 */
void display_letter(letter aletter)
{
    char letter_as_string[2];                       /* Create a string to hold the letter and the null terminator */
    letter_as_string[0] = aletter;                  /* Assign the given letter to the string */   
    letter_as_string[1] = '\0';                     /* Assign the null-terminate the string */
    tinygl_text(letter_as_string);                  /* Use TinyGL to display the letter on the screen */
}

/**
 * Players select their desired letter by pressing the navigator button.
 * NAVSWITCH_NORTH cycles through the letters in the order: ROCK -> PAPER -> SCISSOR.
 * NAVSWITCH_SOUTH cycles in reverse order: ROCK -> SCISSOR -> PAPER.
 * 
 * @param current_letter The currently selected letter.
 * @return The newly selected letter after the button press.
 */
letter select_letter_using_navswitch(letter current_letter)
{
    if (navswitch_push_event_p(NAVSWITCH_NORTH) || navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        switch (current_letter) {
            case ROCK:
                // If NORTH is pressed, switch to PAPER, otherwise, switch to SCISSOR for SOUTH
                return (navswitch_push_event_p(NAVSWITCH_NORTH)) ? PAPER : SCISSOR;

            case PAPER:
                // If NORTH is pressed, switch to SCISSOR, otherwise, switch to ROCK for SOUTH
                return (navswitch_push_event_p(NAVSWITCH_NORTH)) ? SCISSOR : ROCK;

            case SCISSOR:
            default:
                // If NORTH is pressed or for any other unexpected value, switch to ROCK, otherwise, switch to PAPER for SOUTH
                return (navswitch_push_event_p(NAVSWITCH_NORTH)) ? ROCK : PAPER;
        }
    }

    // Return the current letter if no button was pressed
    return current_letter;
}