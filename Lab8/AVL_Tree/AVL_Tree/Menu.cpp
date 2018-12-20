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


void solveTask(int choice, Node *&root)
{
	int key = 0;
	string str;
	switch (choice)
	{
	case 1:
		cout << "Enter the key to be added: ";
		cin >> key;
		cout << "Enter the string: ";
		cin >> str;
		root = add(root, key, str);
		break;
	case 2:
		cout << "Enter the key: ";
		cin >> key;
		cout << "String with key " << key << ": ";
		if (getValue(root, key).empty())
		{
			cout << "String not found by key " << key << endl;
			break;
		}
		cout << getValue(root, key) << endl;
		break;
	case 3:
		cout << "Enter the key to check if it exists: ";
		cin >> key;
		cout << key << (exists(root, key) ? " does " : " does NOT ") << "exist." << endl;
		break;
	case 4:
		cout << "Enter the key to be deleted: ";
		cin >> key;
		root = remove(root, key);
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
		solveTask(c - '0', *&root);
	} while (c != 27);

	deleteTree(root);
}