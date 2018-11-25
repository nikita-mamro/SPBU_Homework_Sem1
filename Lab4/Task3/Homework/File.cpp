#include "File.hpp"
#include "stdafx.hpp"

int readFromFile(Contact* contactsList)
{
	int linesRead = 0;
	int contactIndex = 0;

	FILE *file = new FILE;
	if ((file = fopen("phonebook.txt", "r")) == NULL)
	{
		file = fopen("phonebook.txt", "w");
		fclose(file);
		file = fopen("phonebook.txt", "r"); 
	}

	while (!feof(file))
	{
		char *buffer = new char[MAX_LENGTH];
		const int readBytes = fscanf(file, "%s", buffer);
		if (readBytes < 0)
		{
			delete[] buffer;
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
		delete[] buffer;
	}

	fclose(file);

	return linesRead;
}
