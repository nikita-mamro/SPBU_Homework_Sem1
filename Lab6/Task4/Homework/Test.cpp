#define _CRT_SECURE_NO_WARNINGS
#include "Test.hpp"
#include "List.hpp"
#include <iostream>
#include <vector>

bool test()
{
	const int testLength = 10;
	List *testList = createList();
	Contact *testContacts[testLength];

	char c[1];
	c[0] = 'a';

	for (int i = 0; i < testLength; ++i)
	{
		Contact *contact = new Contact();
		strcpy(contact->name, c);
		strcpy(contact->phone, c);
		testContacts[i] = contact;
		++c[0];
	}

	for (int i = testLength - 1; i >= 0; --i)
	{
		add(testList, createNode(*testContacts[i]));
	}

	if (!testSort(testList, 0)) // name
	{
		cout << "Name sort error!" << endl;
		deleteList(testList);
		delete[] testContacts;
		return false;
	}

	if (!testSort(testList, 1)) // phone
	{
		cout << "Number sort error!" << endl;
		deleteList(testList);
		delete[] testContacts;
		return false;
	}

	deleteList(testList);

	return true;
}