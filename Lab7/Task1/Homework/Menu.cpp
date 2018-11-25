#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "Menu.hpp"

using namespace std;

void printMenu()
{
	printf("MENU\n");
	printf("--------------------------------------\n");
	printf("ESC - Exit\n");
	printf("1 - Add element\n");
	printf("2 - Delete element\n");
	printf("3 - Check if contained\n");
	printf("4 - Print ascending\n");
	printf("5 - Print descending\n");
	printf("--------------------------------------\n");
}


void solveTask(int choice, Set *set)
{
	int added = 0;
	int deleted = 0;
	int checked = 0;
	switch (choice)
	{
	case 1:
		cout << "Input element to add: ";
		cin >> added;
		add(set, added);
		break;
	case 2:
		cout << "Input element to delete: ";
		cin >> deleted;

		if (remove(set, deleted))
		{
			cout << deleted << " deleted." << endl;
		}
		else
		{
			cout << deleted << " not found :(" << endl;
		}

		break;
	case 3:
		cout << "Input element to check if contained: ";
		cin >> checked;

		if (exists(set, checked))
		{
			cout << checked << " is in the set." << endl;
		}

		else
		{
			cout << checked << " is NOT in the set." << endl;
		}

		break;
	case 4:
		cout << "Set elements in ascending order:" << endl;
		printAscDesc(set, true);
		break;
	case 5:
		cout << "Set elements in descending order:" << endl;
		printAscDesc(set, false);
		break;
	default:
		cout << "Choose an option between 1 and 5" << endl;
		break;
	}
}

void proceedTask()
{
	Set *set = createSet();
	char c = ' ';

	printMenu();

	do {
		c = _getch();
		solveTask(c - '0', set);
	} while (c != 27);

	deleteSet(set);
}