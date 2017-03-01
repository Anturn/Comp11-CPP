//	proj0a snake.cpp
//	This is  the phase0 of snake: creating a initial board,
//	player can move the snake and the snake can go through
//	the edge.
//	by: Rui Qin
//	date: 3/6/2016

#include <iostream>
#include "termfuncs.h"
using namespace std;

// snake_head struct,containing the coordinate
// of arrow and the energy unit left,then a
// boolean dicides wether dead
struct snake_head {
        int row;
        int col;
        int EU;
        bool isdead;
};

// The columns and the rows including the board
const int ROWS = 23;
const int COLS = 63;
// several different marks used in board
const char EDGE = '+';
const char OUTER_HOR = '-';
const char OUTER_VER = '|';
const char BLANK = ' ';
const char PASSED = '#';

// starting point when setting up the initial board
const int ARROW_ROWS = 11;
const int ARROW_COLS = 31;

// setting up the initial board
void setup_board(char board[ROWS][COLS]);

// This function sets up the edge, the
// blank including('-' '|' '+' ' ')
void setWhole(char board[ROWS][COLS]);

// this function sets up the starting arrow '^'
void startingPoint(char board[ROWS][COLS]);

// go through the whole board and draw the picture
void draw_board(char board[ROWS][COLS]);

// finding the direction of the arrow
char finding_arrow_direction(char board[ROWS][COLS]);

// finding the coordinate of the arrow in the board
snake_head finding_arrow_coordinate(int row, int col, char board[ROWS][COLS]);

// save the change in a struct and change the head in board
snake_head moves_save(char return_direction, char board[ROWS][COLS],
		      snake_head S, int eu);

// This function takes existed direction
// and the direction from player as
// inputs, then gives out the new changed
// direction
char direction(char existed_direction, char player_direction);

// The direction collected from the user when it is 'r'
char player_right(char existed_direction);

// The direction collected from the user when it is 'l'
char player_left(char existed_direction);

// The direction collected from the user when it is 'f'
char player_foward(char existed_direction);

// output some corresponding position and EU when go up
snake_head snake_up(char board[ROWS][COLS], snake_head S, int eu);

// output some corresponding position and EU when go down
snake_head snake_down(char board[ROWS][COLS], snake_head S, int eu);

// output some corresponding position and EU when go left
snake_head snake_left(char board[ROWS][COLS], snake_head S, int eu);

// output some corresponding position and EU when go right
snake_head snake_right(char board[ROWS][COLS], snake_head S, int eu);

// generating a random reasonable snake 'o'
void snack_o_coordinate(char board[ROWS][COLS]);

// generating a random reasonable snake 'X'
void snack_X_coordinate(char board[ROWS][COLS]);

// boolean wether snake is dead
bool isDead(int row, int col, char board[ROWS][COLS], int eu);

// just cout the score
void report(int score);

// get the updated position, updating the EU
int return_EU(int row, int col, int EU, char board[ROWS][COLS]);

int play_game(char board[ROWS][COLS]);

// input :int values of row and col
// purpose :transform the head into other side of
// the board
// output :struct
snake_head edgeTransform(int row, int col);

int main() {
        char board[ROWS][COLS];
        int score;
        setup_board(board);
        score = play_game(board);
        report(score);
        return 0;
}

// input : the char board
// output : nothing
// purpose : setup the initial board including
// the edge, starting arrow, two snacks and
// the infromation show up to player such as EU
// and score
void setup_board(char board[ROWS][COLS]) {
        screen_clear();
        screen_home();
        setWhole(board);
        startingPoint(board);

        snack_X_coordinate(board);
        snack_o_coordinate(board);

        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        cout << board[i][j];
                }
                cout << endl;
        }
        cout << "EU: " << 60 << "  Score: " << 0 << endl;
}

// input : char board
// output : nothing
// purpose : this function sets up the starting arrow '^'
void startingPoint(char board[ROWS][COLS]) {
        board[ARROW_ROWS][ARROW_COLS] = '^';
}

// input : char board
// output : nothing
// purpose :This function sets up the edge, the
// blank including('-' '|' '+' ' ')
void setWhole(char board[ROWS][COLS]) {
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        board[i][j] = BLANK;
                }
        }

        board[0][0] = EDGE;
        board[0][COLS - 1] = EDGE;
        board[ROWS - 1][0] = EDGE;
        board[ROWS - 1][COLS - 1] = EDGE;
        // horizontal '-'
        for (int i = 1; i < COLS - 1; i++) {
                board[0][i] = OUTER_HOR;
                board[ROWS - 1][i] = OUTER_HOR;
        }
        // vertical '|'
        for (int j = 1; j < ROWS - 1; j++) {
                board[j][0] = OUTER_VER;
                board[j][COLS - 1] = OUTER_VER;
        }
}

int play_game(char board[ROWS][COLS]) {
        char player_R_L_F, getDirection, existed_direction;
        snake_head HEAD;
        bool isend = false;
        int EU = 60, Score = 0;

        while (!isend) {
                // collecting direction from player
                player_R_L_F = getachar();
                screen_clear();
                screen_home();

                if ((player_R_L_F == 'l') || (player_R_L_F == 'r') ||
                    (player_R_L_F == 'f')) {
                        existed_direction = finding_arrow_direction(board);
                        HEAD =
                            finding_arrow_coordinate(HEAD.row, HEAD.col, board);
                        getDirection =
                            direction(existed_direction, player_R_L_F);
                        board[HEAD.row][HEAD.col] = getDirection;
                }

                if (player_R_L_F == 'f') {
                        Score = Score + 1;
                        EU = EU - 1;
                        HEAD = moves_save(getDirection, board, HEAD, EU);
                        isend = HEAD.isdead;
                        EU = HEAD.EU;
                }
                snack_X_coordinate(board);
                snack_o_coordinate(board);
                draw_board(board);
                cout << "EU: " << EU << "  Score: " << Score << endl;
        }
        return Score;
}

// input : two int values of position, the int EU and the board
// output : the int EU
// purpose:get the updated position, updating the EU
int return_EU(int row, int col, int EU, char board[ROWS][COLS]) {
        if (board[row][col] == 'o') {
                return EU + 15;
        } else if (board[row][col] == 'X') {
                return EU + 25;
        }
        return EU;
}

// input : char board
// output : char the direction of the direction
// purpose : finding the direction of the arrow in the board
char finding_arrow_direction(char board[ROWS][COLS]) {
        char direction;
        for (int i = 1; i < ROWS - 1; i++) {
                for (int j = 1; j < COLS - 1; j++) {
                        if (board[i][j] == '^') {
                                direction = '^';
                        } else if (board[i][j] == 'v') {
                                direction = 'v';
                        } else if (board[i][j] == '<') {
                                direction = '<';
                        } else if (board[i][j] == '>') {
                                direction = '>';
                        }
                }
        }
        return direction;
}

// input : int values of the position and the char board
// output : a struct contains the position of the arrow
// purpose :finding the cooradinate of the arrow in the board
snake_head finding_arrow_coordinate(int row, int col, char board[ROWS][COLS]) {
        snake_head S;
        S.row = row;
        S.col = col;

        for (int i = 1; i < ROWS - 1; i++) {
                for (int j = 1; j < COLS - 1; j++) {
                        if (board[i][j] == '^') {
                                S.row = i;
                                S.col = j;
                        } else if (board[i][j] == 'v') {
                                S.row = i;
                                S.col = j;
                        } else if (board[i][j] == '<') {
                                S.row = i;
                                S.col = j;
                        } else if (board[i][j] == '>') {
                                S.row = i;
                                S.col = j;
                        }
                }
        }
        return S;
}

// input : int values of the position
// output : struct contains the position
// purpose :this function is used to deicide whether the snake
// goes to the edge. If it does, then it will go to the other
// side of the board.
snake_head edgeTransform(int row, int col) {
        snake_head S;
        S.row = row;
        S.col = col;
        if (row == 0) {
                S.row = ROWS - 2;
        }
        if (row == ROWS - 1) {
                S.row = 1;
        }
        if (col == 0) {
                S.col = COLS - 2;
        }
        if (col == COLS - 1) {
                S.col = 1;
        }
        return S;
}
// input :char board
// output :nothing
// purpose :go through the whole board and draw the picture
void draw_board(char board[ROWS][COLS]) {
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        cout << board[i][j];
                }
                cout << endl;
        }
}
// input :char direction, char board, a struct and a int eu
// putput : struct contains the EU, the position
// purpose: save the change in a struct and change the head in board
snake_head moves_save(char return_direction, char board[ROWS][COLS],
                      snake_head S, int eu) {
        snake_head SH;
        if (return_direction == '^') {
                SH = snake_up(board, S, eu);
        }

        if (return_direction == 'v') {
                SH = snake_down(board, S, eu);
        }

        if (return_direction == '<') {
                SH = snake_left(board, S, eu);
        }

        if (return_direction == '>') {
                SH = snake_right(board, S, eu);
        }
        return SH;
}

// input :char board,a struct and eu
// output :a struct
// purpose :return a updated struct with new
// eu,position and wether is dead
snake_head snake_up(char board[ROWS][COLS], snake_head S, int eu) {
        board[S.row][S.col] = PASSED;
        S.row--;
        S = edgeTransform(S.row, S.col);
        S.EU = return_EU(S.row, S.col, eu, board);
        S.isdead = isDead(S.row, S.col, board, eu);
        board[S.row][S.col] = '^';
        return S;
}

// input :char board,a struct and eu
// output :a struct
// purpose :return a updated struct with new
// eu,position and wether is dead
snake_head snake_down(char board[ROWS][COLS], snake_head S, int eu) {
        board[S.row][S.col] = PASSED;
        S.row++;
        S = edgeTransform(S.row, S.col);
        S.EU = return_EU(S.row, S.col, eu, board);
        S.isdead = isDead(S.row, S.col, board, eu);
        board[S.row][S.col] = 'v';
        return S;
}

// input :char board,a struct and eu
// output :a struct
// purpose :return a updated struct with new
// eu,position and wether is dead
snake_head snake_left(char board[ROWS][COLS], snake_head S, int eu) {
        board[S.row][S.col] = PASSED;
        S.col--;
        S = edgeTransform(S.row, S.col);
        S.EU = return_EU(S.row, S.col, eu, board);
        S.isdead = isDead(S.row, S.col, board, eu);
        board[S.row][S.col] = '<';
        return S;
}

// input :char board,a struct and eu
// output :a struct
// purpose :return a updated struct with new
// eu,position and wether is dead
snake_head snake_right(char board[ROWS][COLS], snake_head S, int eu) {
        board[S.row][S.col] = PASSED;
        S.col++;
        S = edgeTransform(S.row, S.col);
        S.EU = return_EU(S.row, S.col, eu, board);
        S.isdead = isDead(S.row, S.col, board, eu);
        board[S.row][S.col] = '>';
        return S;
}

// input :char a direction and direction from player
// output : new generating direction
// purpose :According to the 1,2,3,4 decides different
// directions to go and return the number
// clockwise(r): ++ ; counterclockwise(l): --;
char direction(char existed_direction, char player_direction) {
        char direction;

        if (player_direction == 'r') {
                direction = player_right(existed_direction);
        }

        if (player_direction == 'l') {
                direction = player_left(existed_direction);
        }

        if (player_direction == 'f') {
                direction = player_foward(existed_direction);
        }
        return direction;
}

// input :char a direction
// output : char a newly generating direction
// input a existed direction and output a updated one
char player_right(char existed_direction) {
        if (existed_direction == '^') {
                return '>';
        } else if (existed_direction == '>') {
                return 'v';
        } else if (existed_direction == 'v') {
                return '<';
        } else if (existed_direction == '<') {
                return '^';
        } else {
                return existed_direction;
        }
}

// input :char a direction
// output : char a newly generating direction
// input a existed direction and output a updated one
char player_left(char existed_direction) {
        if (existed_direction == '^') {
                return '<';
        } else if (existed_direction == '>') {
                return '^';
        } else if (existed_direction == 'v') {
                return '>';
        } else if (existed_direction == '<') {
                return 'v';
        } else {
                return existed_direction;
        }
}

// input :char a direction
// output : char a newly generating direction
// input a existed direction and output a updated one
char player_foward(char existed_direction) {
        return existed_direction;
}

// phase 1

// input :char board
// output : nothing
// purpose : generating a random snack in a reasonable position
// that is not overlap with the exised snake or board or snack
void snack_o_coordinate(char board[ROWS][COLS]) {
        bool existed_o = false;
        bool again = true;

        for (int i = 1; i < ROWS - 1; i++) {
                for (int j = 1; j < COLS - 1; j++) {
                        if (board[i][j] == 'o') {
                                existed_o = true;
                        }
                }
        }

        while ((again) && (!existed_o)) {
                int row = random_int(1, ROWS - 2);
                int col = random_int(1, COLS - 2);
                if (board[row][col] == BLANK) {
                        again = false;
                }
                board[row][col] = 'o';
        }
}

// input :char board
// output : nothing
// purpose : generating a random snack in a reasonable position
// that is not overlap with the exised snake or board or snack
void snack_X_coordinate(char board[ROWS][COLS]) {
        bool existed_X = false;
        bool again = true;

        for (int i = 1; i < ROWS - 1; i++) {
                for (int j = 1; j < COLS - 1; j++) {
                        if (board[i][j] == 'X') {
                                existed_X = true;
                        }
                }
        }

        while ((again) && (!existed_X)) {
                int row = random_int(1, ROWS - 2);
                int col = random_int(1, COLS - 2);
                if (board[row][col] == BLANK) {
                        again = false;
                }
                board[row][col] = 'X';
        }
}

// input :int values of the position, char board and int eu
// output :boolean that tells wether the snake is dead
// deiceds wether the snake is dead by two conditions:
// 1)eat itself 2)eu is not enough
bool isDead(int row, int col, char board[ROWS][COLS], int eu) {
        if ((board[row][col] == PASSED) || (eu == 0)) {
                return true;
        } else {
                return false;
        }
}

// input :int the total score
// output : nothing
// purpose :print out the final score to the player
void report(int score) {
        cout << "Game Over. Final Score: " << score << endl;
}
