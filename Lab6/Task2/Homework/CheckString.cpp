#include "CheckString.hpp"
#include "stdafx.hpp"

bool isOpeningBracket(const char c)
{
	return c == '(' || c == '[' || c == '{';
}

bool isClosingBracket(const char c)
{
	return c == ')' || c == ']' || c == '}';
}

bool isPair(const char firstBracket, const char secondBracket)
{
	return (firstBracket == '(' && secondBracket == ')' || firstBracket == '{' && secondBracket == '}' || firstBracket == '[' && secondBracket == ']');
}

bool checkString(const string str)
{
	Stack *stack = createStack();
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