#include <iostream>
#include <fstream>
#include <vector>
#include "AnalyzingData.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
	if (!test())
	{
		cout << "Failed tests!" << endl;
		return EXIT_FAILURE;
	}

	cout << "Passed tests!" << endl;

	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	pair<int, int> answer = mostPopularPeriod(input);

	cout << "Most popular hours:" << endl;
	cout << "From " << answer.first << " to " << answer.second << endl;

	return EXIT_SUCCESS;
}