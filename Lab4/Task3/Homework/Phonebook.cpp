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

	for(int i = 0; i < numberOfContacts; ++i)
	{
		printf("%s %s\n", contactsList[i].name, contactsList[i].phone);
	}
}

char* getPhoneNumber(char *name)
{
<<<<<<< HEAD
=======
	printf("Введите имя:");
	char *name = new char[MAX_LENGTH] {};
	scanf("%s", name);

>>>>>>> 2f9920987912b902f4cbbe7e1d604a0c2618cdd2
	Contact contactsList[BOOK_SIZE];

	int numberOfContacts = readFromFile(contactsList) / 2;

	for (int i = 0; i < numberOfContacts; ++i)
	{
		if (!strcmp(contactsList[i].name, name))
		{
<<<<<<< HEAD
			return contactsList[i].phone;
		}
	}
	return NULL;
=======
			printf("Найденный номер: %s\n", contactsList[i].phone);
			delete[] name;
			return;
		}
	}
	printf("Нет совпадений\n");
	delete[] name;
>>>>>>> 2f9920987912b902f4cbbe7e1d604a0c2618cdd2
}

char* getName(char* phone)
{
<<<<<<< HEAD
=======
	printf("Введите номер:");
	char *phone = new char[MAX_LENGTH] {};
	scanf("%s", phone);

>>>>>>> 2f9920987912b902f4cbbe7e1d604a0c2618cdd2
	Contact contactsList[BOOK_SIZE];

	int numberOfContacts = readFromFile(contactsList) / 2;

	for (int i = 0; i < numberOfContacts; ++i)
	{
		if (!strcmp(contactsList[i].phone, phone))
		{
<<<<<<< HEAD
			return contactsList[i].name;
		}
	}
	return NULL;
=======
			printf("Найденный человек: %s\n", contactsList[i].name);
			delete[] phone;
			return;
		}
	}
	printf("Нет совпадений\n");
	delete[] phone;
>>>>>>> 2f9920987912b902f4cbbe7e1d604a0c2618cdd2
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
