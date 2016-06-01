// CSCI 216 Fundamentals of Prgoramming II Spring 2015
// Program #6: Doubly Linked List
// Author: Tomas Ochoa
// Due Date: 3/23/2015

// The object of this program is to implement a doggie game using
// a doubly linked list. This file is the Doubly linked list class
// implementation

#include "Dlist.h"
#include "node.h"
#include <iostream>
#include <cstring>

using namespace std;

// Default constructor 
// the head of the list points to NULL (empty list)
Dlist::Dlist()
{	
	head->next = head;
	head->prev = head;	
	// head = head;
	// NOTE!!!!
	// head's next pointer is the HEAD OF LIST
	// Head's previous pointer is the TAIL OF LIST
	return;
}
// Default destructor
// While the list is not empty, remove the elements
Dlist::~Dlist()
{
	while (!empty())
	{
		removeFront();
	}
	return;
}
// Check if the list is empty
bool Dlist::empty()
{
	if (head->next == head && head->prev == head)
		return true;
	else
		return false;
}
// Insert node at the front of the list
bool Dlist::insertFront(char *s)
{
	if (empty())		    // if the list is empty
	{
		node *firstNode = new node;
		// Initialize connections for the first node of the list
		firstNode->data = _strdup(s);		// store the data 
		firstNode->next = head;				// make the next pointer point to head
		firstNode->prev = head;				// make the previous pointer point to head
		// make head and tail point to the first node
		//head = firstNode;					
		head->next = firstNode;
		head->prev = firstNode;		
	}
	else
	{
		// Make a new node and put data into it
		node *newNode = new node;
		newNode->data = _strdup(s);			// store the data
		// New node connections
		newNode->next = head->next;			// make the new node's next point to the current head
		newNode->prev = head;				// since in the front the new node's prev is head's previous
		// Make connections for the node after the new node
		head->next->prev = newNode;
		head->next = newNode;
		// make the new node the new head
		//head = newNode;
	}
	return true;
}
// Insert a node at the back of the list
bool Dlist::insertBack(char *s)
{
	if (empty())		    // if the list is empty
	{
		node *firstNode = new node;
		// make head and tail point to the first node
		//head = firstNode;
		head->next = firstNode;
		head->prev = firstNode;
		// Initialize connections for the first node of the list
		firstNode->next = head;				// make the next pointer point to head
		firstNode->prev = head;				// make the previous pointer point to head
		firstNode->data = _strdup(s);		// store the data 
	}
	else
	{
		// Make a new node and put data into it
		node *newNode = new node;
		newNode->data = _strdup(s);
		// make connections for the new node
		newNode->next = head;
		newNode->prev = head->prev;
		// Make connections for the node before the new node
		head->prev->next = newNode;
		head->prev = newNode;		
	}
	return true;
}
// Remove a node from the front of the list
char *Dlist::removeFront()
{
	node *nodeToBeRemovoed;
	char *retVal;

	nodeToBeRemovoed = head->next;
	retVal = nodeToBeRemovoed->data;
	
	nodeToBeRemovoed->next->prev = head;
	head->next = nodeToBeRemovoed->next;

	delete nodeToBeRemovoed;

	return retVal;


}
// Remove a node from the back of the list
char *Dlist::removeBack()
{
	// Variable to put the data from node to be reomved 
	char *retVal;
	
	if (empty())		// no elements
	{
		cout << "removing from an empty list...exiting\n";
		exit(13);
	}
	else
	{
		// Declare a node pointer to remove the back node and set it to the tail
		node *ptr;
		ptr = head->prev;
		retVal = head->prev->data;
		// Change the links
		ptr->prev->next = head;
		head->prev = ptr->prev;
		delete ptr;
	}
	// Return the data
	return retVal;
	
}
// Print the list
void Dlist::print()
{
	node *ptr = new node;
	// Set the ptr to head of list
	ptr = head->next;
	if (ptr == head->prev)
		cout << "The list is empty\n";
	else
	{
		while (ptr != head->prev)
		{
			ptr->print();
			cout << endl;
			ptr = ptr->next;
		}
		cout << ptr->data << endl;
	}
	
	return;
}