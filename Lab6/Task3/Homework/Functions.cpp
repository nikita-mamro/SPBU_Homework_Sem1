#include "Functions.hpp"

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isOperand(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isOpeningBracket(char c)
{
	return c == '(';
}

bool isClosingBracket(char c)
{
	return c == ')';
}

int charToDigit(char c)
{
	return c - '0';
}

int proceedOperand(int a, int b, char operand)
{
	switch (operand)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
	return -1;
}

int operandPriority(char operand)
{
	switch (operand)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return 0;
	}
}

string infixToPostfix(const string &input)
{
	Stack stack;
	const int length = input.length();
	string result;

	for (int i = 0; i < length; ++i)
	{
		if (input[i] != ' ')
		{
			if (isDigit(input[i]))
			{
				result += input[i];
			}
			else if (isOperand(input[i]))
			{
				while (!isEmpty(stack) && isOperand(top(stack)) && operandPriority(top(stack)) >= operandPriority(input[i]))
				{
					result += pop(stack);
				}
				push(stack, input[i]);
			}
			else if (isOpeningBracket(input[i]))
			{
				push(stack, input[i]);
			}
			else if (isClosingBracket(input[i]))
			{
				while (!isOpeningBracket(top(stack)))
				{
					result += pop(stack);
				}
				pop(stack);
			}
		}
	}

	while (!isEmpty(stack))
	{
		result += pop(stack);
	}

	deleteStack(stack);

	return result;
}