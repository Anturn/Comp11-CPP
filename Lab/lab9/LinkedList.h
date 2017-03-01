#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
        int data;
        Node *next;
};

class LinkedList {
public:
        LinkedList(); // constructor
        void insert(int);
        bool search(int);
        void print();
        int count();

        bool remove(int);
        void mult_all_by(int);
        int sum();
        ~LinkedList(); // destructor
        void reverse();

private:
        Node *head;
};

#endif
