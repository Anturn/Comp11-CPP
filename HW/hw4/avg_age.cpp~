/*
 * avg_age.cpp
 * purpose: read the years of birth and the name, give out the
 * average ages of the specific name given by the user
 *      by: Rui Qin
 *      date:2/22/2016
 */

#include <iostream>
using namespace std;

const int SPACE_YEARS = 50001;
const int SPACE_NAMES = 50001;
const int SENTINEL = -1;
const int YEAR = 2016;

double average_age(string name_given, int years[], string names[]);
bool name_existed(string name_given, int years[], string names[]);
void printout(string name_given, int years[], string names[]);

int main() {
        int years[SPACE_YEARS];
        string names[SPACE_NAMES];
        int pos = 0;

        int y;
        string data_name;
        string name_given;

        do {
                if (pos < SPACE_YEARS) {
                        cin >> y;
                        cin >> data_name;
                        years[pos] = y;
                        names[pos++] = data_name;
                } else {
                        cout << "too much data" << endl;
                        return 1;
                }
        } while (y != SENTINEL);

        cout << "Enter a name" << endl;
        cin >> name_given;

        printout(name_given, years, names);
        return 0;
}

double average_age(string name_given, int years[SPACE_YEARS],
                   string names[SPACE_NAMES]) {
        int i = 0;
        int j = 0;
        int sum = 0;
        double average;

        while ((i < SPACE_NAMES) && (years[i] != SENTINEL)) {
                if (name_given == names[i]) {
                        sum = sum + (YEAR - years[i]);
                        j = j + 1;
                }
                i = i + 1;
        }
        average = double(sum) / j;
        return average;
}

bool name_existed(string name_given, int years[SPACE_YEARS],
                  string names[SPACE_NAMES]) {
        int i = 0;

        while ((i < SPACE_NAMES) && (years[i] != SENTINEL)) {
                if (name_given == names[i]) {
                        return true;
                }
                i++;
        }
        return false;
}

void printout(string name_given, int years[], string names[]) {
        double average;
        bool boolean;

        boolean = name_existed(name_given, years, names);
        average = average_age(name_given, years, names);
        if (boolean == false) {
                cout << "name not found" << endl;
        } else {
                cout << "average age = " << average << endl;
        }
}