#include "Menu.hpp"
#include "Test.hpp"
#include "File.hpp"
#include <iostream>

using namespace std;

int main()
{
	cout << "Running tests..." << endl;

	if (!test())
	{
		cout << "Failed tests!" << endl;
		return EXIT_FAILURE;
	}
	
	cout << "Passed tests!" << endl;

	List *list = createList();
	readFromFile(list);
	proceedTask(list);
	deleteList(list);

	return EXIT_SUCCESS;
}