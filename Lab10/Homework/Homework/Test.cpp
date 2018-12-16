#include "Test.hpp"
#include "Graph.hpp"
#include <fstream>
#include <iostream>

bool test(vector<string>& result)
{
	bool res = true;

	ifstream testInput("testinput.txt", ios::in);

	if (!testInput.is_open())
	{
		res = false;
		result.push_back("Cannot open testinput.txt file!");
		return res;
	}

	vector<vector<int>> testAnswer = solveTask(testInput);

	if (testAnswer.size() != 3)
	{
		res = false;
		result.push_back("Error in counting the amount of countries!");
		return res;
	}

	vector<int> countryA = testAnswer[0];
	vector<int> countryB = testAnswer[1];
	vector<int> countryC = testAnswer[2];

	if (countryA.size() != 3)
	{
		result.push_back("Error in counting cities of first country!");
		res = false;
	}
	else
	{
		for (int city : countryA)
		{
			if (city != 3 && city != 4 && city != 2)
			{
				result.push_back("Error in naming cities of first country!");
				res = false;
			}
		}
	}

	if (countryB.size() != 1)
	{
		result.push_back("Error in counting cities of second country!");
		res = false;
	}
	else
	{
		if (countryB[0] != 1)
		{
			result.push_back("Error in naming cities of second country!");
			res = false;
		}
	}

	if (countryC.size() != 3)
	{
		result.push_back("Error in counting cities of third country!");
		res = false;
	}
	else
	{
		for (int city : countryC)
		{
			if (city != 6 && city != 5 && city != 0)
			{
				result.push_back("Error in naming cities of third country!");
				res = false;
			}
		}
	}

	return res;
}
