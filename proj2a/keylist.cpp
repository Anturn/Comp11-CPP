#include <iostream>
#include <fstream>
#include "keylist.h"

using namespace std;

// KeyList()
// Purpose: Constructor, setting up the initial cases
//          where the head and iterator points to NULL
KeyList::KeyList() {
        head = NULL;
        iterator = NULL;
}

// KeyList(std::string keyFile)
// Purpose: Constructor witn input, read file
//          from outside which contains all the
//          keys and setting head and iterator to NULL
// Arguments: the files from outside contains all the keys
//
KeyList::KeyList(std::string keyFile) {
        head = NULL;
        iterator = NULL;
        read_file(keyFile);
}

// ~KeyList()
// Purpose: Destructor, releasing all the memory, or to say,
//          deleting all the linked list at last after the
//          is over
KeyList::~KeyList() {
        Node *current;
        while (head != NULL) {
                current = head;
                head = head->next;
                delete current;
        }
}

Node* KeyList::get_head() {
        return head;
}

// read_file(string keyFile)
// Purpose: Read file from outside and save the information
//          the file contains
//
// Arguments: the files from outside
//
void KeyList::read_file(string keyFile) {
        string line;
        ifstream inputFile(keyFile.c_str());
        if (inputFile.is_open()) {
                while (getline(inputFile, line)) {
                        insert(line);
                }
                inputFile.close();
        }
}

// input: a string, actually a key
// output: none
// purpose: This function insert the string from outside into the
// linked list
void KeyList::insert(std::string k) {
        Node *new_node = new Node;
        new_node->kwr.key = k;
        new_node->next = head;
        head = new_node;
        reset_iterator();
}

// Purpose: to return the next KeyWithResult data in the list
//          After each call to next(), the
//          iterator variable should point
//          to the next node, and NULL if the end of the list
//          has been reached.
// Return value: the KeyWithResult data pointed
//               to by the iterator pointer. If
//               at the end of the list, the
//               word_percentage for the
//               data should be "-1.0"
KeyWithResult KeyList::next() {
        if (iterator == NULL) {
                KeyWithResult last;
                last.word_percentage = -1.0;
                return last;
        }

        KeyWithResult current_ = iterator->kwr;
        iterator = iterator->next;
        return current_;
}

// reset_iterator()
// Purpose: reset the iterator to the head
// of the list to go through the list again
void KeyList::reset_iterator() {
        iterator = head;
}

// update_result()
// Purpose: search through the list and
//          update k's percentage and
//          plaintext
// Arguments: the key to search for in the
//            list, and the percentage value
void KeyList::update_result(std::string k, float percentage,
                            std::string p_text) {
        Node *current = head;
        while (current->kwr.key != k) {
                current = current->next;
        }
        current->kwr.word_percentage = percentage;
        current->kwr.plaintext = p_text;
}
