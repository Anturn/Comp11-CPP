// Rui Qin   1/26/2016
// avg2.cpp -- compute average of three numbers
//             demonstrates:
//		  input, output
//		  variables, assignment
//		  operations: +, / with ints, %, / with floats
//		  comments
// modified by:
//          on:
//

#include <iostream>

using namespace std;

int main()
{
	int     a, b, c;    // creates boxes for ints
	int     sum;        // sum goes here
	int     quotient;
	int     remainder;
	int     num;

	num = 3;            // number of vals to avg

	cout << "Please enter three numbers: ";

	cin  >> a;
	cin  >> b;
	cin  >> c;

	// do the processing part now

	sum = a + b + c;    // add and store

	quotient  = sum / num;
	remainder = sum % num; 

	// output the result as a mixed number

	cout << "The average is " << quotient << " " ;
	cout << remainder << "/" << num << endl;
	cout << "In decimal form: " 
	     << (sum / 3.0) << endl;
}
