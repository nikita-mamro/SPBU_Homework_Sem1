#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int powLin(int a, int pow)
{
	int res = 1;
	for (int i = 0; i < pow; ++i)
	{
		res *= a;
	}
	return res;
}

int powLog(int a, int pow)
{
	int res = 1;
	if (pow == 0)
	{
		return 1;
	}
	if (pow == 1)
	{
		return a;
	}
	if (pow == 2)
	{
		return a * a;
	}
	int semiPower = powLog(a, pow / 2);
	return semiPower * semiPower * powLog(a, pow % 2);
}

void testLin()
{
	printf("Testing powLin()...\n");
	int testNum1 = 152998;
	int testPow1 = 0;
	printf("152998 ^ 0\n powLin() result: %d\n the result has to be 1\n", powLin(testNum1, testPow1));
	printf(powLin(152998, 0) == 1 ? "Test passed\n" : "Test failed\n");
	int testNum2 = 14;
	int testPow2 = 8;
	printf("14 ^ 8\n powLin() result: %d\n the result has to be 1475789056\n", powLin(testNum2, testPow2));
	printf(powLin(14, 8) == 1475789056 ? "Test passed\n\n" : "Test failed\n\n");
}

void testLog()
{
	printf("Testing powLog()...\n");
	int testNum1 = 152998;
	int testPow1 = 0;
	printf("152998 ^ 0\n powLog() result: %d\n the result has to be 1\n", powLog(testNum1, testPow1));
	printf(powLog(152998, 0) == 1 ? "Test passed\n" : "Test failed\n");
	int testNum2 = 14;
	int testPow2 = 8;
	printf("14 ^ 8\n powLog() result: %d\n the result has to be 1475789056\n", powLog(testNum2, testPow2));
	printf(powLog(14, 8) == 1475789056 ? "Test passed\n\n" : "Test failed\n\n");
}

int main()
{
	int number = 0;
	int power = 0;
	printf("Input number to elvate: ");
	scanf("%d", &number);
	printf("Input the power: ");
	scanf("%d", &power);
	printf("Using O(n) function %d ^ %d = %d\n", number, power, powLin(number, power));
	printf("Using O(logn) function %d ^ %d = %d", number, power, powLog(number, power));
	printf("\n\nTesting functions with other parameters......\n\n");
	testLin();
	testLog();
	return 0;
}