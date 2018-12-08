#include "Test.hpp"
#include "HashTable.hpp"

void fillAnswers(vector<Element*> answer)
{
	Element *e1 = createElement(",", 1);
	Element *e2 = createElement("Test", 1);
	Element *e3 = createElement("being", 1);
	Element *e4 = createElement("by", 1);
	Element *e5 = createElement("is", 2);
	Element *e6 = createElement("test", 1);
	Element *e7 = createElement("tested", 1);
	Element *e8 = createElement("testing", 1);
	Element *e9 = createElement("textfile", 1);
	Element *e10 = createElement("the", 2);

	answer.push_back(e1);
	answer.push_back(e2);
	answer.push_back(e3);
	answer.push_back(e4);
	answer.push_back(e5);
	answer.push_back(e6);
	answer.push_back(e7);
	answer.push_back(e8);
	answer.push_back(e9);
	answer.push_back(e10);
}

bool test(vector<string>& result)
{
	bool res = true;

	ifstream input("testinput.txt", ios::in);

	if (!input.is_open())
	{
		result.push_back("Cannot open testinput.txt");
		return false;
	}

	HashTable *testTable = readFromFile(input);

	vector<Element*> testRes;
	fillArray(testTable, testRes);

	vector<Element*> answer;

	fillAnswers(answer);
	// ѕроверка на наличие и верность всех слов и их кол-ва

	for (Element *current : testRes)
	{
		for (Element *currentAnswer : answer)
		{
			if (getElementWord(current) != getElementWord(currentAnswer))
			{
				result.push_back("Error: Wrong words!");
				res = false;
			}
			if (getElementCounter(current) != getElementCounter(currentAnswer))
			{
				result.push_back("Error: Wrong counters!");
				res = false;
			}
		}
	}

	input.close();

	return res;
}