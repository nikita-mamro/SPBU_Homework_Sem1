#include "Test.hpp"

void askForTests()
{
	printf("Вы уверены, что хотите проводить тесты?\nОни стирают данные из файла справочника, если у вас таковой имеется.\n");
	srand(time(nullptr));
	int key = (rand() % 1000) * (rand() % 1000);
	int input = 0;
	printf("Введите ключ %d для подтверждения начала тестов: ", key);
	scanf("%d", &input);
	if (input == key)
	{
		test();
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
	printAll(); // не упало -> ok =)

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