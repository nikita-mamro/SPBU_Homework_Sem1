#include "CheckString.hpp"

bool isOpeningBracket(const char c)
{
	return c == '(' || c == '[' || c == '{' ? true : false;
}

bool isClosingBracket(const char c)
{
	return c == ')' || c == ']' || c == '}' ? true : false;
}

bool isPair(const char fBr, const char sBr)
{
	if (fBr == '(' && sBr == ')' || fBr == '{' && sBr == '}' || fBr == '[' && sBr == ']')
	{
		return true;
	}
	return false;
}

bool checkString(const string str)
{
	Stack stack;
	int length = str.length();
	
	for (int i = 0; i < length; ++i)
	{
		if (!isOpeningBracket(str[i]) && !isClosingBracket(str[i]))
		{
			continue;
		}

		if (isOpeningBracket(str[i]))
		{
			push(stack, str[i]);
		}

		else if (isClosingBracket(str[i]))
		{
			if (isPair(top(stack), str[i]))
			{
				pop(stack);
			}
			else
			{
				deleteStack(stack);
				return false;
			}
		}
	}

	if (top(stack) != '\0')
	{
		deleteStack(stack);
		return false;
	}

	deleteStack(stack);
	return true;
}