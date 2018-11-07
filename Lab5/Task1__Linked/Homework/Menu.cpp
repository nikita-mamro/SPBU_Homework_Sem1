#pragma once
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include "Menu.hpp"

void printMenu()
{
	printf("����\n");
	printf("--------------------------------------\n");
	printf("ESC - �����\n");
	printf("1 � �������� �������� � ������������� ������\n");
	printf("2 � ������� �������� �� ������\n");
	printf("3 � ����������� ������\n");
	printf("4 - �������� ���\n");
	printf("--------------------------------------\n");
}

void solveTask(int choice, SortedList &list)
{
	int element = 0;
	switch (choice)
	{
	case 1:
		printf("������� �������� �������� ��� ���������� � ������: ");
		scanf("%d", &element);
		addElement(element, list);
		break;
	case 2:
		if (list.head == nullptr)
		{
			printf("������ �������, ������ ����!\n");
			break;
		}
		printf("������� �������� �������� ��� �������� �� ������: ");
		scanf("%d", &element);
		removeElement(element, list);
		break;
	case 3:
		printSortedList(list);
		break;
	case 4:
		system(CLEAR);
		printMenu();
		break;
	default:
		break;
	}
}

void proceedTask()
{
	SortedList *list = new SortedList;
	char c = ' ';
	printMenu();
	do {
		c = getch();
		solveTask(c - '0', *list);
	} while (c != 27);
	deleteSortedList(*list);
}