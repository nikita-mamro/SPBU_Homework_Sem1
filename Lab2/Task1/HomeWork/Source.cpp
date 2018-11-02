#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int fibonacciRec(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else if (n > 2)
	{
		return fibonacciRec(n - 1) + fibonacciRec(n - 2);
	}
	else
	{
		return 0;
	}
}

unsigned int fibonacciNoRec(int n)
{
	int firstElement = 1;
	int secondElement = 1;
	int nextElement = 1;

	for (int i = 2; i < n; ++i)
	{
		nextElement = firstElement + secondElement;
		firstElement = secondElement;
		secondElement = nextElement;
	}

	return nextElement;
}

void testSuccess(int input, int output)
{
	printf("Fib(n) passed test when n = %d, the result is %d\n", input, output);
}

void testFailure(int input, int output, int realResult)
{
	printf("Test failed: Fib(%d) != %d, the result should be %d\n", input, output, realResult);
}

void testFibRec()
{
	int fib1 = 1;
	int fib10 = 55;
	int fib40 = 102334155;
	printf("\nTesting FibonacciRec() function...\n\n");
	if (fibonacciRec(1) == fib1)
	{
		testSuccess(1, fib1);
	}
	else
	{
		testFailure(1, fibonacciRec(1), fib1);
	}
	if (fibonacciRec(10) == fib10)
	{
		testSuccess(10, fib10);
	}
	else
	{
		testFailure(10, fibonacciRec(10), fib10);
	}
	if (fibonacciRec(40) == fib40)
	{
		testSuccess(40, fib40);
	}
	else
	{
		testFailure(40, fibonacciRec(40), fib40);
	}
}

void testFibNoRec()
{
	int fib1 = 1;
	int fib10 = 55;
	int fib40 = 102334155;
	printf("\nTesting FibonacciNoRec() function...\n\n");
	if (fibonacciNoRec(1) == fib1)
	{
		testSuccess(1, fib1);
	}
	else
	{
		testFailure(1, fibonacciNoRec(1), fib1);
	}
	if (fibonacciNoRec(10) == fib10)
	{
		testSuccess(10, fib10);
	}
	else
	{
		testFailure(10, fibonacciNoRec(10), fib10);
	}
	if (fibonacciNoRec(40) == fib40)
	{
		testSuccess(40, fib40);
	}
	else
	{
		testFailure(40, fibonacciNoRec(40), fib40);
	}
}

int main()
{
	int n = 0;
	testFibRec();
	testFibNoRec();
	printf("Enter the position of Fib number: ");
	scanf("%d", &n);
	printf("Found via recursion:\n%d\nFound without recursion:\n%d\n", fibonacciRec(n), fibonacciNoRec(n));
	return 0;
}