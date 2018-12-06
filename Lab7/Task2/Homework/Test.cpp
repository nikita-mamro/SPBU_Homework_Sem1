#include "Test.hpp"
#include "Tree.hpp"

bool test(vector<string>& result)
{
	bool res = true;

	ifstream input("testinput.txt", ios::in);

	if (!input.is_open())
	{
		result.push_back("Cannot open testinput.txt");
		return false;
	}

	Tree *testTree = createTree(input);
	
	if (getExpressionValue(testTree) != 12)
	{
		string expressionError = "Error in counting the value of expression!\n";
		expressionError += "Counted anwer: " + to_string(getExpressionValue(testTree));
		expressionError += "\nExpected answer: 12!";
		result.push_back(expressionError);
		res = false;
	}

	return res;
}
