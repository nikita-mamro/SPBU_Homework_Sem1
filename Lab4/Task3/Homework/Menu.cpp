#include "Menu.hpp"
#include "File.hpp"

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
	switch (choice) 
	{

	}
}

void proceedTask()
{
	char c;
	do {
		c = getch();
		solveTask(c - '0');
	} while (c != 27);
}