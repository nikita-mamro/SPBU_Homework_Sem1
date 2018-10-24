#include "stdafx.hpp"
#include "Menu.hpp"
#include "File.hpp"
#include "Phonebook.hpp"

void printMenu()
{
	printf("����\n");
	printf("--------------------------------------\n");
	printf("ESC - �����\n");
	printf("1 - �������� ������(��� � �������)\n");
	printf("2 - ����������� ��� ��������� ������\n");
	printf("3 - ����� ������� �� �����\n");
	printf("4 - ����� ��� �� ��������\n");
	printf("5 - ��������� ������� ������ � ����\n");
	printf("6 - �������� ����� � ������� ����\n");
	printf("--------------------------------------\n");
	printf("�������� �������� � ����:\n");
	printf("���\n");
	printf("�����\n");
	printf("������������ ����� �����/������ : 30\n");
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
		printf("������� ��� : ");
		scanf("%s", contactsBuffer[addCounter].name);
		printf("������� ����� �������� : ");
		scanf("%s", contactsBuffer[addCounter].phone);
		addCounter++;
		printf("������� � ���������� : %d\n", addCounter);
		break;
	case 2:
		printAll();
		break;
	case 3:
		printf("������� ���: ");
		scanf("%s", name);
		if (getPhoneNumber(name) != NULL)
		{
			printf("�����: %s\n", getPhoneNumber(name));
		}
		else
		{
			printf("��� ����������, ��������� ������������ �������� ������.\n");
		}
		break;
	case 4:
		printf("������� �����: ");
		scanf("%s", phone);
		if (getName(phone) != NULL)
		{
			printf("�����: %s\n", getName(phone));
		}
		else
		{
			printf("��� ����������, ��������� ������������ �������� ������.\n");
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
		printf("�������� ����� �� 1 �� 6\n");
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