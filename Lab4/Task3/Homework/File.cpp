#include "File.hpp"

void writeToFile(char name[30], char phoneNumber[30])
{
	printf("Добавляем %s %s...\n", name, phoneNumber);
	FILE *out = fopen("phonebook.txt", "a+");
	fprintf(out, "%s\n%s\n", name, phoneNumber);
	fclose(out);
}

Contact *readFromFile()
{
	Contact contactsList[100];
	return contactsList;
}
