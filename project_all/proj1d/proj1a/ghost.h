/*******************************************************************************
 * Ghost Class Interface                                                       *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 ******************************************************************************/
#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

#include "constants.h"

class Ghost {
      public:
        Ghost();

        /* for initializing location */
        void set_location(int row, int col);
        /* give the boolean to decide wether the ghost encounter a dot*/
        bool move(char[ROWS][COLS], int target_r, int target_c);
        /* place the position on the board*/
        void place_on_board(char[ROWS][COLS]);

        bool is_at(int row, int col);

      private:
        int row, col;
};
#endif
