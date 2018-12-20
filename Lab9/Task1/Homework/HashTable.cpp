#include "HashTable.hpp"
#include "List.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct HashTable
{
	vector<List*> buckets;
};

HashTable * createHashTable()
{
	return new HashTable;
}

void readFromFile(HashTable * table, ifstream & input)
{
	table->buckets.resize(100);

	string word;

	while (!input.eof())
	{
		input >> word;
		add(word, table);
	}
}

void deleteTable(HashTable *& table)
{
	for (List *current : table->buckets)
	{
		deleteList(current);
	}

	delete table;
	table = nullptr;
}

void add(const string & word, HashTable *table)
{
	if (loadCoefficient(table) > 1.0)
	{
		expand(table);
	}

	const unsigned int hash = hashFunction(word) % table->buckets.size();

	if (table->buckets[hash] == nullptr)
	{
		table->buckets[hash] = createList();
	}

	if (!exists(word, table))
	{
		add(table->buckets[hash], createNode(word, 1));
	}
	else
	{
		changeCounter(table->buckets[hash], word, 1);
	}
}

bool exists(const string & word, const HashTable * table)
{
	const unsigned int hash = hashFunction(word) % table->buckets.size();
	return exists(table->buckets[hash], word);
}

unsigned long int hashFunction(const string & word)
{
	long int sum = 0;

	for (unsigned int i = 0; i < word.length(); ++i)
	{
		sum = sum * 19 + word[i] * 13;
	}

	return sum;
}

void expand(HashTable * table)
{
	const int size = table->buckets.size();
	table->buckets.resize(size * 2);

	for (unsigned int i = table->buckets.size() / 2; i < table->buckets.size(); ++i)
	{
		table->buckets[i] = createList();
	}

	for (unsigned int i = 0; i < table->buckets.size() / 2; ++i)
	{
		Node *current = getHead(table->buckets[i]);

		while (current != nullptr)
		{
			if (isRehashed(current))
			{
				setIsRehashed(current, false);
				continue;
			}

			const unsigned int hash = hashFunction(getWord(current)) % table->buckets.size();
			List *targetList = table->buckets[hash];
			string word = getWord(current);
			int counter = getCounter(current);

			add(table->buckets[hash], createNode(word, counter));


			setIsRehashed(current, true);

			Node *tmp = current;
			current = next(current);
			remove(table->buckets[i], tmp);
		}
	}
}

double loadCoefficient(const HashTable * table)
{
	int elementsCount = 0;

	for (List *current : table->buckets)
	{
		if (current != nullptr)
		{
			elementsCount += getLength(current);
		}
	}

	int segmentsCount = table->buckets.size();

	return (double)elementsCount / (double)segmentsCount;
}

int maxLenghtInSegment(const HashTable * table)
{
	int maxLength = 0;

	for (List *current : table->buckets)
	{
		if (current != nullptr)
		{
			if (getLength(current) > maxLength)
			{
				maxLength = getLength(current);
			}
		}
	}

	return maxLength;
}

double averageLengthInSegment(const HashTable * table)
{
	int lengthsSum = 0;
	int lengthsCounter = 0;

	for (List *current : table->buckets)
	{
		if (current != nullptr)
		{
			lengthsSum += getLength(current);
			++lengthsCounter;
		}
	}

	return (double)lengthsSum / (double)lengthsCounter;
}

struct Element
{
	string word;
	int counter;
};

Element *createElement(string word, int counter)
{
	return new Element{ word, counter };
}

void qsort(vector<Element*> &arr, int low, int high)
{
	if (low >= high)
	{
		return;
	}

	int index = low;
	string element = arr[low]->word;

	for (int i = low; i <= high; ++i)
	{
		if (arr[i]->word < element)
		{
			swap(arr[i], arr[index]);
			++index;
		}
	}
	if (index == low)
	{
		++index;
	}

	qsort(arr, low, index - 1);
	qsort(arr, index, high);
}

void fillArray(HashTable *table, vector<Element*>& res)
{
	for (List *currentList : table->buckets)
	{
		if (currentList != nullptr)
		{
			Node *currentNode = getHead(currentList);
			while (currentNode != nullptr)
			{
				Element *tmp = createElement(getWord(currentNode), getCounter(currentNode));
				res.push_back(tmp);
				currentNode = next(currentNode);
			}
		}
	}
	qsort(res, 0, res.size() - 1);
}


void printWordsFrequency(vector<Element*> result)
{
	for (Element *currentElement : result)
	{
		cout << currentElement->word << " - " << currentElement->counter << endl;
	}
}

void setElementWord(Element * element, string word)
{
	element->word = word;
}

void setElementCounter(Element * element, int counter)
{
	element->counter = counter;
}

string getElementWord(Element * element)
{
	return element->word;
}

int getElementCounter(Element * element)
{
	return element->counter;
}