/*******************************************************************************
 * Game Class Interface                                                        *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 ******************************************************************************/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "constants.h"
#include "pacman.h"
#include "ghost.h"
#include "dot.h"
#include "boulder.h"

class Game {
      public:
        Game();

        // prints the manual and stalls until the user types a character
        void print_manual();

        // Runs the Pacman game!
        void run();

      private:
        int level;
        char board[ROWS][COLS];
        Pacman p;
        Ghost ghosts[NUM_GHOSTS];
        Dot dots[NUM_DOTS];
        Boulder boulders[NUM_BOULDERS];
        // This is my function prints the initial frame
        void print_whole();
        // This is my function sets up the initial space
        void set_space();
        // This is my function sets up specific number of boulders
        void set_boulders();
        // This is my function randomly sets up specific number of dots
        void set_dots();
        // This is my function just refreshes the dots and prints on the board
        void print_dots();
        // This is my function sets up four ghosts in four corners
        void set_ghosts();
        // This is my function which the ghosts move in a specific pattern
        void ghost_move();
        // This is my function refreshes the dots and ghosts printing on the
        // board
        void print_dots_ghosts();
        // This is my function just refreshes the ghosts and prints on the board
        void print_ghosts();
        // This is my function sets up the pacman
        void set_pacman();
        // This is my function refresh the board and print out the score
        void clear_print_score();
        // This is my function collects all set up and print function
        // togethor
        void set_in_one();
        // This is my function containing some functions clear and
        //  set the board
        void clear_set();
        // This function just prints out the score and the level
        void print();
        // This is my function deicides wether the game is end
        bool isgamend(int, bool);
        // This is my function to cout some words to the user when the game is
        // end
        bool outcome(int);
        // This is my function to decide wether the dot iseaten
        bool return_bool(char);
};

#endif
