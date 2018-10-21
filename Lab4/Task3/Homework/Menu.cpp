#include "Menu.hpp"
#include "File.hpp"

void printMenu()
{
	printf("МЕНЮ\n");
	printf("--------------------------------------\n");
	printf("ESC - выйти\n");
	printf("1 - добавить запись(имя и телефон)\n");
	printf("2 - распечатать все имеющиеся записи\n");
	printf("3 - найти телефон по имени\n");
	printf("4 - найти имя по телефону\n");
	printf("5 - сохранить текущие данные в файл\n");
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