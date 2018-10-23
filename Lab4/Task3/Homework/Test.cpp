#include "Test.hpp"

void askForTests()
{
	printf("�� �������, ��� ������ ��������� �����?\n��� ������� ������ �� ����� �����������, ���� � ��� ������� �������.\n");
	srand(time(nullptr));
	int key = (rand() % 1000) * (rand() % 1000);
	int input = 0;
	printf("������� ���� %d ��� ������������� ������ ������: ", key);
	scanf("%d", &input);
	if (input == key)
	{
		test();
	}
}

bool test()
{
	clearTextFile();
	printf("�������� �����!\n");

	Contact contactsMenuBufferTest[BOOK_SIZE];
	int addCounter = 0;
	char* name = "name";
	char* phone = "8888";

	strcpy(contactsMenuBufferTest[0].name, name);
	strcpy(contactsMenuBufferTest[0].phone, phone);
	saveData(contactsMenuBufferTest, 1);
	printAll(); // �� ����� -> ok =)

	Contact contactsFileBufferTest[BOOK_SIZE];
	if (readFromFile(contactsFileBufferTest) != 2)
	{
		printf("������ � readFromFile()! ������� ��������� ������!\n");
		printf("�������� ����� 2, ����������: %d\n", readFromFile(contactsFileBufferTest));
		return false;
	}
	if (strcmp(contactsFileBufferTest[0].name, name) != 0 || strcmp(contactsFileBufferTest[0].phone, phone) != 0)
	{
		printf("������ � readFromFile()!\n");
		return false;
	}
	
	system("cls");
	printf("����� ��������!\n");
	clearTextFile();
	return true;
}

void clearTextFile()
{
	FILE *file = fopen("phonebook.txt", "w");
	fclose(file);
}