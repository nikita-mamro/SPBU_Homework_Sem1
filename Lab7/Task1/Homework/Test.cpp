#include "Test.hpp"
#include "Set.hpp"

void fillSet(Set *set)
{
	add(set, 6);
	add(set, 3);
	add(set, 9);
	add(set, 2);
	add(set, 5);
	add(set, 10);
	add(set, 7);
	add(set, 8);
	add(set, 1);
	add(set, 4);
	add(set, 4);
}

bool test(std::vector<std::string> &result)
{
	Set *testSet = createSet();
	bool res = true;

	fillSet(testSet);

	for (int i = 1; i < 11; ++i)
	{
		if (!exists(testSet, i))
		{
			result.push_back("Error in exists()");
			res = false;
		}
		if (!remove(testSet, i))
		{
			result.push_back("Error in remove()");
			res = false;
		}
	}

	fillSet(testSet);

	std::vector<int> testFillArrayAsc;
	std::vector<int> testFillArrayDesc;
	
	fillArrayAscDesc(testFillArrayAsc, root(testSet), true);
	fillArrayAscDesc(testFillArrayDesc, root(testSet), false);
	
	for (int i = 0; i < testFillArrayAsc.size() - 1; ++i)
	{
		if (testFillArrayAsc[i] > testFillArrayAsc[i + 1])
		{
			result.push_back("Error in ascending order in fillArrayAscDesc()");
			res = false;
			break;
		}
	}
	
	for (int i = 0; i < testFillArrayDesc.size() - 1; ++i)
	{
		if (testFillArrayDesc[i] < testFillArrayDesc[i + 1])
		{
			result.push_back("Error in descending order in fillArrayAscDesc()");
			res = false;
			break;
		}
	}

	deleteSet(testSet);

	return res;
}