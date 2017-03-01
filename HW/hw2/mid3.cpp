#include <iostream>

/*
 *   mid3.cpp -- program to print out the middle of three input values
 *
 *   usage:  ./mid3
 *   input:  three doubles
 *   output: the middle of the three input values
 *   note:   Do not prompt the user, do not print explanations on output.
 *           In fact, do not change main() at all, and don't use cin or
 *           cout in mid3().
 *
 *  modified by: Rui Qin
 *  modified on: 2/3/2016
 */

using namespace std;

double mid3(double n1, double n2, double n3); // tell compiler about this

int main() {
        // NOTE: DO NOT CHANGE ANYTHING IN main()!
        double a, b, c; // input values
        double middle;  // result

        cin >> a >> b >> c; // read in three values

        middle = mid3(a, b, c); // compute the middle

        cout << middle << endl; // display it on the screen

        return 0;
}

//
// mid3() return the middle of three values passed as arguments
//
double mid3(double n1, double n2, double n3) {
        double midn;

        if ((n1 >= n2 && n1 <= n3) || (n1 <= n2 && n1 >= n3)) {
                midn = n1; // This line decides whether n1 is the middle number
        }

        if ((n2 >= n1 && n2 <= n3) || (n2 <= n1 && n2 >= n3)) {
                midn = n2; // This line decides whether n2 is the middle number
        }

        if ((n3 >= n1 && n3 <= n2) || (n3 <= n1 && n3 >= n2)) {
                midn = n3; // This line decides whether n3 is the middle numer
        }

        return midn; // This line is used to return the value

        // your code starts here!
        // your function MUST use return to send back the
        // middle value of the three values passed in
}
