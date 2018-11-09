#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


bool* toBits(int num) 
{
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
	for (int i = 31; i >= 0; --i)
	{
		printf("%d", num[i]);
	}
	printf("\n");
}

bool test()
{
	printf("Running tests...\n\n");
	int nonRandomNumber1 = 102;
	int nonRandomNumber2 = 123;
	printf("First number: %d\nSecond number: %d\n", nonRandomNumber1, nonRandomNumber2);
	bool* nonRandomBitNumber1 = toBits(102);
	bool* nonRandomBitNumber2 = toBits(123);
	printBiNum(nonRandomBitNumber1);
	printf("+\n");
	printBiNum(nonRandomBitNumber2);
	printf("--------------------------------\n");
	bool *bitAnswer1 = sumNumbers(nonRandomBitNumber1, nonRandomBitNumber2);
	printBiNum(bitAnswer1);
	int answer1 = toInt(bitAnswer1);
	delete[] nonRandomBitNumber1;
	delete[] nonRandomBitNumber2;
	delete[] bitAnswer1;
	printf("The answer is %d\n", answer1);
	int sumResult1 = nonRandomNumber1 + nonRandomNumber2;
	printf("Correct answer: %d\n\n", sumResult1);
	bool test1Result = sumResult1 == answer1;
	if (!test1Result)
	{
		printf("Test 1 failed!\n");
		return false;
	}

	int firstNumber = rand() / 2;
	int secondNumber = rand() / 2;
	printf("First number: %d\nSecond number: %d\n", firstNumber, secondNumber);
	bool* firstBiNumber = toBits(firstNumber);
	bool* secondBiNumber = toBits(secondNumber);
	printBiNum(firstBiNumber);
	printf("+\n");
	printBiNum(secondBiNumber);
	printf("--------------------------------\n");
	bool *bitAnswer2 = sumNumbers(firstBiNumber, secondBiNumber);
	printBiNum(bitAnswer2);
	int answer2 = toInt(bitAnswer2);
	delete[] firstBiNumber;
	delete[] secondBiNumber;
	delete[] bitAnswer2;
	printf("The answer is %d\n", answer2);
	int sumResult2 = firstNumber + secondNumber;
	printf("Correct answer: %d\n\n", sumResult2);
	bool test2Result = sumResult2 == answer2;
	if (!test2Result)
	{
		printf("Test 2 failed!\n");
		return false;
	}
	printf("Passed tests!\n");
	return true;
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
