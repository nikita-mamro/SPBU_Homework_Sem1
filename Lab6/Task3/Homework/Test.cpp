#include "Test.hpp"

bool test()
{
	const int numOfTests = 4;

	string testStrings[numOfTests];
	string answers[numOfTests];
	
	testStrings[0] = "1 + 1";
	answers[0] = "11+";
	testStrings[1] = "(1 + 1) * 2";
	answers[1] = "11+2*";
	testStrings[2] = "(3 + 3) * (2 + 2) / (1 + 1)";
	answers[2] = "33+22+*11+/";
	testStrings[3] = "2 * 2 * 2 / (1 + 3) + 3 * 2";
	answers[3] = "22*2*13+/32*+";
	
	for (int i = 0; i < numOfTests; ++i)
	{
		if (infixToPostfix(testStrings[i]).compare(answers[i]) != 0)
		{
			return false;
		}
	}

	return true;
}