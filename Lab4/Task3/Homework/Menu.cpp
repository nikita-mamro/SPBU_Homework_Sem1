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
	printf("--------------------------------------\n");
}


void solveTask(int choice, Contact* contactsBuffer, int& addCounter)
{
	int phoneNumber = 0;
	char *name = new char[50]{};
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
		printf("������� ��� : ");
		scanf("%s", name);
		getPhoneNumber(name);
		break;
	case 4:
		printf("������� ����� �������� : ");
		scanf("%d", &phoneNumber);
		getName(phoneNumber);
		break;
	case 5:
		saveData(contactsBuffer, addCounter);
		addCounter = 0;
		break;
	default:
		printf("�������� ����� �� 1 �� 5\n");
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