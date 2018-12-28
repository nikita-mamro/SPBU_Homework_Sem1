#include "AnalyzingData.hpp"
#include <vector>
#include <fstream>

using namespace std;

struct Person
{
	int timeFrom = 0;
	int timeTo = 0;
	Person(int from, int to) { timeFrom = from; timeTo = to;}
};

vector<Person*> dataFromFile(ifstream & input)
{
	vector<Person*> result;

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

		result.push_back(new Person(timeFrom, timeTo));

		input.get();
	}

	return result;
}

vector<int> mostPopularPeriod(ifstream & input)
{
	vector<int> result(2);

	vector<Person*> people = dataFromFile(input);

	int maxNumOfVisitors = 0;
	int counter = 1;

	vector<Person*> tmpPeople;
	vector<Person*> peopleAtTimeWeNeed;

	peopleAtTimeWeNeed.push_back(people[0]);

	for (unsigned int i = 0; i < people.size() - 1; ++i)
	{
		tmpPeople.clear();
		tmpPeople.push_back(people[i]);

		for (unsigned int j = i + 1; j < people.size() - 1; ++j)
		{
			if (people[i]->timeTo < people[j]->timeFrom)
			{
				break;
			}
			++counter;
			tmpPeople.push_back(people[j]);
		}

		if (counter > maxNumOfVisitors)
		{
			maxNumOfVisitors = counter;
			counter = 0;
			peopleAtTimeWeNeed = tmpPeople;
		}
	}

	int timeFrom = 0;
	int timeTo = 1441;

	for (auto * person : peopleAtTimeWeNeed)
	{
		if (person->timeFrom > timeFrom)
		{
			timeFrom = person->timeFrom;
		}
		if (person->timeTo < timeTo)
		{
			timeTo = person->timeTo;
		}
	}

	for (auto * person : people)
	{
		delete person;
	}

	result[0] = timeFrom / 60;
	result[1] = timeTo / 60;

	return result;
}
