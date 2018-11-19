#define _CRT_SECURE_NO_WARNINGS
#include "File.hpp"

void readFromFile(List *list)
{
	FILE *file = fopen("phonebook.txt", "r");

	while (!feof(file))
	{
		Contact *contact = new Contact();
		fscanf(file, "%s - %s", contact->name, contact->phone);
		add(list, createNode(*contact));
		delete contact;
	}

	fclose(file);
}