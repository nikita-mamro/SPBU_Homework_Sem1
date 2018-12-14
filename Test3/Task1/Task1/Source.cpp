#include <iostream>
#include "Test.hpp"
#include "SortedList.hpp"

using namespace std;

int main()
{
	cout << "Running tests!" << endl;

	if (!test())
	{
		cout << "Failed tests!" << endl;
		return EXIT_FAILURE;
	}

	cout << "Passed tests!" << endl;
	cout << "Start inputting numbers until it's 0:" << endl;

	SortedList list;
	int input = -1;

	while (input != 0)
	{
		cin >> input;
		addElement(input, list);
	}

	printSortedList(list);

	deleteSortedList(list);
	return EXIT_SUCCESS;
}