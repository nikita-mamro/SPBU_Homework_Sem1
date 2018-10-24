#pragma once

#include "Menu.hpp"

void printMenu()
{
	printf("МЕНЮ\n");
	printf("--------------------------------------\n");
	printf("ESC - Выйти\n");
	printf("1 – Добавить значение в сортированный список\n");
	printf("2 – Удалить значение из списка\n");
	printf("3 – Распечатать список\n");
	printf("4 - Очистить лог\n");
	printf("--------------------------------------\n");
}


void solveTask(int choice, SortedList &list)
{
	int element = 0;
	switch (choice)
	{
	case 1:
		printf("Введите значение элемента для добавления в список: ");
		scanf("%d", &element);
		addElement(element, list);
		printf("Добавлен элемент %d!\n", element);
		break;
	case 2:
		if (list.count == 0)
		{
			printf("Нечего удалять, список пуст!\n");
			break;
		}
		printf("Введите значение элемента для удаления из списка: ");
		scanf("%d", &element);
		removeElement(element, list);
		break;
	case 3:
		printSortedList(list);
		break;
	case 4:
		system("cls");
		printMenu();
		break;
	default:
		break;
	}
}

void proceedTask()
{
	SortedList list;
	char c;
	printMenu();
	do {
		c = getch();
		solveTask(c - '0', list);
	} while (c != 27);
}
