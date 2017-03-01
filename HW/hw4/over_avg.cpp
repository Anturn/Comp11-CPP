//
//      over_avg.cpp
//      This function first reads the data(the year) and then
//	count the average value of them, finally gives out
//	the years that greater than average
//
//      created by :Rui Qin
//      date: 2/22/2016

#include <iostream>
using namespace std;

const int SPACE = 30001;
const int SENTINEL = -1;

int over_average(int nums[], double average);
double average(int nums[]);

int main() {
        int years[SPACE];
        int pos = 0;
        int y;
        int overAverage;
        double avg;

        do {
                if (pos < SPACE) {
                        cin >> y;
                        years[pos++] = y;
                } else {
                        cout << "too much input" << endl;
                        return 1;
                }
        } while (y != SENTINEL);

        avg = average(years);
        overAverage = over_average(years, avg);
        cout <<  overAverage << endl;

        return 0;
}

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
        // The code here is used to count the average value
}

int over_average(int nums[SPACE], double average) {
        int i = 0;
        int j = 0;

        while ((i < SPACE) && (nums[i] != SENTINEL)) {
                if (nums[i] > average) {
                        j = j + 1;
                }

                i = i + 1;
        }
        return j;
}
