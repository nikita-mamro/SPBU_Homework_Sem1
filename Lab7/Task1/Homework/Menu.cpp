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


void solveTask(int choice)
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
	case 5:

		break;

	default:
		cout << "Choose an option between 1 and 5" << endl;
		break;
	}
}

void proceedTask()
{
	char c = ' ';
	printMenu();
	do {
		c = _getch();
		solveTask(c - '0');
	} while (c != 27);
}