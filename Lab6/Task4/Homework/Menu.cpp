#include "stdafx.hpp"
#include "Menu.hpp"
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


void solveTask(int choice, List *list)
{
	switch (choice)
	{
	case 1:
		printList(list);
		break;
	case 2:
		mergeSort(list, 0);
		printf("/n/n");
		printList(list);
		break;
	case 3:
		mergeSort(list, 1);
		printf("/n/n");
		printList(list);
		break;
	default:
		printf("Choose option from 1 to 3\n");
		List *half1 = firstHalf(list);
		printList(half1);
		List *half2 = secondHalf(list);
		printList(half2);
		break;
	}
}

void proceedTask(List *list)
{
	char c = ' ';
	int addCounter = 0;
	printMenu();
	do {
		c = _getch();
		solveTask(c - '0', list);
	} while (c != 27);
}