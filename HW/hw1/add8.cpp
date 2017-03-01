//      add8.cpp
//      purpose: get the sum of 8 floating point numbers
//      created by: Rui Qin
//      date: 1/28/2016

#include <iostream>
using namespace std;

int main() {
        double sum;
        double num1, num2, num3, num4, num5, num6, num7, num8;
        cout << "Please type in eight floating point numbers" << endl;
        cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8;
        sum = num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8;
        cout << "This is the sum of your 8 numbers:\n" << sum << endl;
        return 0;
}
