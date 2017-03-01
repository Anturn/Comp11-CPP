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
	int EU;
	bool isdead;
};



const int ROWS = 23, COLS = 63; // The columns and the rows including the board

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

snake_head moves_save(char return_direction, char board[ROWS][COLS], snake_head S,int eu) ;
// save the change in a struct and change the head in board

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

void snack_o_coordinate(char board[ROWS][COLS]);
void snack_X_coordinate(char board[ROWS][COLS]);

bool isDead(int row,int col,char board[ROWS][COLS],int eu);

void report(int score);

int return_EU(int row,int col ,int EU,char board[ROWS][COLS]);

int play_game(char board[ROWS][COLS]);
snake_head edgeTransform(int row,
                         int col); // transform the head into other side of
// the board and save in the struct


int main() {
        char board[ROWS][COLS]; // OR struct
        int score;
        setup_board(board);
        //play_game(board);
        score = play_game(board);
        report(score);
        return 0;
}

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
        cout << "EU: " << 60 <<"  Score: " << 0 <<endl;
   
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

int play_game(
    char board[ROWS][COLS]) { // get the order decides wether to move forward
        // or change the direction, by calling the function
        //"direction"

        char player_R_L_F;
        char getDirection;
        snake_head HEAD;
        char existed_direction;
        bool isend = false;
	int EU = 60;
	int Score = 0;
	
	
	

        while (!isend) {
		
	
                
		player_R_L_F = getachar();// collecting direction from player
                screen_clear();
                screen_home();
		
		if ((player_R_L_F == 'l')||(player_R_L_F == 'r')||(player_R_L_F == 'f')) {
		
		
                existed_direction = finding_arrow_direction(board);
                HEAD = finding_arrow_coordinate(HEAD.row, HEAD.col, board);
		
                getDirection = direction(existed_direction, player_R_L_F);
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
		cout << "EU: " << EU <<"  Score: " << Score<<endl;
		
        }
        return Score;
}

int return_EU(int row,int col ,int EU,char board[ROWS][COLS]){
	if(board[row][col] == 'o'){
		return EU + 15;
	}else if (board[row][col] == 'X'){
		return EU + 25;
	}
	return EU;
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

snake_head moves_save(char return_direction, char board[ROWS][COLS], snake_head S,int eu) {
	if (return_direction == '^') {
                board[S.row][S.col] = PASSED;
                S.row--;
                S = edgeTransform(S.row, S.col);
		
		S.EU = return_EU(S.row,S.col,eu,board);
		
		
		S.isdead = isDead(S.row,S.col,board,eu);
		
		board[S.row][S.col] = '^';
		return S;
        }

        if (return_direction == 'v') {
                board[S.row][S.col] = PASSED;
                S.row++;
                S = edgeTransform(S.row, S.col);
		
		S.EU = return_EU(S.row,S.col,eu,board);
		
		S.isdead = isDead(S.row,S.col,board,eu);
		
		board[S.row][S.col] = 'v';
		return S;
		
	}

        if (return_direction == '<') {
                board[S.row][S.col] = PASSED;
                S.col--;
                S = edgeTransform(S.row, S.col);
		
		S.EU = return_EU(S.row,S.col,eu,board);
		
		S.isdead = isDead(S.row,S.col,board,eu);
		
		board[S.row][S.col] = '<';
		return S;
	
	}
	
        if (return_direction == '>') {
                board[S.row][S.col] = PASSED;
                S.col++;
                S = edgeTransform(S.row, S.col);
		
		S.EU = return_EU(S.row,S.col,eu,board);
		
		S.isdead = isDead(S.row,S.col,board,eu);
		
		board[S.row][S.col] = '>';
		return S;
	
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

void snack_o_coordinate(char board[ROWS][COLS]){
	bool existed_o = false;
	bool again = true;
	
	for (int i = 1; i < ROWS - 1; i++) {
                for (int j = 1; j < COLS - 1; j++) {
			if (board[i][j] == 'o'){
				existed_o = true;
			}
		}
	}
	
	while((again) && (!existed_o)){
		int row = random_int(1,21);
		int col = random_int(1,61);
			if(board[row][col] == BLANK){
					again = false;
				}
				 board[row][col] = 'o';
	}
	
}

void snack_X_coordinate(char board[ROWS][COLS]){
	bool existed_X = false;
	bool again = true;
	
	for (int i = 1; i < ROWS - 1; i++) {
                for (int j = 1; j < COLS - 1; j++) {
			if (board[i][j] == 'X'){
				existed_X = true;
			}
		}
	}
	
	while((again) && (!existed_X)){
		int row = random_int(1,21);
		int col = random_int(1,61);
			if(board[row][col] == BLANK){
					again = false;
				}
				board[row][col] = 'X';
	}
	
}

bool isDead(int row,int col,char board[ROWS][COLS],int eu){
	if((board[row][col] == PASSED) || (eu == 0)){
		return true; 
	}
	else{
		return false;
	}
	
}


void report(int score){
	cout << "Game Over. Final Score: " << score << endl;



}







