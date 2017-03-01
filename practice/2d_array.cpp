#include<iostream>
#include<cstdlib>

using namespace std;

const int ROWS = 3;
const int COLS = 6;
const int SLEEP_TIME = 100000;

void clear(); // clears the screen
void initialize_box(char array[][COLS], int rows, int cols, char ch);
void print_box(char array[][COLS], int rows, int cols);
void reverse_walk(char array[][COLS], int rows, int cols);

int main()
{
        char xbox[ROWS][COLS];
        
        // initialize
        initialize_box(xbox,ROWS,COLS,'.'); // initialize with spaces
        
        reverse_walk(xbox,ROWS,COLS);
        
        return 0;
}

// purpose: walk Xs from the bottom right, move left,
//          then up, in a zig-zag pattern
// arguments: an array with COLS columns, and two
//            ints for the number of rows and columns
// return value: none
void reverse_walk(char array[][COLS],int rows, int cols)
{
        for (int r=rows-1; r >= 0; r--) {
                for (int c=cols-1; c >= 0; c--) {
                        array[r][c] = 'X';
                        print_box(array,rows,cols);
                        //usleep(SLEEP_TIME);
                }
        }
}

// purpose: walk from the bottom right, move left,
//          then up, in a zig-zag pattern
// arguments: an array with COLS columns, two
//            ints for the number of rows and columns,
//            and a character for initialization
// return value: none
void initialize_box(char array[][COLS], int rows, int cols, char ch)
{
      for (int r=0; r < rows; r++) {
                for (int c=0; c < cols; c++) {
                        array[r][c] = ch; // the character
                }
        }  
}

// purpose: clear the screen and
//          print the array to the screen
// arguments: an array with COLS columns, two
//            ints for the number of rows and columns,
// return value: none
void print_box(char array[][COLS], int rows, int cols)
{
        clear();
        for (int r=0; r < rows; r++) {
                for (int c=0; c < cols; c++) {
                        cout << array[r][c];
                }
                cout << endl;
        }
}

// purpose: clear the screen and return cursor to top left
// arguments: none
// return value: none
void clear()
{
        // this is the character sequence that clears
        // the screen and returns the cursor to the top
        // left of the screen
        cout << "\033[H\033[2J";
}