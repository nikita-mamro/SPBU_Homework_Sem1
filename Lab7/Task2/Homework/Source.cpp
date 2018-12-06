#include <iostream>
#include <fstream>
#include "Tree.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
	vector <string> result;

	if (!test(result))
	{
		cout << "Tests failed!" << endl;
		for (int i = 0; i < result.size(); ++i)
		{
			cout << result[i] << endl;
		}
		return EXIT_FAILURE;
	}
	else
	{
		cout << "Passed all tests!" << endl;
	}

	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}
	else
	{
		Tree *tree = createTree(input);
		cout << "Expression from input.txt: ";
		printExpression(tree);
		deleteTree(tree);
		cout << endl << "Answer: " << getExpressionValue(tree);
	}

	return EXIT_SUCCESS;
}