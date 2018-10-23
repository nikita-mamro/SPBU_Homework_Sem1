#include "Phonebook.hpp"
#include "File.hpp"

void printAll(Contact *contactsList)
{
	printf("Содержимое справочника:\n");
	int numberOfContacts = readFromFile(contactsList) / 2;
	for(int i = 0; i < numberOfContacts; ++i)
	{
		printf("%s %s\n", contactsList[i].name, contactsList[i].phone);
	}
}

void getPhoneNumber(char * name)
{

}

void getName(int phoneNumber)
{

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
