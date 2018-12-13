#include <iostream>
#include "Test.hpp"
#include "KMPalgorithm.hpp"
#include "ReadFile.hpp"

using namespace std;

int main()
{
	vector <string> testResult;

	if (!test(testResult))
	{
		cout << "Tests failed!" << endl;
		for (int i = 0; i < testResult.size(); ++i)
		{
			cout << testResult[i] << endl;
		}
		return EXIT_FAILURE;
	}

	cout << "Tests passed!" << endl;

	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	string text = readFromFile(input);

	input.close();

	cout << "Text from file:" << endl << endl;

	cout << text << endl << endl;

	cout << "Enter pattern:" << endl << endl;

	string pattern = string();

	getline(cin, pattern);

	int answer = firstPatternMatchKMP(text, pattern);

	if (answer < 0)
	{
		cout << "Pattern not found!" << endl;
		return EXIT_SUCCESS;
	}

	cout << "Your pattern occurs in text in position " << answer << endl;

	return EXIT_SUCCESS;
}