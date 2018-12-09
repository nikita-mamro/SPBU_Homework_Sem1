#include "List.hpp"
#include "Test.hpp"
#include <iostream>

using namespace std;

int main()
{
	cout << "Running tests..." << endl;

	if (!test())
	{
		cout << "Tests failed!" << endl;
		return EXIT_FAILURE;
	}
	else
	{
		cout << "Tests passed!" << endl << endl;
	}

	List *list = createList();
	
	cout << "Reading from file..." << endl << endl;

	fill(list);

	cout << "The list:" << endl;
	printList(list);
	
	if (checkList(list))
	{
		cout << "The list from file is symmetric!" << endl;
	}
	else
	{
		cout << "The list from file is NOT symmetric!" << endl;
	}

	deleteList(list);

	return EXIT_SUCCESS;
}