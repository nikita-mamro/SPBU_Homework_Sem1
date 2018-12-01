#include "Menu.hpp"
#include "AVL_Tree.hpp"
#include "Test.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> result;

	if (!test(result))
	{
		cout << "Tests failed!" << endl;
		for (unsigned int i = 0; i < result.size(); ++i)
		{
			cout << result[i] << endl;
		}
		return EXIT_FAILURE;
	}
	else
	{
		cout << "Tests passed!" << endl;
	}

	proceedTask();
	return EXIT_SUCCESS;
}