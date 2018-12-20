#define _CRT_SECURE_NO_WARNINGS
#include "File.hpp"

void readFromFile(List *list)
{
	FILE *file = fopen("phonebook.txt", "r");

	Contact *contact = new Contact();

	while (!feof(file))
	{
		fscanf(file, "%s - %s", contact->name, contact->phone);
		add(list, createNode(*contact));
	}

	delete contact;

	fclose(file);
}