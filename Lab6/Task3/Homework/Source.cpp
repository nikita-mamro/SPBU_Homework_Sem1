#include "Test.hpp"

int main()
{
	cout << "Running tests..." << endl << endl;

	if (test())
	{
		cout << "Passed tests!" << endl << endl;
	}
	else
	{
		cout << "Failed tests!" << endl << endl;
	}

	cout << "Input infix string:" << endl;

	string input;
	getline(cin, input);
	string res = infixToPostfix(input);

	cout << "Converted into postfix:" << endl << res << endl;

	return 0;
}