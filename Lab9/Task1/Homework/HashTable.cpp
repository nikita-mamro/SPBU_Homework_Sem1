#include "HashTable.hpp"
#include "List.hpp"
#include <algorithm>

struct HashTable
{
	vector <List*> buckets;
};

void add(const string & word, HashTable &table)
{
	int hash = hashFunction(word) % table.buckets.size();

	if (!exists(word, table))
	{
		add(table.buckets[hash], createNode(word));
	}
	else
	{
		changeCounter(table.buckets[hash], word, 1);
	}
}

bool exists(const string & word, HashTable const &table)
{
	int hash = hashFunction(word) % table.buckets.size();
	return exists(table.buckets[hash], word);
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

void printWordsFrequency(HashTable & table)
{
	for (List *current : table.buckets)
	{
		if (current != nullptr)
		{
			printList(current);
		}
	}
}
