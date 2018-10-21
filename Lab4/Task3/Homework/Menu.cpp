#include "stdafx.hpp"
#include "Menu.hpp"
#include "File.hpp"
#include "Phonebook.hpp"
#include "ContactStruct.hpp"

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


void solveTask(int choice)
{
	Contact contactsBuffer[100];
	int counter = 0;
	int phoneNumber = 0;
	char *name = new char[50]{};
	switch (choice) 
	{
	case 1:
		printf("������� ��� : ");
		scanf("%s", contactsBuffer[counter].name);
		printf("������� ����� �������� : ");
		scanf("%s", contactsBuffer[counter].phone);
		counter++;
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
		saveData(contactsBuffer, counter);
		break;
	default:
		printf("�������� ����� �� 1 �� 5\n");
		break;
	}
	delete[] name;
}

void proceedTask()
{
	char c;
	do {
		c = getch();
		solveTask(c - '0');
	} while (c != 27);
}