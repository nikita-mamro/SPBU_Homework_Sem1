#include "stdafx.hpp"
#include "Menu.hpp"
#include "File.hpp"
#include "ContactStruct.hpp"

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
	case 4:
		system("cls");
		break;
	default:
		printf("Choose option from 1 to 4\n");
		break;
	}
}

void proceedTask()
{
	char c = ' ';
	int addCounter = 0;
	printMenu();
	do {
		c = getch();
		solveTask(c - '0');
	} while (c != 27);
}