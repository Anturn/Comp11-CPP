//iftest.cpp
//      purpose: report number of digits in an integer
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//
//  modified by: Rui Qin
//         date:1/27/2016
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int input;

	cout << "Enter a number: ";
	cin  >> input;

	if (abs(input) >= 100) {
		cout << "input has three or more digits" << endl;
	} else if ( abs(input) >= 10){
		cout << "input has two digits" << endl;
	} else if ( abs(input) > 0){
		cout << "input has one digit" << endl;
	} else {
                cout << "input is 0" <<endl;

        } 
        if (input <0){
                cout << "and input is negative"<<endl;
        }

        return 0;
        
}

