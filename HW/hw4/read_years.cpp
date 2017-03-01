//
//      read_years.cpp - demo of sentinel
//      This function first reads the data(the year) and then
//	gives out the average value of those years
//
//      created by :Rui Qin
//      date: 2/22/2016

#include <iostream>
using namespace std;

const int SPACE = 1000;
const int SENTINEL = -1;

/////////////////////////////////////////////////////////////////////////
///////////////////////////   Interfaces  ///////////////////////////////
/////////////////////////////////////////////////////////////////////////

// print a sequence of numbers
// terminated by a sentinel
void print_seq(int nums[]);

// returns the average (mean) value
// of the integers in the sequence
double average(int nums[]);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////   Client  /////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int main() {
        int years[SPACE];
        int pos = 0;
        int y;
        double avg;

        do {
                if (pos < SPACE) {
                        cin >> y;
                        years[pos++] = y;
                } else {
                        cout << "too much input" << endl;
                        return 1;
                }
        } while (y != SENTINEL); // this part reads in all the data
        // until it hits a SENTINEL

        print_seq(years);
        avg = average(years);
        cout << "avg = " << avg << endl;

        return 0;
}

/////////////////////////////////////////////////////////////////////////
///////////////////////////   Abstraction ///////////////////////////////
///////////////////////////     Barrier   ///////////////////////////////
/////////////////////////////////////////////////////////////////////////

//////////////////////////  Implementations /////////////////////////////

// print a sequence of numbers
// terminated by a sentinel
void print_seq(int nums[SPACE]) {
        int pos = 0;
        while (nums[pos] != SENTINEL) {
                cout << pos << " " << nums[pos] << endl;
                pos++;
        }
}

// returns the average (mean) value
// of the integers in the sequence
double average(int nums[SPACE]) {
        int i = 0;
        int total = 0;
        double average;
        while ((i < SPACE) && (nums[i] != SENTINEL)) {
                total = total + nums[i];
                i = i + 1;
        }
        average = (double)total / i;
        return average;
        // your code here (remove this line and the line above this line)
}
