#include "Functions.hpp"

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
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
	return 0;
}

int proceedString(string str)
{
	int result = 0;
	return result;
}