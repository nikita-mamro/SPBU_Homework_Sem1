#include "Functions.hpp"
#include "stdafx.hpp"

using namespace std;

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isOperand(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
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

int proceedTask(const string &input)
{
	int length = input.length();
	Stack *stack = createStack();
	for (int i = 0; i < length; ++i)
	{
		if (input[i] == ' ')
		{
			continue;
		}
		else if (isDigit(input[i]))
		{
			int currentNumber = charToDigit(input[i]);
			push(stack, currentNumber);
		}
		else if (isOperand(input[i]))
		{
			int numberA = pop(stack);
			int numberB = pop(stack);
			int buffer = proceedOperand(numberB, numberA, input[i]);
			push(stack, buffer);
		}
		else
		{
			printf("Unable to proceed input!\nCheck whether ur input is correct!\n");
			return -1;
		}
	}
	int result = pop(stack);
	deleteStack(stack);
	return result;
}