#include "Test.hpp"
#include "AnalyzingData.hpp"
#include <fstream>

using namespace std;

bool test()
{
	ifstream input("testinput.txt", ios::in);

	if (!input.is_open())
	{
		return false;
	}

	pair<int, int> answer = mostPopularPeriod(input);

	if (answer.first != 15 || answer.second != 18)
	{
		return false;
	}

	return true;
}
