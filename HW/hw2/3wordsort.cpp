#include <iostream>

/*
 *   3wordsort.cpp -- program to print out three words in alpha order
 *
 *   usage:  ./3wordsort
 *   input:  three words
 *   output: the three words in alphabetical order, separated by spaces
 *   note:   Do not prompt the user; Do not print explanations on output.
 *           In fact, don't modify main().
 *
 *  modified by: Rui Qin
 *  modified on: 2/3/2016
 */

using namespace std;

void printInOrder(string s1, string s2, string s3);

int main() {
        string w1, w2, w3; // input values

        cin >> w1 >> w2 >> w3;    // read in three values
        printInOrder(w1, w2, w3); // function does not return anything

        return 0;
}

//
// printInOrder() prints out the three words in alpha order
//		  with spaces between them, no return value
//
void printInOrder(string x, string y, string z) {
        if (x <= y &&
            x <= z) { // This part decides the first word among these three.
                cout << x << " ";
        } else if (y <= x && y <= z) {
                cout << y << " ";
        } else if (z <= x && z <= y) {
                cout << z << " ";
        }

        if ((x <= y && x >= z) ||
            (x >= y &&
             x <= z)) { // This part decides the second word among these three.
                cout << x << " ";
        } else if ((y <= x && y >= z) || (y >= x && y <= z)) {
                cout << y << " ";
        } else if ((z <= y && z >= x) || (z >= y && z <= x)) {
                cout << z << " ";
        }

        if (x >= y &&
            x >= z) { // This part decides the third word among these three.
                cout << x << " " << endl;
        } else if (y >= x && y >= z) {
                cout << y << " " << endl;
        } else if (z >= x && z >= y) {
                cout << z << " " << endl;
        }

        // your code here
        // your function does NOT use return
        // Instead, it sends values to cout, separated by spaces
        // followed by an endl.
        // Just print the 3 strings as described in the assignment
        // with no extra stuff.
}
