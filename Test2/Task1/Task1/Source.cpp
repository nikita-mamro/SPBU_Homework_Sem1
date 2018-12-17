#include <iostream>
#include "Test.hpp"
#include "List.hpp"

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
		cout << "Tests passed!" << endl;
	}

	List *list = createList();

	readFromFile(list);

	printList(list);

	List *answer = reverseList(list);

	cout << "Result: " << endl;

	printList(answer);

	deleteList(list);
	deleteList(answer);

	return EXIT_SUCCESS;
}