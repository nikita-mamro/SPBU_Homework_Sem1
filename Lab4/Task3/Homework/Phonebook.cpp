#include "Phonebook.hpp"
#include "File.hpp"

void printAll()
{
	Contact contactsList[BOOK_SIZE];

	printf("���������� �����������:\n");

	int numberOfContacts = readFromFile(contactsList) / 2;

	if (numberOfContacts == 0)
	{
		printf("���������� ����.\n");
		return;
	}

	for(int i = 0; i < numberOfContacts; ++i)
	{
		printf("%s %s\n", contactsList[i].name, contactsList[i].phone);
	}
}

void getPhoneNumber()
{
	printf("������� ���:");
	char *name = new char[MAX_LENGTH] {};
	scanf("%s", name);

	Contact contactsList[BOOK_SIZE];

	int numberOfContacts = readFromFile(contactsList) / 2;

	for (int i = 0; i < numberOfContacts; ++i)
	{
		if (!strcmp(contactsList[i].name, name))
		{
			printf("��������� �����: %s\n", contactsList[i].phone);
			delete[] name;
			return;
		}
	}
	printf("��� ����������\n");
	delete[] name;
}

void getName()
{
	printf("������� �����:");
	char *phone = new char[MAX_LENGTH] {};
	scanf("%s", phone);

	Contact contactsList[BOOK_SIZE];

	int numberOfContacts = readFromFile(contactsList) / 2;

	for (int i = 0; i < numberOfContacts; ++i)
	{
		if (!strcmp(contactsList[i].phone, phone))
		{
			printf("��������� �������: %s\n", contactsList[i].name);
			delete[] phone;
			return;
		}
	}
	printf("��� ����������\n");
	delete[] phone;
}

void saveData(Contact* buffer, int numberOfRecords)
{
	printf("��������� �������: %d\n", numberOfRecords);

	for (int i = 0; i < numberOfRecords; ++i)
	{
		writeToFile(buffer[i].name, buffer[i].phone);
	}

	printf("������ ��������!\n");
}
