// CSCI 216 Fundamentals of Prgoramming II Spring 2015
// Program #6: Doubly Linked List
// Author: Tomas Ochoa
// Due Date: 3/23/2015

// The object of this program is to implement a doggie game using
// a doubly linked list. This file is the doubly linked list 
// definition. This definition of the doubly linked list uses
// node class.

#ifndef __Dlist_h
#define __Dlist_h

#include "node.h";

class Dlist
{
	public:
		Dlist();
		~Dlist();
		bool empty();
		bool insertFront(char *);
		bool insertBack(char *);
		char *removeFront();
		char *removeBack();
		void print();
	//private:
		node* head = new node;
};


#endif // End the __Dist_h definition if not already defined
