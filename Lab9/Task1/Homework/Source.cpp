#include "HashTable.hpp"
#include "Test.hpp"
#include <iostream>
#include <vector>

int main()
{
	vector<string> testResult;

	if (!test(testResult))
	{
		cout << "Tests failed!" << endl;
		for (unsigned int i = 0; i < testResult.size(); ++i)
		{
			cout << testResult[i] << endl;
		}
		return EXIT_FAILURE;
	}
	cout << "Passed all tests!" << endl;

	ifstream input("input.txt", ios::in);
	
	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	HashTable *table = readFromFile(input);

	vector<Element*> res;
	fillArray(table, res);

	cout << "WORD - FREQUENCY:" << endl;
	printWordsFrequency(res);
	cout << endl << "Load coefficient: " << loadCoefficient(table) << endl;
	cout << endl << "Average list length: " << averageLengthInSegment(table) << endl;
	cout << endl << "MAX list length: " << maxLenghtInSegment(table) << endl;

	input.close();

	return EXIT_SUCCESS;
}