//
// cookies.cpp -- dispense cookies
//   input: user specifies a number in range 1..9
//  output: program prints the word cookie that many times
//   

#include <iostream>
using namespace std;

int  get_info();
bool in_range(int);
void repeat  (int);

int main()
{
        int n;

        n = get_info();
        repeat(n);

        return 0;
}

// repeat -- print the word cookie n times
//   arg: number of cookies to print
//
void repeat(int n)
{
        while (n-- > 0)
                cout << "cookie" << endl;
}

// get_info -- require user input in range 1..9
//   rets: an int in range 1..9
int get_info()
{
        int num;

        do {
                cout << "Number (1..9): ";
                cin  >> num ;
        }
        while (in_range(num) == false);
        return num;
}

// in_range -- checks if integer is in range
//    args: an int 
//    rets: true if number is in range 1..9
bool in_range(int n)
{
        if (n < 1)
                cout << "too few" << endl;
        else if (n > 9)
                cout << "too many" << endl;
        else
                return true;

        return false;
}
