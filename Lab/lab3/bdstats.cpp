/*
 * bdstats.cpp  -- compute stats on birthday data
 *
 *   SO FAR
 *	1. read in data
 *	2. then prints out the list with line numbers using another loop
 *      3. Idea: store birthdays as ints.  Example: 1031, 0704
 *
 *   TODO:
 *    [a] change loop to print out only the birthdays in October
 *    [b] after printing out the October bdays, print a count of how many
 *    [c] Move the print/count loop to a function called month_count
 *        declare the function as int month_count(int bd[], int len)
 *        The function should return the count
 *        main should call month_count
 *    [d] modify month_count so it no longer prints the dates and count
 *        and only returns the count.  Then modify main so prints the count.
 *    [e] Modify month_count so it takes a third argument: the month
 *    [f] Have main call month_count with bdays, CAPACITY, and 10
 *    [g] Now have main loop through all 12 months
 *    [h] EXTRA: print which month has the MOST birthdays
 */
#include <iostream>

using namespace std;

const int CAPACITY = 1000 ;		// change as needed

int main() 
{
        int bdays[CAPACITY];	// where values are stored
        int used;		// number of spaces used
        int pos;                // position variable
        int num;
        int num1;

	// read in CAPACITY values, use a while loop
	pos = 0;
        num = 0;
	while( pos < CAPACITY ){
		cin >> bdays[pos];
		pos++;
	}
	used = pos;		// position is how far we got

        // now to print out the list, use a for loop for a change
        for (num1 = 1; num1 < 13 ; num1++){
        for (pos = 0; pos < used ; pos = pos + 1) {


                if (bdays[pos]>100*num1 && bdays[pos]< 100*(num1+1)){
                         num++;      
                }
        }
                cout <<"There are "<< num <<" in "<< num1<<" month" << endl;
                num = 0;
        }

        return 0;
}
