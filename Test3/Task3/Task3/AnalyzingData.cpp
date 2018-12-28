#include "AnalyzingData.hpp"
#include <utility>

using namespace std;

vector<pair<int, int>> dataFromFile(ifstream & input)
{
	vector<pair<int, int>> result;

	int current = 0;

	while (!input.eof())
	{
		int timeFrom = 0;
		int timeTo = 0;

		input >> current;
		timeFrom += current * 60;

		input >> current;
		timeFrom += current;

		input >> current;
		timeTo += current * 60;

		input >> current;
		timeTo += current;

		pair<int, int> pair(timeFrom, timeTo);

		result.push_back(pair);

		input.get();
	}

	return result;
}

pair<int, int> mostPopularPeriod(ifstream & input)
{
	pair<int, int> result;

	vector<pair<int, int>> visitors = dataFromFile(input);

	int maxNumOfVisitors = 0;
	int counter = 1;

	vector<pair<int, int>> tmpVisitors;
	vector<pair<int, int>> visitorsAtTimeWeNeed;

	visitorsAtTimeWeNeed.push_back(visitors[0]);

	for (unsigned int i = 0; i < visitors.size() - 1; ++i)
	{
		tmpVisitors.clear();
		tmpVisitors.push_back(visitors[i]);

		for (unsigned int j = i + 1; j < visitors.size(); ++j)
		{
			if (visitors[i].second < visitors[j].first)
			{
				break;
			}
			++counter;
			tmpVisitors.push_back(visitors[j]);
		}

		if (counter > maxNumOfVisitors)
		{
			maxNumOfVisitors = counter;
			counter = 0;
			visitorsAtTimeWeNeed = tmpVisitors;
		}
	}

	int timeFrom = 0;
	int timeTo = 1441;

	for (auto  visitor : visitorsAtTimeWeNeed)
	{
		if (visitor.first > timeFrom)
		{
			timeFrom = visitor.first;
		}
		if (visitor.second < timeTo)
		{
			timeTo = visitor.second;
		}
	}

	result.first = timeFrom / 60;
	result.second = timeTo / 60;

	return result;
}
