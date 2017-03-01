// dice_roll.cpp
// Purpose: To play a simple dice game called odd/even/same with one player
//          Two 6-sided dice are rolled, and combine to form a score,
//          as follows: The base score is the sum of the dice. If the dice
//          are both even, the roller gets a 2x bonus (i.e., double the score).
//          If both dice are odd, the roller gets a 3x bonus.
//          If both dice are the same value, the roller gets an additional
//          4x bonus (on top of the other bonuses)
// By:      Rui Qin
// Date:    2/10/2016

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// function definitions
int roll_die(int);
int calc_total(int roll1, int roll2);
void report_score(int roll1, int roll2, int total);

// TODO: Declare calc_total and report_score functions
//       Note: don't forget your argument lists in the function declarations

const int SIDES = 6;

int main() {
        int roll1, roll2, total;

        srand(time(NULL)); // time-based seed
        // srand(1); // simple seed (uncomment to debug program)
        roll1 = roll_die(SIDES);
        roll2 = roll_die(SIDES);

        // TODO: Use the functions defined above to
        // play the game
        total = calc_total(roll1, roll2);
        report_score(roll1, roll2, total);
        return 0;
}

// Purpose: returns a value between 1 and max
// Arguments: the maximum number to return
// Return value: an integer between 1 and max
int roll_die(int max) {
        return rand() % max + 1;
}

// -------------------------------------------------
// TODO: Write calc_total and report_score functions here
//
// The calc_total function takes two integers as arguments (they are
//     the two dice rolls) and returns the total score
//
// The report_score function takes three integers: the two dice rolls
//     and the total score, and prints out the report in the
//     following form:
//        You rolled a 2 and a 2 for a total score of 32.

int calc_total(int roll1, int roll2) {
        int base_score;
        base_score = roll1 + roll2;

        if (roll1 % 2 == 0 && roll2 % 2 == 0) {
                base_score = base_score * 2;
        } else if (roll1 % 2 != 0 && roll2 % 2 != 0) {
                base_score = base_score * 3;
        }

        if (roll1 == roll2) {
                base_score = base_score * 4;
        }

        return base_score;
}

void report_score(int roll1, int roll2, int total) {
        cout << "You rolled a " << roll1 << " and a " << roll2
             << " for a total score"
             << " of " << total << "." << endl;
}
