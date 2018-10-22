#include "Phonebook.hpp"
#include "File.hpp"

void printAll()
{

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
