#include "Test.hpp"
#include "stdafx.hpp"
#include "File.hpp"
#include "Menu.hpp"
#include "Phonebook.hpp"

void askForTests()
{
	printf("Вы уверены, что хотите проводить тесты?\nОни стирают данные из файла справочника, если у вас таковой имеется.\n");
	srand(time(nullptr));
	int key = (rand() % 1000 + 1) * (rand() % 1000 + 1);
	int input = 0;
	printf("Введите ключ %d для подтверждения начала тестов для тестирования\n", key);
	printf("Введите любое другое число для запуска без тестирования\n");
	printf("Ожидание ввода... ");
	scanf("%d", &input);
	if (input == key)
	{
		test();
	}
	else
	{
		system("cls");
	}
}

bool test()
{
	clearTextFile();
	printf("Проводим тесты!\n");

	Contact contactsMenuBufferTest[BOOK_SIZE];
	int addCounter = 0;
	char* name = "name";
	char* phone = "8888";

	strcpy(contactsMenuBufferTest[0].name, name);
	strcpy(contactsMenuBufferTest[0].phone, phone);
	saveData(contactsMenuBufferTest, 1);
	printAll(contactsMenuBufferTest, 1); // не упало -> ok =)

	Contact contactsFileBufferTest[BOOK_SIZE];
	if (readFromFile(contactsFileBufferTest) != 2)
	{
		printf("Ошибка в readFromFile()! Неверно считаются строки!\n");
		printf("Ожидался ответ 2, полученный: %d\n", readFromFile(contactsFileBufferTest));
		return false;
	}
	if (strcmp(contactsFileBufferTest[0].name, name) != 0 || strcmp(contactsFileBufferTest[0].phone, phone) != 0)
	{
		printf("Ошибка в readFromFile()!\n");
		printf("Ожидался ответ name 8888, полученный: %s %s\n", contactsFileBufferTest[0].name, contactsFileBufferTest[0].phone);
		return false;
	}

	if (strcmp(getName(phone, contactsMenuBufferTest, 0), name) != 0)
	{
		printf("Ошибка в getName()!\n");
		printf("Ожидался ответ name, полученный: %s\n", getName(phone, contactsMenuBufferTest, 0));
		return false;
	}

	if (strcmp(getPhoneNumber(name, contactsMenuBufferTest, 0), phone) != 0)
	{
		printf("Ошибка в getPhoneNumber()!\n");
		printf("Ожидался ответ 8888, полученный: %s\n", getPhoneNumber(name, contactsMenuBufferTest, 0));
		return false;
	}

	system("cls");
	printf("Тесты пройдены!\n");
	clearTextFile();
	return true;
}

void clearTextFile()
{
	FILE *file = fopen("phonebook.txt", "w");
	fclose(file);
}
