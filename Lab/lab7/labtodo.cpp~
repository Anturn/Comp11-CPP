# include <iostream>
using namespace std;
//
// labtodo.cpp -- write a class and test the functions
//
//	compile: clang++ -Wall -Wextra labtodo.cpp
//
#include "lab.h"

void show(Lab);
// Function definitions for lab testing
Lab test1(Lab);
Lab test2(Lab);
Lab test3(Lab);
Lab test4(Lab);
Lab test5(Lab);
Lab test6(Lab);

int main()
{
	Lab	lab1;

	cout << "=== Testing init and print" << endl;
	lab1.init();
	lab1.print();
	cout << "--- should have printed nothing" << endl;

	 lab1 = test2(lab1);		// uncomment after doing step 2
	 lab1 = test3(lab1);		// uncomment after doing step 3
	 lab1 = test4(lab1);		// uncomment after doing step 4
	 lab1 = test5(lab1);		// uncomment after doing step 5
	
	return 0;
}
// show -- print out the title, members, and count for a Lab
void Lab::show()
{       
	cout << "List for: " << title << endl;
	print();
	cout << "total: " << get_count() << " / " << get_capacity() <<endl;
}

Lab test2(Lab l)
{
	bool result;
	cout << "======= Test2: Testing add and print ===" << endl;
	cout << "      | add ann, output should be 1, ann " << endl;
	result = l.add("ann");
	cout << result << endl;
	l.print();

	cout << "      | add bev, output should be 1, ann, bev " << endl;
	result = l.add("bev");
	cout << result << endl;
	l.print();

	cout << "      | add ann, output should be 0, ann, bev " << endl;
	result = l.add("ann");
	cout << result << endl;
	l.print();

	cout << "      | add cal, output should be 1, ann, bev, cal " << endl;
	result = l.add("cal");
	cout << result << endl;
	l.print();

	cout << "      | add dan, want: 1, ann, bev, cal, dan " << endl;
	result = l.add("dan");
	cout << result << endl;
	l.print();

	cout <<"      | add eli, want: 1, ann, bev, cal, dan, eli" <<endl;
	result = l.add("eli");
	cout << result << endl;
	l.print();

	cout <<"      | add flo, want: 0, ann, bev, cal, dan, eli" <<endl;
	result = l.add("flo");
	cout << result << endl;
	l.print();

	return l;
}

// tests get_count, is_in
Lab test3(Lab l)
{
	int	num;
	bool	result;
	Lab	temp;

	cout << "======= Test3: Testing get_count, is_in ===" << endl;
	cout << "      | counting list from test2,  want: 5" << endl;
	num = l.get_count();
	cout << num << endl;

	cout << "      | make temp, empty Lab,  want: 0" << endl;
	temp.init();
	num = temp.get_count();
	cout << num << endl;

	cout << "      | add Zach to temp,  want: 1" << endl;
	temp.add("Zach");
	num = temp.get_count();
	cout << num << endl;

	cout << "      | add Ying to temp,  want: 2" << endl;
	temp.add("Ying");
	num = temp.get_count();
	cout << num << endl;

	cout << "      | temp.is_in Zach ,  want: 1" << endl;
	result = temp.is_in("Zach");
	cout << result << endl;

	cout << "      | temp.is_in Zak ,  want: 0" << endl;
	result = temp.is_in("Zak");
	cout << result << endl;

	cout << "      | orig.is_in dan ,  want: 1" << endl;
	result = l.is_in("dan");
	cout << result << endl;

	cout << "      | orig.is_in eli ,  want: 1" << endl;
	result = l.is_in("eli");
	cout << result << endl;

	cout << "      | orig.is_in eva ,  want: 0" << endl;
	result = l.is_in("eva");
	cout << result << endl;
	
	return l;
}
// tests set_title, get_title, get_capacity
Lab test4(Lab l)
{
	Lab	temp;

	cout << "======= Test4: Testing set_title, get_title, get_capacity ==="
	     << endl;
	cout << "      | setting title for orig, want: Wed 3PM" << endl;
	l.set_title("Wed 3PM");
	cout << l.get_title() << endl;

	cout << "      | resetting title for orig, want: Thu 9AM" << endl;
	l.set_title("Thu 9AM");
	cout << l.get_title() << endl;

	cout << "      | setting title for temp, want: Tue 7:30" << endl;
	temp.set_title("Tue 7:30");
	cout << temp.get_title() << endl;

	cout << "      | orig.get_capacity want: 5" << endl;
	cout << l.get_capacity() << endl;

	cout << "      | temp.get_capacity want: 5" << endl;
	cout << temp.get_capacity() << endl;

	cout << "      | temp.init(), temp.get_capacity want: 5" << endl;
	temp.init();
	cout << temp.get_capacity() << endl;

	return l;
}
// tests drop
Lab test5(Lab l)
{
	Lab	temp;
	bool	result;

	cout << "======= Test5: Testing drop, add, count, print ===" << endl;
	cout << "      | drop ann, want: bev cal dan eli 1 4" << endl;
	result = l.drop("ann");
	l.print();
	cout << result << " " << l.get_count() << endl;

	cout << "      | drop ann, want: bev cal dan eli 0 4" << endl;
	result = l.drop("ann");
	l.print();
	cout << result << " " << l.get_count() << endl;

	cout << "      | drop gus, want: bev cal dan eli 0 4" << endl;
	result = l.drop("gus");
	l.print();
	cout << result << " " << l.get_count() << endl;

	cout << "      | drop eli, want: bev cal dan 1 3" << endl;
	result = l.drop("eli");
	l.print();
	cout << result << " " << l.get_count() << endl;

	cout << "      | ** making an empty Lab **" << endl;
	temp.init();

	cout << "      | temp.get_count, want: 0" << endl;
	cout << temp.get_count() << endl;

	cout << "      | temp.drop eli, want: 0 0" << endl;
	result = temp.drop("eli");
	temp.print();
	cout << result << " " << temp.get_count() << endl;

	cout << "      | temp. add ron sue tom, drop sue, add sam " << endl;
	cout << "      |       want ron sam tom 1 3" << endl;
	temp.add("ron");
	temp.add("sue");
	temp.add("tom");
	result = temp.drop("sue");
	temp.add("sam");
	temp.print();
	cout << result << " " << temp.get_count() << endl;

	return l;
}
	
// -------------------------------------------------------------------
// class member functions implementations go here
// Your job: write the code for these functions
// The return values for these functions are phony values: REPLACE THEM
//
// ----- STEP ONE ---------------------------------

//
// init -- set all slots in list to the empty string ( "" , not " " )
void Lab::init()
{
        for(int i=0;i<LAB_SPACE;i++){
                names[i] = "";
        }
}

// print -- print out all non-empty items in the list, on separate lines
void Lab::print()
{
        for (int i=0;i<LAB_SPACE;i++){
                if (names[i] != ""){
                        cout << names[i] << endl;
                }
        }
}

// ----- STEP TWO ---------------------------------
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
        
        for (int i=0;i<LAB_SPACE;i++){
                if (s == names[i]){
                        return false;
                }
        }

        for (int i=0;i<LAB_SPACE;i++){
                if (names[i] ==""){
                        names[i] = s;
                        return true;
                }
	}

	return false;
}
// ----- STEP THREE ---------------------------------
//
//  count -- return number of non-blank items in list
//
int Lab::get_count()
{       
        int count = 0;
        for (int i=0;i<LAB_SPACE;i++){
                if (names[i] !=""){
                        count++;
                }
	}
	return count;
}
//
// is_in -- search list for a name
//          return true if found, false if not
//
bool Lab::is_in(string s)
{
        for (int i=0;i<LAB_SPACE;i++){
                if (names[i] == s){
                        return true;
		}
        }
	return false;
}
// ----- STEP FOUR ---------------------------------
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
	return 0;
}
// ----- STEP FIVE ---------------------------------
//  drop -- remove a name from the list
//          find string, replace with ""
//  rets:   true if found and removed it
//          false otherwise
//
bool Lab::drop(string s)
{
        for(int i=0;i<LAB_SPACE;i++){
                if( names[i] == s){
                        names[i] = "";
                        return true;
                }
        }
	return false;
}
// ----- STEP SIX  ---------------------------------
//  [a] add a show() member function to definition
//  [b] add the show() function code to implementation section

