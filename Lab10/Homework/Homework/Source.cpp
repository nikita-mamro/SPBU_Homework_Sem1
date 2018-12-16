#include <iostream>
#include <fstream>
#include "Graph.hpp"
#include "ReadFromFile.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
	vector <string> testResult;
	
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

	vector<vector<int>> answer = solveTask(input);

	input.close();
	
	char c = 'A';

	for (vector<int> country : answer)
	{
		cout << "Country " << c << " : ";
		for (int city : country)
		{
			cout << city << " ";
		}
		++c;
		cout << endl;
	}

	return EXIT_SUCCESS;
}