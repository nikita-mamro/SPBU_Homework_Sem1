#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Menu.hpp"
#include "AVL_Tree.hpp"

using namespace std;

void printMenu()
{
	printf("MENU\n");
	printf("--------------------------------------\n");
	printf("ESC - Exit\n");
	printf("1 - Add element by key\n");
	printf("2 - Get element by key\n");
	printf("3 - Check if key is contained\n");
	printf("4 - Delete by key\n");
	printf("--------------------------------------\n");
}


void solveTask(int choice, Node *node)
{
	switch (choice)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		cout << "Choose an option between 1 and 4" << endl;
		break;
	}
}

void proceedTask()
{
	Node *root = createNode();
	char c = ' ';

	printMenu();

	do {
		c = _getch();
		solveTask(c - '0', root);
	} while (c != 27);
}