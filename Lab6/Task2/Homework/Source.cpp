#include "Test.hpp"

int main()
{
	cout << "Running tests..." << endl << endl;

	if (!test())
	{
		cout << "Tests failed!" << endl << endl;
		return 0;
	}
	else
	{
		cout << "Tests passed!" << endl << endl;
	}

	cout << "Enter the string to be checked on bracket balance:" << endl;
	string input;
	getline(cin, input);

	if (checkString(input))
	{
		cout << "Brackets are balanced!" << endl;
	}
	else
	{
		cout << "Brackets are NOT balanced!" << endl;
	}

	return 0;
}