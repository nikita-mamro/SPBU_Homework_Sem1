#include "stdafx.hpp"
#include "Menu.hpp"
#include "File.hpp"
#include "Phonebook.hpp"

void printMenu()
{
	printf("МЕНЮ\n");
	printf("--------------------------------------\n");
	printf("ESC - выйти\n");
	printf("1 - добавить запись(имя и телефон)\n");
	printf("2 - распечатать все имеющиеся записи\n");
	printf("3 - найти телефон по имени\n");
	printf("4 - найти имя по телефону\n");
	printf("5 - сохранить текущие данные в файл\n");
	printf("--------------------------------------\n");
}


void solveTask(int choice, Contact* contactsBuffer, int& addCounter)
{
	int phoneNumber = 0;
	char *name = new char[50]{};
	switch (choice) 
	{
	case 1:
		printf("Введите имя : ");
		scanf("%s", contactsBuffer[addCounter].name);
		printf("Введите номер телефона : ");
		scanf("%s", contactsBuffer[addCounter].phone);
		addCounter++;
		printf("Записей к сохранению : %d\n", addCounter);
		break;
	case 2:
		printAll();
		break;
	case 3:
		printf("Введите имя : ");
		scanf("%s", name);
		getPhoneNumber(name);
		break;
	case 4:
		printf("Введите номер телефона : ");
		scanf("%d", &phoneNumber);
		getName(phoneNumber);
		break;
	case 5:
		saveData(contactsBuffer, addCounter);
		addCounter = 0;
		break;
	default:
		printf("Выберите опцию от 1 до 5\n");
		break;
	}
	delete[] name;
}

void proceedTask()
{
	Contact contactsBuffer[100];
	char c;
	int addCounter = 0;
	do {
		c = getch();
		solveTask(c - '0', contactsBuffer, addCounter);
	} while (c != 27);
	delete[] contactsBuffer;
}