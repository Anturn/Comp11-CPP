// lab-mgr.cpp
// Purpose: To provide a program that uses the Lab class to implement
//          a lab manager program
// By:
// Date:
#include "lab.h"
#include <fstream> // for handling file input
using namespace std;

// Function declarations
Lab add_from_file(Lab);		// declare this function
void menu();

// Functions
int main()
{
	menu();
	return 0;
}

// basic menu for managing labs
void menu()
{
	Lab	a;
	string	name, choice;

	//a.init(); // This is what i need to delete
	cout << "Title for lab? ";
	cin  >> name;
	a.set_title( name );

	do
	{
		cout << "add, print, search, drop, count, open, quit? " ;
		cin  >> choice;

		switch( choice[0] ){
			case 'a':	cout << "  Name to add? ";
					cin  >> name;
					if ( a.add(name) == true )
						cout << "    ok" << endl;
					else
						cout << "    can't" << endl;
					break;
			case 'd':	cout << "  Name to drop? ";
					cin  >> name;
					if ( a.drop(name) )
						cout << "    ok" << endl;
					else
						cout << "    nope" << endl;
					break;
			case 'p':	cout << "Lab:" << a.get_title() << endl;
					a.print();

			case 'c':	// fall through !!
					cout << a.get_count() << " / " 
					     << a.get_capacity() << endl;
					break;
			case 's':	cout << "  Find what name? ";
					cin  >> name;
					if ( a.is_in( name ) )
						cout << "   yes" << endl;
					else
						cout << "   no" << endl;
					break;
			case 'o':	a = add_from_file(a);
					break;
		}
		cout << endl;
	}
	while( choice[0] != 'q' );
}

// add_from_file
// purp: open a disk file, read names, add those names to a Lab
// args: a Lab to add names to
// rets: the lab with the names added
// errs: if cannot open file, then report and return lab unchanged
// 
Lab add_from_file(Lab list)
{
	ifstream	data;
	string		word;
	string		filename;

	cout << "Read from what file? ";
	cin  >> filename;
	data.open( filename.c_str() );
	if ( ! data.is_open() ){
		cout << "Cannot open " << filename << endl;
		return list;
	}
	while ( data >> word )
		if ( list.add(word) == false )
			cout << "cannot add: " << word << endl;
	data.close();
	return list;
}
