#include <iostream>
#include "Test.hpp"
#include "KMPalgorithm.hpp"
#include "ReadFile.hpp"

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

	cout << "Tests passed!" << endl;

	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	string checkReadFromFile = readFromFile(input);

	cout << checkReadFromFile << endl;

	input.close();

	return EXIT_SUCCESS;
}