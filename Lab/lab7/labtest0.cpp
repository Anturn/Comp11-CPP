#include <iostream>
using namespace std;
//
// labtest0.cpp -- tests a class
//	compile: clang++ -Wall -Wextra labtest0.cpp labcode.o -o labtest0
//
#include "lab.h"

void show(Lab);

int main()
{
	Lab	lab1;

	lab1.init();
	lab1.set_title("Mon 3:30");
	lab1.add("amy") ;
	lab1.add("amy") ;
	lab1.add("bob") ;
	lab1.add("cal") ;
	show(lab1);

	cout << lab1.is_in("amy")  << endl;
	cout << lab1.is_in("alf")  << endl;
	lab1.drop("bob");
	cout << lab1.is_in("bob")  << endl;
	show(lab1);

	lab1.add("jon");
	lab1.add("mel");
	show(lab1);

	// TODO:  drop amy and cal, then add lee, lou, lyn, lex

	// TODO: show the revised list
	return 0;
}
// show -- print out the title, members, and count for a Lab
void show(Lab l)
{
	cout << "List for: " << l.get_title() << endl;
	l.print();
	cout << "total: " << l.get_count() << " / " << l.get_capacity() <<endl;
}
