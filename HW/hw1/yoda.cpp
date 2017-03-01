//      yoda.cpp
//      purpose: turn your fours words in reverse order
//      created by: Rui Qin
//      date: 1/28/2016
//

#include <iostream>
using namespace std;

int main() {
        string one, two, three, four;

        cout << "Type in four words" << endl;
        cin >> one;
        cin >> two;
        cin >> three;
        cin >> four;
        cout << "These are your reverse words:\n" << four << " " << three << " "
             << two << " " << one << endl;
        return 0;
}
