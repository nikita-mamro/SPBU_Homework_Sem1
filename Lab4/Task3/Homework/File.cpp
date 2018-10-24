#include "File.hpp"

void writeToFile(char name[MAX_LENGTH], char phoneNumber[MAX_LENGTH])
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

	FILE *file;
	if ((file = fopen("phonebook.txt", "r")) == NULL)
	{
		file = fopen("phonebook.txt", "a+");// is this КОСТЫЛЬ? hm
		fclose(file);			    // is this КОСТЫЛЬ? hm
		file = fopen("phonebook.txt", "r"); // is this КОСТЫЛЬ? hm
	}

	while (!feof(file))
	{
		char *buffer = new char[MAX_LENGTH];
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
