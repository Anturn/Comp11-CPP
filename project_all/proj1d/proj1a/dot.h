/*******************************************************************************
 * Dot Class Interface                                                         *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 ******************************************************************************/
#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED

#include "constants.h"

class Dot {
      public:
        /* Constructor initalizes private members */
        Dot();

        /*
         * Chooses a random location for the dot on the board. This
         * function chooses a location that is occupied by a space.
         *
         * Arguments:
         *      - 2D array of board
         *
         * Returns:
         *      - None
         */
        void set_random_location(char board[ROWS][COLS]);

        /*
         * Places the Dot on the board, at its location.
         *
         * Arguments:
         *      - 2D array of board
         *
         * Returns: None.
         */
        void place_on_board(char board[ROWS][COLS]);

        /* returns if the Dot is at this row and col */
        bool is_at(int r, int c);

        /* sets eaten to be the passed-in bool */
        void set_eaten(bool); // CACACACACACACACACACACACACACACACACACACAC

        /* returns if the dot has been eaten */
        bool was_eaten();

      private:
        int row, col;
        bool eaten;
};

#endif
