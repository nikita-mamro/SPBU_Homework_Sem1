#include "Test.hpp"

void askForTests()
{
	printf("Вы уверены, что хотите проводить тесты?\nОни стирают данные из файла справочника, если у вас таковой имеется.\n");
	srand(time(nullptr));
	int key = (rand() % 1000 + 1) * (rand() % 1000 + 1);
	int input = 0;
<<<<<<< HEAD
	printf("������� ���� %d ��� ������������� ������ ������ ��� ������������\n", key);
	printf("������� ����� ������ ����� ��� ������� ��� ������������\n");
	printf("�������� �����... ");
=======
	printf("Введите ключ %d для подтверждения начала тестов: ", key);
>>>>>>> 2f9920987912b902f4cbbe7e1d604a0c2618cdd2
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
<<<<<<< HEAD
		printf("������ � readFromFile()!\n");
		printf("�������� ����� name 8888, ����������: %s %s\n", contactsFileBufferTest[0].name, contactsFileBufferTest[0].phone);
		return false;
	}

	if (strcmp(getName(phone), name) != 0)
	{
		printf("������ � getName()!\n");
		printf("�������� ����� name, ����������: %s\n", getName(phone));
		return false;
	}

	if (strcmp(getPhoneNumber(name), phone) != 0)
	{
		printf("������ � getPhoneNumber()!\n");
		printf("�������� ����� 8888, ����������: %s\n", getPhoneNumber(name));
=======
		printf("Ошибка в readFromFile()!\n Неверно считываются данные!\n");
		printf("Ожидался ответ name 8888, полученный: %s %s\n", contactsFileBufferTest[0].name, contactsFileBufferTest[0].phone);
>>>>>>> 2f9920987912b902f4cbbe7e1d604a0c2618cdd2
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
