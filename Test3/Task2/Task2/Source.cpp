#include <iostream>
#include <vector>
#include "Test.hpp"
#include "PriorityQueue.hpp"

using namespace std;

int main()
{
	vector<string> errors;

	if (!test(errors))
	{
		cout << "Tests failed!" << endl;
		for (unsigned int i = 0; i < errors.size(); ++i)
		{
			cout << errors[i] << endl;
		}
		return EXIT_FAILURE;
	}

	cout << "Passed all tests!" << endl;

	PriorityQueue * pQueue = createQueue();

	enqueue(pQueue, 10, 1);
	enqueue(pQueue, 5, 12);
	enqueue(pQueue, 12, 2);
	enqueue(pQueue, 1, 1);

	printPQueue(pQueue);

	deletePQueue(pQueue);

	return EXIT_SUCCESS;
}