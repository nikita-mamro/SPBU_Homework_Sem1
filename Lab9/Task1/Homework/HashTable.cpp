#include "HashTable.hpp"
#include "List.hpp"
#include <vector>

struct HashTable
{
	vector <List*> buckets;
};

HashTable * createHashTable()
{
	return new HashTable;
}

HashTable * readFromFile(ifstream & input)
{
	HashTable *table = createHashTable();



	return table;
}

void add(const string & word, HashTable *table)
{
	int hash = hashFunction(word) % table->buckets.size();

	if (!exists(word, table))
	{
		add(table->buckets[hash], createNode(word));
	}
	else
	{
		changeCounter(table->buckets[hash], word, 1);
	}
}

bool exists(const string & word, HashTable const *table)
{
	int hash = hashFunction(word) % table->buckets.size();
	return exists(table->buckets[hash], word);
}

int hashFunction(const string & word)
{
	int sum = 0;

	for (unsigned int i = 0; i < word.length(); ++i)
	{
		sum = sum * 5 + word[i];
	}

	return sum;
}

void printWordsFrequency(HashTable * table)
{
	for (List *current : table->buckets)
	{
		if (current != nullptr)
		{
			printList(current);
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

	return (double) elementsCount / (double) segmentsCount;
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

	return (double) lengthsSum / (double) lengthsCounter;
}
