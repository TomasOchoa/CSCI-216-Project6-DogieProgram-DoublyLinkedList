// CSCI 216 Fundamentals of Prgoramming II Spring 2015
// Program #6: Doubly Linked List
// Author: Tomas Ochoa
// Due Date: 3/23/2015

// The object of this program is to implement a doggie game using
// a doubly linked list. This file is the node class header 

#ifndef __node_h
#define __node_h

class node
{
	public:
		node();
		node(char*);
		~node();
		void print();
		friend class Dlist;
	private:
		char *data;
		node *next;
		node *prev;
		friend class Dlist;
};

#endif // end the defintion of __node_h
