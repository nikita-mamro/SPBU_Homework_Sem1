#include "Phonebook.hpp"
#include "File.hpp"

void printAll()
{
	Contact contactsList[BOOK_SIZE];
	printf("Содержимое справочника:\n");

	int numberOfContacts = readFromFile(contactsList) / 2;

	if (numberOfContacts == 0)
	{
		printf("Справочник пуст.\n");
		return;
	}

	for (int i = 0; i < numberOfContacts; ++i)
	{
		printf("%s %s\n", contactsList[i].name, contactsList[i].phone);
	}
}

char* getPhoneNumber(char *name)
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
	return NULL;
}

char* getName(char* phone)
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
	return NULL;
}

void saveData(Contact* buffer, int numberOfRecords)
{
	printf("Сохранено записей: %d\n", numberOfRecords);

	for (int i = 0; i < numberOfRecords; ++i)
	{
		writeToFile(buffer[i].name, buffer[i].phone);
	}

	printf("Данные записаны!\n");
}
