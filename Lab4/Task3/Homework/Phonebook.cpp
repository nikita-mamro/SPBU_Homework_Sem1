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

void saveData(Contact *buffer, int numberOfRecords)
{
	for (int i = 0; i < numberOfRecords; ++i)
	{
		writeToFile(buffer[i].name, buffer[i].phone);
		printf("%s hello %s", buffer[i].name, buffer[i].phone);//ничего
	}
	printf("%s hello %s", buffer[0].name, buffer[0].phone);//много ММММ....
	printf("Данные записаны!\n");
}
