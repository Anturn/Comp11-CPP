#include <iostream>
#include "LinkedList.h"

using namespace std;


// Constructor initializes to an empty list
LinkedList::LinkedList() 
{	
	head = NULL;
     // TODO: Class does together
}


// Inserts the given value at the front of the list
void LinkedList::insert(int num)
{	
	Node *new_node = new Node;
	new_node->data = num;
	new_node->next = head;
	head = new_node;
	// TODO: Class does together
}


// Returns true if the given value is in the list, false otherwise
bool LinkedList::search(int num)
{	
	Node *current = head;
	while(current!=NULL){
		if(current->data == num){
			return true;
		}
		current = current->next;
	
	}
	return false;  // TODO: Class does together
}


// Prints the list to cout
void LinkedList::print()
{	
	Node *current = head;
	while(current!=NULL){
		cout << current->data<<endl;
		current = current->next;
	}
	// TODO: Students write code here
	
}


// Returns the number of elements in the list
int LinkedList::count()
{	
	int count = 0;
	Node *current = head;
	while(current!=NULL){
		count++;
		current = current->next;
	}
		
	return count;  // TODO: Students write code here
}


// Removes the first element with the given value from the list
// If no such element exists, returns false, otherwise returns true
bool LinkedList::remove(int num)
{
	Node *current = head;
	Node *previous = NULL;
	while(current!=NULL){
		if (current->data==num){
			if(previous == NULL){
				head = current->next; 
			}
			previous->next = current->next;
			delete current;
			return true;
		}
		previous = current;
		current = current->next;
	
	}
	return false;  // TODO: Students write code here
}


// Multiplies all elements of the list by the given factor
void LinkedList::mult_all_by(int factor)
{	
	Node *current = head;
	while(current!=NULL){
		current->data = factor*current->data;
		current = current->next;
		
	}
	// TODO: Students write code here
}


// Returns the sum of all elements in the list
int LinkedList::sum()
{	
	int sum = 0;
	Node *current = head;
	while(current!=NULL){
		sum = sum + current->data;
		current = current->next;
		
	}
	return sum; // TODO: Students write code here
}


// destructor deletes the list
LinkedList::~LinkedList()
{
	Node *current = head;
	while(head!=NULL){
		current = head;
		head = head->next;
		delete current;
	}
        // TODO: Students write code here
}


// Reverses the list
void LinkedList::reverse()
{
	
	// TODO: Students write code here
}
