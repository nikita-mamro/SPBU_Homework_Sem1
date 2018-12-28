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

	vector<int> answer = mostPopularPeriod(input);

	if (answer[0] != 15 || answer[1] != 18)
	{
		return false;
	}

	return true;
}
