//      change.cpp
//      purpose: figure out the number of quarters,dims,nickels and pennies to
//      dispense for a specified amount of change
//      created by: Rui Qin
//      date: 1/28/2016
//

#include <iostream>
using namespace std;

int main() {
        int totalChanges;
        int numberOfQuarters;
        int numberOfDime;
        int numberOfNickel;
        int numberOfPenny;

        int moneyLeftAfterQuarters;
        int moneyLeftAfterDime;
        int moneyLeftAfterNickel;

        const int QUARTERS = 25;
        const int DIME = 10;
        const int NICKEL = 5;
        const int PENNY = 1;

        cout << " Amount of change in cents?" << endl;
        cin >> totalChanges;

        numberOfQuarters = totalChanges / QUARTERS;
        moneyLeftAfterQuarters = totalChanges % QUARTERS;

        numberOfDime = moneyLeftAfterQuarters / DIME;
        moneyLeftAfterDime = moneyLeftAfterQuarters % DIME;

        numberOfNickel = moneyLeftAfterDime / NICKEL;
        moneyLeftAfterNickel = moneyLeftAfterDime % NICKEL;

        numberOfPenny = moneyLeftAfterNickel / PENNY;

        cout << numberOfQuarters << " quarters, " << numberOfDime << " dimes, "
             << numberOfNickel << " nickels, " << numberOfPenny << " pennies "
             << endl;
        return 0;
}
