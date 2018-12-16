#include <iostream>
#include <string>
#include <fstream>
#include "PrimMST.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
	cout << "Running tests..." << endl;

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

	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	vector<vector<int>> graph;

	readFromFile(graph, input);

	return EXIT_SUCCESS;
}