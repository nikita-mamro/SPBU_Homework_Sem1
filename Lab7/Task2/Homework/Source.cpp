#include <iostream>
#include <fstream>
#include "Tree.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
	vector <string> testResult;

	if (!test(testResult))
	{
		cout << "Tests failed!" << endl;
		for (int i = 0; i < testResult.size(); ++i)
		{
			cout << testResult[i] << endl;
		}
		return EXIT_FAILURE;
	}
	cout << "Passed all tests!" << endl;

	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	Tree *tree = createTree(input);
	input.close();
	cout << "Expression from input.txt: ";
	printExpression(tree);
	deleteTree(tree);
	cout << endl << "Answer: " << getExpressionValue(tree);

	return EXIT_SUCCESS;
}