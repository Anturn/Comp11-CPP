// Example program
#include <iostream>
#include <string>
using namespace std;

const int ROWS = 23, COLS = 63;
const char EDGE ='+',OUTER_HOR ='-',OUTER_VER ='|',BLANK = ' '; 

void setup_board(char board[ROWS][COLS]);
void setWhole(char board[ROWS][COLS]); //This function sets up the edge, the blank including('-' '|' '+' ' ')
void startingPoint(char board[ROWS][COLS]);// THis function sets up the starting arrow '^'


int main()
{
char board[ROWS][COLS];  // OR struct
//int score;
setup_board(board);
//score = play_game(board);
//report(score);
return 0;
}


void setup_board(char board[ROWS][COLS])
{	
	
	setWhole(board);
	startingPoint(board);
	for(int i = 0;i < ROWS;i++){
		for(int j = 0;j < COLS;j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}

void startingPoint(char board[ROWS][COLS]){
	board[11][31] = '^';
}


void setWhole(char board[ROWS][COLS]) {

	
	for(int i = 0;i < ROWS;i++){
		for(int j = 0;j < COLS;j++){
			board[i][j] = BLANK;
		}
	}
	
	board[0][0]= EDGE;	//???????//wether uses constant???
	board[0][62]= EDGE;
	board[22][0]= EDGE;
	board[22][62]= EDGE;
	
	for(int i=1;i < COLS-1;i++){ //horizontal '-'
		board[0][i]=OUTER_HOR;
		board[22][i]=OUTER_HOR;
		//cout << board[0][i];
		//cout << board[22][i];
	}
	
	for(int j=1;j < ROWS-1;j++){ //vertical
		board[j][0]=OUTER_VER;
		board[j][62]=OUTER_VER;
		//cout << board[j][0];
		//cout << board[j][62];
	}
	
	
	
	//for(int i = 1;i < ROWS-2;i++){
		//for(int j = 1;j < COLS-2;j++){
			//board[i][j] = BLANK;
			//cout << board[i][j];
		//} 
	//}

}