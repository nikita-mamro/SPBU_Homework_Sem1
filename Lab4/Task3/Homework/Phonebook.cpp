#include "Phonebook.hpp"
#include "File.hpp"

void printAll(Contact* buffer, int numberOfRecords)
{
	Contact contactsList[BOOK_SIZE];
	printf("Содержимое справочника:\n");

	int numberOfContacts = readFromFile(contactsList) / 2;

	if (numberOfContacts == 0)
	{
		printf("Текстовый файл пуст.\n");
	}

	for (int i = 0; i < numberOfContacts; ++i)
	{
		printf("%s %s\n", contactsList[i].name, contactsList[i].phone);
	}

	for (int i = 0; i < numberOfRecords; ++i)
	{
		printf("%s %s\n", buffer[i].name, buffer[i].phone);
	}
}

char* getPhoneNumber(char *name, Contact* buffer, int numberOfRecords)
{
	Contact contactsList[BOOK_SIZE];

	int numberOfContacts = readFromFile(contactsList) / 2;

	for (int i = 0; i < numberOfContacts; ++i)
	{
		if (!strcmp(contactsList[i].name, name))
		{
			return contactsList[i].phone;
		}
	}

	for (int i = 0; i < numberOfRecords; ++i)
	{
		if (!strcmp(buffer[i].name, name))
		{
			return buffer[i].phone;
		}
	}

	return NULL;
}

char* getName(char* phone, Contact* buffer, int numberOfRecords)
{
	Contact contactsList[BOOK_SIZE];

	int numberOfContacts = readFromFile(contactsList) / 2;

	for (int i = 0; i < numberOfContacts; ++i)
	{
		if (!strcmp(contactsList[i].phone, phone))
		{
			return contactsList[i].name;
		}
	}

	for (int i = 0; i < numberOfRecords; ++i)
	{
		if (!strcmp(buffer[i].phone, phone))
		{
			return buffer[i].name;
		}
	}

	return NULL;
}

void saveData(Contact* buffer, int numberOfRecords)
{
	printf("Сохранено записей: %d\n", numberOfRecords);

	FILE *out = fopen("phonebook.txt", "a+");

	for (int i = 0; i < numberOfRecords; ++i)
	{
		printf("Добавляем %s %s...\n", buffer[i].name, buffer[i].phone);
		fprintf(out, "%s\n%s\n", buffer[i].name, buffer[i].phone);
	}

	fclose(out);

	printf("Данные записаны!\n");
}
