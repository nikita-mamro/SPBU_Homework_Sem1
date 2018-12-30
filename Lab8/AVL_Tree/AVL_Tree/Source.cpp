#include "Menu.hpp"
#include "AVL_Tree.hpp"
#include "Test.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> testResult;

	if (!test(testResult))
	{
		cout << "Tests failed!" << endl;
		for (unsigned int i = 0; i < testResult.size(); ++i)
		{
			cout << testResult[i] << endl;
		}
		return EXIT_FAILURE;
	}

	cout << "Tests passed!" << endl;
	proceedTask();
	return EXIT_SUCCESS;
}