#include "File.hpp"

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
		string buffer;
		const int readBytes = fscanf(file, "%s", buffer);
		int bufferLength = buffer.length();
		if (readBytes < 0)
		{
			break;
		}
		if (linesRead % 2 == 0)
		{
			copy(0, bufferLength - 1, contactsList[contactIndex].name);
			++linesRead;
		}
		else
		{
			copy(0, bufferLength - 1, contactsList[contactIndex].phone);
			++contactIndex;
			++linesRead;
		}
	}

	fclose(file);

	return linesRead;
}