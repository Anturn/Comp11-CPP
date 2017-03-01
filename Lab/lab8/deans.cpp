#include <iostream>
#include <cctype>
using namespace std;

// deans.cpp -- separate students by dean
//  input: list of names read from cin
// output: lists for each dean sent to cout
//   idea: use the Lab class to store each of the lists

int main()
{
	Lab	lists[4];
	string	name;
	char	first_lett;

	lists[0].init();	lists[0].set_title("Jason Rife");
	lists[1].init();	lists[1].set_title("Jean Herbert");
	lists[2].init();	lists[2].set_title("Carol Baffi-Dugan");
	lists[3].init();	lists[3].set_title("Odd-names");

	while( cin >> name )
	{
		first_lett = tolower( name[0] );
		if ( first_lett >= 'a' && first_lett <= 'g' )
			lists[0].add(name);
		else if ( first_lett >= 'h' && first_lett <= 'o' )
			lists[1].add(name);
		else if ( first_lett >= 'o' && first_lett <= 'z' )
			lists[2].add(name);
		else
			lists[3].add(name);
	}
	for( int i = 0 ; i < 4; i++ ){
		cout << "List for Dean " << lists[i].get_title() << endl;
		lists[i].print();
		cout << "TOTAL " << lists[i].get_count() << "/"
		     << lists[i].get_capacity() << endl;
	}
}
