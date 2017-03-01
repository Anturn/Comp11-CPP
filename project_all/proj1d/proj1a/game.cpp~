/*******************************************************************************
 * Game Class Implementation                                                   *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 *****************************************************************************/

#include <iostream>
using namespace std;

#include "game.h"
#include "pacman.h"
#include "ghost.h"
#include "dot.h"
#include "termfuncs.h"

/* Constructor
   Initially set up the level to level 1 and the
   initial score to zero
 */
Game::Game() {
        level = 1;
        p.add_to_score(0);
}

/* print_manual()
 * Purpose:   Prints the manual and stalls until the user types a character
 * Arguments: None
 * Returns:   None
 */
void Game::print_manual() {
        screen_clear();
        cout << "PACMAN GAME\n"
                "            \n"
                " Move left:    "
             << CMD_LFT << "\n"
                           " Move right:   "
             << CMD_RGT << "\n"
                           " Move up:      "
             << CMD_UP << "\n"
                          " Move down:    "
             << CMD_DWN << "\n"
                           "\n"
                           " Collect all the dots. They look like: "
             << DOT << "\n"
                       " Avoid the ghosts.     They look like: "
             << GHOST << "\n"
                         "\n"
                         " Good luck!\n"
                         "\n"
                         " Press any key to continue...\n";

        getachar();
}

// This function call other function to run the
// whole game

// (Sorry about my ghost file if that bothers you, I just
// start the phase1 and dont want to go back to delete
// or something)
void Game::run() {
        bool eaten, iscontinuous = true;
        char getdirection;
        int score_here = p.get_score();
        while ((level < 16) && (iscontinuous)) {
                screen_clear();
                bool isend = false;
                int eaten_times = 0;
                set_in_one();
                while (!isend) {
                        getdirection = getacharnow(SPEED);
                        eaten = return_bool(getdirection);
                        ghost_move(), print_dots_ghosts();
                        if (eaten == true) {
                                eaten_times++, score_here++;
                                p.add_to_score(score_here);
                        }
                        set_pacman();
                        isend = isgamend(eaten_times, p.is_alive());
                        clear_print_score();
                }
                clear_set();
                iscontinuous = outcome(eaten_times);
                if (iscontinuous) {
                        score_here = score_here + LEVEL_REWARD;
                        p.add_to_score(score_here);
                }
                level++;
        }
}

// This is my function refreshes the board and print out the score
void Game::clear_print_score() {
        screen_clear();
        print_whole();
        cout << "score: " << p.get_score() << endl;
}

// This function which the ghosts move in a specific pattern
void Game::ghost_move() {
        bool ghost_eat;
        if (p.get_num_moves() % GHOST_FREQ != 0) {
                for (int i = 0; i < NUM_GHOSTS; i++) {
                        ghost_eat =
                            ghosts[i].move(board, p.get_row(), p.get_col());
                        ghosts[i].place_on_board(board);
                        if (ghost_eat == true) {
                                p.set_alive(false);
                        }
                }
        }
}

// This function just prints out the score and the level
void Game::print() {
        cout << "score: " << p.get_score() << endl;
        cout << "Level " << level << ": Press any key to start" << endl;
}

// This function refreshes the dots and ghosts printing on the board
void Game::print_dots_ghosts() {
        set_space();
        set_boulders();
        print_dots();
        print_ghosts();
}

// This is my function containing some functions clear and
// set the board
void Game::clear_set() {
        screen_clear();
        set_pacman();
        print_whole();
}

/* This is the function put all the set and
   print stuff into one function
 */
void Game::set_in_one() {
        set_space();
        p.center();
        set_boulders();
        set_pacman();
        set_dots();
        set_ghosts();
        print_whole();
        print();
        getachar();
}

// input: the char command
// output: the bool decides wether the pacman eats a dot
// this function takes direction as inout and gives out
// the boolean to decide wether a dot is eaten
bool Game::return_bool(char command) {
        return p.move(board, command);
}

// This function just first creates some space
// in the board
void Game::set_space() {
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        board[i][j] = SPACE;
                }
        }
}

// This function prints out all the game
// on the screen
void Game::print_whole() {
        cout << BORD_CORN;
        for (int i = 0; i < COLS; i++) {
                cout << BORD_TOP;
        }
        cout << BORD_CORN << endl;

        for (int i = 0; i < ROWS; i++) {
                cout << BORD_SIDE;
                for (int j = 0; j < COLS; j++) {
                        cout << board[i][j];
                }
                cout << BORD_SIDE << endl;
        }

        cout << BORD_CORN;
        for (int i = 0; i < COLS; i++) {
                cout << BORD_TOP;
        }
        cout << BORD_CORN << endl;
}

// This function sets up specific number of bouderls
void Game::set_boulders() // int number_boulders)
{
        for (int i = 0; i < BOULDERS_PER_LEVEL * level;
             i++) { // number_boulders;i++
                boulders[i].place_on_board(board);
        }
}

// This function sets up specific number of dots
void Game::set_dots() {
        for (int i = 0; i < DOTS_PER_LEVEL * level; i++) {
                dots[i].set_eaten(false);
                dots[i].set_random_location(board);
                dots[i].place_on_board(board);
        }
}
// // This function just refreshes the dots and prints on the board
void Game::print_dots() {
        int pac_row = p.get_row();
        int pac_col = p.get_col();
        bool iseaten;
        for (int i = 0; i < DOTS_PER_LEVEL * level; i++) {
                iseaten = dots[i].is_at(pac_row, pac_col);
                if (iseaten == false) {
                        dots[i].place_on_board(board);
                }
        }
}

// this fucntion puts the coordinate of pacman
// into the array for the board
void Game::set_pacman() {
        p.place_on_board(board);
}

// input: int and bool
// output: the bool
// this function takes eatentimes and isalive as inputs and
// gives out a boolean to decide wether the game is end
bool Game::isgamend(int eatentimes, bool isalive) {
        if ((eatentimes == level * DOTS_PER_LEVEL) || (isalive == false)) {
                return true;
        } else {
                return false;
        }
}

// inout: a int and a boolean
// output: none
// this function cout some words to the user such as
// win or lose
bool Game::outcome(int eaten_times) {
        if (eaten_times == level * DOTS_PER_LEVEL) {
                return true;
                // cout << "score: " << score << endl;
        } else {
                cout << "You Lose !!! " << endl;
                cout << "score: " << p.get_score() << endl;
                return false;
        }
}

// this function sets up the initial four ghosts
// in four corners
void Game::set_ghosts() {
        ghosts[0].set_location(0, 0);
        ghosts[1].set_location(0, COLS - 1);
        ghosts[2].set_location(ROWS - 1, 0);
        ghosts[3].set_location(ROWS - 1, COLS - 1);
        for (int i = 0; i < 4; i++) {
                ghosts[i].place_on_board(board);
        }
}

// This function just refreshes the ghosts and prints on the board
void Game::print_ghosts() {
        for (int i = 0; i < NUM_GHOSTS; i++) {
                ghosts[i].place_on_board(board);
        }
}
