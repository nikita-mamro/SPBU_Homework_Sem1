#include <iostream>
#include <fstream>
#include "Graph.hpp"
#include "ReadFromFile.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
	//***TESTS***

	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	vector<vector<int>> answer = solveTask(input);
	char c = 'A';

	for (vector<int> country : answer)
	{
		cout << c << " - ";
		for (int city : country)
		{
			cout << city << " ";
		}
		++c;
		cout << endl;
	}

	return EXIT_SUCCESS;
}