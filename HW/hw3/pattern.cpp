//      This function means to draw the picture.
//      The  input taken as" First string" as the mark
//      the user want to see and the "Second string" as
//      the second string user wants to put. And the
//      "Width" as the maximum elements in first row,
//      which will decrease by two each time later
//
//      created by :Rui Qin
//      date: 2/10/2016

#include <iostream>
using namespace std;

void draw_picture(string A, string B, int Width);

int main() {
        string StringA, StringB;
        int Width;

        cout << "First string?";
        cin >> StringA;

        cout << "Second string?";
        cin >> StringB;

        cout << "Width?";
        cin >> Width;

        draw_picture(StringA, StringB, Width);
        return 0;
}

void draw_picture(string A, string B, int Width) {
        int n, m, i, j, a, b, v,
            num_row; // The integral variables here are used in loop

        if (Width % 2 != 0) { // The case when width is odd
                num_row = (Width + 1) / 2;
                v = 1;
        } else { // The case when width is even
                num_row = (Width + 2) / 2;
                v = 0;
        }

        for (m = 1; m <= num_row; m++) {
                // The outer loop gets the row in first part
                for (n = 1; n <= Width - 2 * (m - 1); n++) {
                        // The inner loop here to draw the string1
                        cout << A;
                }
                for (i = 1; i <= 2 * (m - 1); i++) {
                        // The inner loop here to draw the string2
                        cout << B;
                }
                cout << "\n"; // a new line
        }

        for (j = 1; j <= num_row - 1; j++) {
                // The outer loop gets the row in second part
                for (a = 1; a <= 2 * j + v; a++) {
                        // The inner loop here to draw the string1
                        cout << A;
                }
                for (b = 1; b <= Width - 2 * j - v; b++) {
                        // The inner loop here to draw the string2
                        cout << B;
                }
                cout << "\n"; // a new line
        }
}
