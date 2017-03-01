// lab.cpp
// Purpose: To implement the Lab class for the lab manager for student names.
// By:
// Date:
//
#include "lab.h"
#include <iostream>
#include <fstream>
using namespace std;
// lab enrollment management program
// simple menu to manage enrollments for labs

// ========= START OF PROGRAM THAT USES CLASS Lab ==========================


// ========= CODE FOR MEMBER FUNCTIONS FOR CLASS Lab =======================

// init -- set all slots in list to the empty string ( "" , not " " )
Lab::Lab()
{	LAB_SPACE = 5;
	used = 0;
	names = new string[capacity];
	for( int i = 0 ; i < LAB_SPACE ; i++ )
		names[i] = BLANK;
}

// print -- print out all non-empty items in the list, on separate lines
void Lab::print()
{
	for( int i = 0 ; i < LAB_SPACE ; i++ )
		if ( names[i] != BLANK )
			cout << names[i] << endl;
}

//
// add -- add a name to the list if not already there
//        idea: check first to see if name is in list
//             if so, return false
//        then: add new name at first blank spot
//
// rets: true if added, false if did not add
//
bool Lab::add(string s)
{
	if ( is_in(s) )
		return false;

	for( int i = 0 ; i < LAB_SPACE ; i++ )
		if ( names[i] == BLANK ){
			names[i] = s;
			used++;		// this is where used be used
			return true;
		}
	return false;			// else we did not
}
int Lab::get_count()
{
	return used;
}
//
// is_in -- search list for a name
//          return true if found, false if not
//
bool Lab::is_in(string s)
{
	for ( int i = 0 ; i < LAB_SPACE ; i++ )
		if ( names[i] == s )
			return true;
	return false;
}
//
//  set_title  -- a mutator that sets a private data member
//, get_title, get_capacity -- accessors that return private data values
//
void Lab::set_title(string t)
{
	title = t;
}
string Lab::get_title()
{
	return title;
}
int Lab::get_capacity()
{
	return LAB_SPACE;
}
//  drop -- remove a name from the list
//          find string, replace with ""
//  rets:   true if found and removed it
//          false otherwise
//
bool Lab::drop(string s)
{
	for( int i = 0 ; i < LAB_SPACE ; i++ )
		if ( names[i] == s ){
			names[i] = BLANK;
			used--;		// this is where used be used
			return true;
		}
	return false;
}


void Lab::expand()
{
	
	
	
	
}


