// CSCI 216 Fundamentals of Prgoramming II Spring 2015
// Program #6: Doubly Linked List
// Author: Tomas Ochoa
// Due Date: 3/23/2015

// The object of this program is to implement a doggie game using
// a doubly linked list. This file is the main function

#include "Dlist.h"

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
	Dlist stack;
	char name[120];
	char food[120];
	bool eating = true;
	bool grass = false;

	cout << "Hi, what is your doggie's name \n";
	cin.getline(name, 119);
	while (eating)
	{
		// eat
		while (!grass)
		{
			cout << "What does " << name << " eat? \n";
			cin.getline(food, 119);
			if (!strcmp(food, "grass"))
			{
				cout << "Oh, no, it looks like " << name <<" is getting sick! Ick...\n";
				break;
			}
			else if (!strcmp(food, "dog food"))
			{
				eating = false;
				break;
			}
			stack.insertBack(food);
		}
		// barf
		while (!stack.empty() && eating)
		{
			cout << name << " barfs up " << stack.removeBack() << endl;
			if (stack.empty())
				cout << "It looks like " << name << " is feeling better now...\n";
		}
	}
	cout << "Ugh! " << name << " is insulted and walks away in a huff!!!\n";
	
    system("Pause");
	return 0;
}

/*
---------------------------- PROGRAM OUTPUT---------------------------
Hi, what is your doggie’s name?
Bozo
What does Bozo eat?
a loaf of bread
What does Bozo eat?
a garbage truck
What does Bozo eat?
three clouds
What does Bozo eat?
grass
Oh, no, it looks like Bozo is getting sick!  Ick...
Bozo barfs up three clouds
Bozo barfs up a garbage truck
Bozo barfs up a loaf of bread
It looks like Bozo is feeling better now...
What does Bozo eat?
dog food
Ugh!  Bozo is insulted and runs away in a huff!
Press any key to continue...

-----------------------------------------------------------------------
*/