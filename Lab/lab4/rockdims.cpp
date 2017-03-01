//
// rockdims.cpp -- analyze height and width of a digital image
//  input has "." background  and "x" for rock
//

#include <iostream>
using namespace std;

const char SPACE = '.';
const char ROCK  = 'x';
const int WIDTH  = 200;
const int HEIGHT = 50;

// declarations go here
// main should be very short, just an outline
void read_asteroids(char asteroids[HEIGHT][WIDTH]);




int main() 
{
        char data[HEIGHT][WIDTH];
        read_asteroids(data);
	
	 
        for (int i = 0; i < HEIGHT ; i++){
                for(int j = 0; j < WIDTH ; j++){
                      cout << data[i][j] ;
		    




}cout << endl;
	}
}
// helper functions go here




void read_asteroids(char asteroids[HEIGHT][WIDTH])
{       
              
 
        for (int i = 0; i < HEIGHT ; i++){
                for(int j = 0; j < WIDTH ; j++){
                        cin >> asteroids[i][j];
                
                }
        }
        


}

//int give_out(char red_asteroids[][WIDTH], int rows,int cols)














