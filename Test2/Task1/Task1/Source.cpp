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

	int a = 0;
	int b = 0;

	cout << "Enter A: ";
	cin >> a;
	cout << "Enter B: ";
	cin >> b;

	List *list = createList();

	readFromFile(list);

	printList(list);

	List *answer = createList();

	answer = proceedTask(list, a, b);

	cout << "Result: " << endl;

	printList(answer);

	writeToFile(answer);

	deleteList(list);
	deleteList(answer);

	return EXIT_SUCCESS;
}