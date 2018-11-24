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
	printf("1 - Print list\n");
	printf("2 - Print sorted by name\n");
	printf("3 - Print sorted by number\n");
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
	default:
		
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