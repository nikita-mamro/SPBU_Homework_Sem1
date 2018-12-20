#define _CRT_SECURE_NO_WARNINGS
#include "Test.hpp"
#include "List.hpp"
#include <iostream>
#include <vector>
#include "ContactStruct.hpp"

using namespace std;

void deleteTestContacts(Contact *testContacts[], const int length)
{
	for (int i = 0; i < length; ++i)
	{
		delete testContacts[i];
	}
}

bool test()
{
	const int testLength = 10;
	List *testList = createList();
	Contact *testContacts[testLength];

	char c[] = { 'a', '\0' };

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
		deleteTestContacts(testContacts, testLength);
		return false;
	}

	if (!testSort(testList, 1)) // phone
	{
		cout << "Number sort error!" << endl;
		deleteList(testList);
		deleteTestContacts(testContacts, testLength);
		return false;
	}

	deleteList(testList);
	deleteTestContacts(testContacts, testLength);

	return true;
}