//	proj0a snake.cpp
//	This is  the phase0 of snake: creating a initial board,
//	player can move the snake and the snake can go through
//	the edge.
//	by: Rui Qin
//	date: 3/6/2016

#include <iostream>
#include "termfuncs.h"
using namespace std;

struct snake_head {
        int row;
        int col;
};

struct snack_o {
	int row;
	int col;
};

struct snack_X {
	int row;
	int col;
}

const int ROWS = 23, COLS = 63; // The columns and the rows including the board
const int EU = 60;
const char EDGE = '+', OUTER_HOR = '-', OUTER_VER = '|', BLANK = ' ',
           PASSED = '#'; // several different marks used in board
const int ARROW_ROWS = 11, ARROW_COLS = 31;
// starting point when setting up the initial board

void setup_board(char board[ROWS][COLS]);
void setWhole(char board[ROWS][COLS]); // This function sets up the edge, the
                                       // blank including('-' '|' '+' ' ')
void startingPoint(
    char board[ROWS][COLS]); // THis function sets up the starting arrow '^'

void draw_board(char board[ROWS][COLS]); // go through the whole board and
// draw the picture

char finding_arrow_direction(char board[ROWS][COLS]); // finding the direction
// of the arrow

snake_head finding_arrow_coordinate(int row, int col, char board[ROWS][COLS]);
// finding the coordinate
// of the arrow in the board

bool moves_save(
    char return_direction, char board[ROWS][COLS],
    snake_head S); // save the change in a struct and change the head in board

char direction(char existed_direction,
               char player_direction); // This function takes existed direction
                                       // and the direction from player as
                                       // inputs, then gives out the new changed
                                       // direction
char player_right(
    char existed_direction); // The direction collected from the user
// when it is 'r'
char player_left(
    char existed_direction); // The direction collected from the user
// when it is 'l'
char player_foward(
    char existed_direction); // The direction collected from the user
// when it is 'f'

snack_o snack_o_coordinate(int row, int col,char board[ROW][COLS]);
snack_X snack_X_coordinate(int row, int col,char board[ROW][COLS]);

void play_game(char board[ROWS][COLS]);
snake_head edgeTransform(int row,
                         int col); // transform the head into other side of
// the board and save in the struct


int main() {
        char board[ROWS][COLS]; // OR struct
        // int score;
        setup_board(board);
        play_game(board);
        // score = play_game(board);
        // report(score);
        return 0;
}

void setup_board(char board[ROWS][COLS]) {
        setWhole(board);
        startingPoint(board);
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        cout << board[i][j];
                }
                cout << endl;
        }
}

void startingPoint(
    char board[ROWS][COLS]) // THis function sets up the starting arrow '^'
{
        board[ARROW_ROWS][ARROW_COLS] = '^';
}

void setWhole(char board[ROWS][COLS]) // This function sets up the edge, the
                                      // blank including('-' '|' '+' ' ')
{
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        board[i][j] = BLANK;
                }
        }

        board[0][0] = EDGE;
        board[0][62] = EDGE;
        board[22][0] = EDGE;
        board[22][62] = EDGE;

        for (int i = 1; i < COLS - 1; i++) { // horizontal '-'
                board[0][i] = OUTER_HOR;
                board[22][i] = OUTER_HOR;
        }

        for (int j = 1; j < ROWS - 1; j++) { // vertical '|'
                board[j][0] = OUTER_VER;
                board[j][62] = OUTER_VER;
        }
}

void play_game(
    char board[ROWS][COLS]) { // get the order decides wether to move forward
        // or change the direction, by calling the function
        //"direction"

        char player_R_L_F;
        char getDirection;
        snake_head HEAD;
        char existed_direction;
        bool isend = false;

        while (!isend) {
                player_R_L_F = getachar(); // collecting direction from player
                screen_clear();
                screen_home();

                existed_direction = finding_arrow_direction(board);
                HEAD = finding_arrow_coordinate(HEAD.row, HEAD.col, board);
		
                getDirection = direction(existed_direction, player_R_L_F);
                board[HEAD.row][HEAD.col] = getDirection;
`
                if (player_R_L_F == 'f') {
                        isend = moves_save(getDirection, board, HEAD);
                }
                draw_board(board);
        }
}

char finding_arrow_direction(char board[ROWS][COLS]) {
        // Finding the direction of the arrow in the board
        for (int i = 1; i < ROWS - 1; i++) {
                for (int j = 1; j < COLS - 1; j++) {
                        if (board[i][j] == '^') {
                                return '^';
                        } else if (board[i][j] == 'v') {
                                return 'v';
                        } else if (board[i][j] == '<') {
                                return '<';
                        } else if (board[i][j] == '>') {
                                return '>';
                        }
                }
        }
}

snake_head finding_arrow_coordinate(int row, int col, char board[ROWS][COLS]) {
        // Finding the cooradinate of the arrow in the board
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

snake_head edgeTransform(int row, int col) {
        // This function is used to deicide whether the snake
        // goes to the edge. If it does, then it will go to the other
        // side of the board.
        snake_head S;
        S.row = row;
        S.col = col;
        if (row == 0) {
                S.row = 21;
        }
        if (row == 22) {
                S.row = 1;
        }
        if (col == 0) {
                S.col = 61;
        }
        if (col == 62) {
                S.col = 1;
        }
        return S;
}

void draw_board(char board[ROWS][COLS]) {
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        cout << board[i][j];
                }
                cout << endl;
        }
}

bool moves_save(char return_direction, char board[ROWS][COLS], snake_head S) {
        if (return_direction == '^') {
                board[S.row][S.col] = PASSED;
                S.row--;
                S = edgeTransform(S.row, S.col);
		board[S.row][S.col] = '^';
		return isDead(S.row,S.col,board));
        }

        if (return_direction == 'v') {
                board[S.row][S.col] = PASSED;
                S.row++;
                S = edgeTransform(S.row, S.col);
		board[S.row][S.col] = 'v';
		return isDead(S.row,S.col,board));
	}

        if (return_direction == '<') {
                board[S.row][S.col] = PASSED;
                S.col--;
                S = edgeTransform(S.row, S.col);
		board[S.row][S.col] = '<';
		return isDead(S.row,S.col,board));
	}
	
        if (return_direction == '>') {
                board[S.row][S.col] = PASSED;
                S.col++;
                S = edgeTransform(S.row, S.col);
		board[S.row][S.col] = '>';
		return isDead(S.row,S.col,board));
	}
	
}

char direction(char existed_direction, char player_direction) ////////// PROBLEM
{ // According to the 1,2,3,4 decides different
        // directions to go and return the number
        // clockwise(r): ++ ; counterclockwise(l): --;

        if (player_direction == 'r') {
                return player_right(existed_direction);
        }

        if (player_direction == 'l') {
                return player_left(existed_direction);
        }

        if (player_direction == 'f') {
                return player_foward(existed_direction);
        }
}

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

char player_foward(char existed_direction) {
        return existed_direction;
}





//phase 1

snack_o snack_o_coordinate(int row, int col,char board[ROW][COLS]){
	snake_o O;
	bool existed_o = false;
	bool again = true;
	
	for (int i = 1; i < ROWS - 1; i++) {
                for (int j = 1; j < COLS - 1; j++) {
			if (board[i][j] == 'o'){
				O.row = i;
				O.col = j;
				existed_o = true;
			}
		}
	}
	
	while((again) && (!existed_o)){
		O.row = random_int(1,21);
		O.col = random_int(1,61);
			if(board[O.row][O.col] == BLANK){
					again = false;
				}
	}
	return O;
	
}

snack_X snack_X_coordinate(int row, int col,char board[ROW][COLS]){
	snake_X X;
	bool existed_X = false;
	bool again = true;
	
	for (int i = 1; i < ROWS - 1; i++) {
                for (int j = 1; j < COLS - 1; j++) {
			if (board[i][j] == 'X'){
				O.row = i;
				O.col = j;
				existed_X = true;
			}
		}
	}
	
	while((again) && (!existed_X)){
		X.row = random_int(1,21);
		X.col = random_int(1,61);
			if(board[X.row][X.col] == BLANK){
					again = false;
				}
	}
	return X;
	
}

bool isDead(int row,int col,char board){
	if(board[row][col] == PASSED){
		return true; 
	}else{
		return false;
	}
	


}










