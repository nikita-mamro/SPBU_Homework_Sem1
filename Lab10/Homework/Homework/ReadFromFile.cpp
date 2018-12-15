#include "ReadFromFile.hpp"
#include "Graph.hpp"
#include <fstream>

struct InputElement
{
	int cityFrom;
	int cityTo;
	int roadLength;
};

InputElement *createInputElement(int cityFrom, int cityTo, int roadLength)
{
	return new InputElement{ cityFrom, cityTo, roadLength };
}

int getRoadLength(InputElement * element)
{
	return element->roadLength;
}

int getCityFrom(InputElement * element)
{
	return element->cityFrom;
}

int getCityTo(InputElement * element)
{
	return element->cityTo;
}

void readFromFile(vector<int>& capitals, vector<InputElement*>& triplets, ifstream & input)
{
	int cityCount = 0;
	int roadCount = 0;
	input >> cityCount;
	input >> roadCount;

	int cityFrom = 0;
	int cityTo = 0;
	int roadLength = 0;
	
	for (int i = 0; i < roadCount; ++i)
	{
		input >> cityFrom >> cityTo >> roadLength;
		triplets.push_back(createInputElement(cityFrom, cityTo, roadLength));
	}

	int capitalsCount = 0;
	
	input >> capitalsCount;

	int capital = 0;

	for (int i = 0; i < capitalsCount; ++i)
	{
		input >> capital;
		capitals.push_back(capital);
	}
}
