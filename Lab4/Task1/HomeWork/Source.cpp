#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


bool* toBits(int num) {
	bool* res = new bool[32];
	for (int i = 0; i < 32; ++i)
	{
		res[i] = num >> i & 1;
	}
	return res;
}

int toInt(bool* bitNumber)
{
	int res = 0;
	for (int i = 0; i < 32; ++i)
	{
		res += bitNumber[i] << i;
	}
	return res;
}

bool* sumNumbers(bool* firstNumber, bool* secondNumber)
{
	bool *result = new bool[32];
	bool temp = 0;

	for (int i = 0; i < 32; ++i)
	{
		result[i] = temp ^ firstNumber[i] ^ secondNumber[i];
		temp = (temp & firstNumber[i]) || (temp & secondNumber[i]) || (firstNumber[i] & secondNumber[i]);
	}

	return result;
}

void printBiNum(bool* num)
{
	for (int i = 31; i >= 0; --i) {
		printf("%d", num[i]);
	}
	printf("\n");
}

bool test()
{
	printf("Running tests...\n\n");
	int firstNumber = rand() / 2;
	int secondNumber = rand() / 2;
	printf("First number: %d\nSecond number: %d\n", firstNumber, secondNumber);
	bool* firstBiNumber = toBits(firstNumber);
	bool* secondBiNumber = toBits(secondNumber);
	printBiNum(firstBiNumber);
	printf("+\n");
	printBiNum(secondBiNumber);
	printf("--------------------------------\n");
	printBiNum(sumNumbers(firstBiNumber, secondBiNumber));
	int answer = toInt(sumNumbers(firstBiNumber, secondBiNumber));
	delete[] firstBiNumber;
	delete[] secondBiNumber;
	printf("The answer is %d\n", answer);
	int sumResult = firstNumber + secondNumber;
	printf("Correct answer: %d\n", sumResult);
	bool testResult = sumResult == answer;
	if (testResult)
	{
		printf("Test passed!\n\n");
		return true;
	}
	else
	{
		printf("Test failed!\n\n");
		return false;
	}
}

int main()
{
	srand(time(nullptr));
	test();
	int firstNumber = 0;
	int secondNumber = 0;
	printf("Input 1st number: ");
	scanf("%d", &firstNumber);
	printf("Input 2nd number: ");
	scanf("%d", &secondNumber);
	printf("Calculating sum...\n");
	bool* firstBiNumber = toBits(firstNumber);
	bool* secondBiNumber = toBits(secondNumber);
	printBiNum(firstBiNumber);
	printf("+\n");
	printBiNum(secondBiNumber);
	printf("--------------------------------\n");
	bool* answer = sumNumbers(firstBiNumber, secondBiNumber);
	printBiNum(answer);
	printf("The answer is %d", toInt(answer));
	delete[] firstBiNumber;
	delete[] secondBiNumber;
	delete[] answer;
	return 0;
}
