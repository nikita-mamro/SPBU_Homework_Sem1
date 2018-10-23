#include "File.hpp"

void writeToFile(char name[30], char phoneNumber[30])
{
	printf("Добавляем %s %s...\n", name, phoneNumber);
	FILE *out = fopen("phonebook.txt", "a+");
	fprintf(out, "%s\n%s\n", name, phoneNumber);
	fclose(out);
}

int readFromFile(Contact* contactsList)
{
	int linesRead = 0;
	int contactIndex = 0;
	FILE *file = fopen("phonebook.txt", "r");
	while (!feof(file))
	{
		char *buffer = new char[30];
		const int readBytes = fscanf(file, "%s", buffer);
		if (readBytes < 0) 
		{
			break;
		}
		if (linesRead % 2 == 0)
		{
			strcpy(contactsList[contactIndex].name, buffer);
			++linesRead;
		}
		else
		{
			strcpy(contactsList[contactIndex].phone, buffer);
			++contactIndex;
			++linesRead;
		}
	}
	fclose(file);
	return linesRead;
}
