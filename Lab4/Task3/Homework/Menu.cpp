#include "stdafx.hpp"
#include "Menu.hpp"
#include "File.hpp"
#include "Phonebook.hpp"

void printMenu()
{
	printf("МЕНЮ\n");
	printf("--------------------------------------\n");
	printf("ESC - Выйти\n");
	printf("1 - Добавить запись(имя и телефон)\n");
	printf("2 - Распечатать все имеющиеся записи\n");
	printf("3 - Найти телефон по имени\n");
	printf("4 - Найти имя по телефону\n");
	printf("5 - Сохранить текущие данные в файл\n");
	printf("6 - Очистить экран и вывести меню\n");
	printf("--------------------------------------\n");
	printf("Контакты хранятся в виде:\n");
	printf("ИМЯ\n");
	printf("НОМЕР\n");
	printf("Максимальная длина Имени/Номера : 30\n");
	printf("--------------------------------------\n");
}


void solveTask(int choice, Contact* contactsBuffer, int& addCounter)
{
	char* phoneNumber = new char[MAX_LENGTH]{};
	char *name = new char[MAX_LENGTH]{};
	char *phone = new char[MAX_LENGTH] {};

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
		printf("Введите имя: ");
		scanf("%s", name);
		if (getPhoneNumber(name) != NULL)
		{
			printf("Номер: %s\n", getPhoneNumber(name));
		}
		else
		{
			printf("Нет совпадений, проверьте правильность введённых данных.\n");
		}
		break;
	case 4:
		printf("Введите номер: ");
		scanf("%s", phone);
		if (getName(phone) != NULL)
		{
			printf("Имя: %s\n", getName(phone));
		}
		else
		{
			printf("Нет совпадений, проверьте правильность введённых данных.\n");
		}
		break;
	case 5:
		saveData(contactsBuffer, addCounter);
		addCounter = 0;
		break;
	case 6:
		system("cls");
		printMenu();
	default:
		printf("Выберите опцию от 1 до 6\n");
		break;
	}

	delete[] name;
	delete[] phone;
}

void proceedTask()
{
	Contact contactsBuffer[BOOK_SIZE];
	char c;
	int addCounter = 0;
	printMenu();
	do {
		c = getch();
		solveTask(c - '0', contactsBuffer, addCounter);
	} while (c != 27);
}
