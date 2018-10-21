#include "File.hpp"

void writeToFile(char name[30], char phoneNumber[30])
{
	FILE *out = fopen("phonebook.txt", "w");
	fwrite(name, sizeof(name), 1, out);
	fwrite(" ", sizeof(" "), 1, out);
	fwrite(&phoneNumber, sizeof(phoneNumber), 1, out);
	fwrite("\n", sizeof("\n"), 1, out);
	fclose(out);
}

void readFromFile()
{

}
