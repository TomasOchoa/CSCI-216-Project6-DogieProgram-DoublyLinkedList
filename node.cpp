// CSCI 216 Fundamentals of Prgoramming II Spring 2015
// Program #6: Doubly Linked List
// Author: Tomas Ochoa
// Due Date: 3/23/2015

// The object of this program is to implement a doggie game using
// a doubly linked list. This file is the node class implementation

#include "node.h"
#include <iostream>
#include <cstring>

using namespace std;

// Constructor without data
node::node()
{
	data = "";
	return;
}
// Constructor with data
node::node(char *s)
{
	data = _strdup(s);
	return;
}
// Default destructor
node::~node()
{	

	return;
}
// Print the data in the node
void node::print()
{
	cout << data;

	return;
}