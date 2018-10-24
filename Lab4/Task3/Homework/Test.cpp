#include "Test.hpp"

void askForTests()
{
	printf("�� �������, ��� ������ ��������� �����?\n��� ������� ������ �� ����� �����������, ���� � ��� ������� �������.\n");
	srand(time(nullptr));
	int key = (rand() % 1000 + 1) * (rand() % 1000 + 1);
	int input = 0;
	printf("������� ���� %d ��� ������������� ������ ������ ��� ������������\n", key);
	printf("������� ����� ������ ����� ��� ������� ��� ������������\n");
	printf("�������� �����... ");
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