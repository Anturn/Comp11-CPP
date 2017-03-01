#include <iostream>
#include "LinkedList.h"
//
// program to test various functions for LinkedList 
//
using namespace std;

void title_print( LinkedList *, string );
void build_list( LinkedList *);
string bool_to_str(bool);

const int INIT_LIST[] = {1,4,-3,7,5,}; // will go into list backwards
const int COUNT = sizeof(INIT_LIST) / sizeof(int);

int main()
{
        LinkedList	list1;		// start with an empty list

        // printing empty list
        title_print( &list1 , "should be empty" );

        build_list(&list1);
        
        // printing the actual list
        title_print( &list1, "should be 5, 7, -3, 4, 1");

        // -- now to test some functions

		cout << endl << "== Testing search() ==" << endl;
		cout << "Searching for 5, -10, 0, 1.  "
			 << "Should be true, false, false, true" << endl;
		cout << bool_to_str(list1.search(5)) << ", "
			 << bool_to_str(list1.search(-10)) << ", "
			 << bool_to_str(list1.search(0)) << ", "
			 << bool_to_str(list1.search(1)) << endl;

        cout << endl << "== Testing sum(), count(), mult_all_by()  ==" << endl;

        cout << "sum of that list is " << list1.sum() << endl;
        cout << "length of that list is " << list1.count() << endl;
        cout << "multiplying all by 3." << endl;
        list1.mult_all_by(3);
        cout << "The new list:" << endl;
        title_print(&list1, "should be 15, 21, -9, 12, 3" );

        cout << endl << "== Testing reverse() ==" << endl;

        list1.reverse();
        title_print( &list1, "should be 3, 12, -9, 21, 15" );

		cout << endl << "== Testing remove() ==" << endl;
		cout << "Removing -9, 15, 12, and 3." << endl;
		list1.remove(-9);
        title_print(&list1, "should be 3, 12, 21, 15" );
		list1.remove(15);
        title_print(&list1, "should be 3, 12, 21" );
		list1.remove(12);
        title_print(&list1, "should be 3, 21" );
		list1.remove(3);
        title_print(&list1, "should be 21" );

        return 0;
}


// print a list with a title
//
void title_print( LinkedList *l, string title )
{
        cout << "Printing list: " << title << endl;
        l->print();
        cout << endl;
}

// Adds values from INIT_LIST to the LinkedList pointed to by l
void build_list( LinkedList *l)
{
        for (int i=0;i<COUNT;i++) {
                l->insert(INIT_LIST[i]);
        }
}

// Converts a boolean to the string "true" or "false"
string bool_to_str(bool b)
{
	if (b) {
		return "true";
    } else {
		return "false";
    }
}
