#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//В массиве целых чисел найти число, сумма 
//цифр которого была бы наибольшей. Если таких чисел несколько, 
//вывести на экран все эти числа.

void printArray(int *theArray, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", theArray[i]);
	}
	printf("\n");
}

int sumOfDigits(int number)
{
	int res = 0;

	while (number > 0)
	{
		res += number % 10;
		number /= 10;
	}

	return res;
}

int *findAnswer(int *theArray, int length)
{
	int *tmp = new int[length] {};
	int maxDigitsSum = -1;
	int index = 0;
	for (int i = 0; i < length; ++i)
	{
		if (sumOfDigits(theArray[i]) > maxDigitsSum)
		{
			for (int i = 0; i < length; ++i)
			{
				tmp[i] = 0;
			}
			index = 0;
			maxDigitsSum = sumOfDigits(theArray[i]);
			tmp[index] = theArray[i];
		}
		else if (sumOfDigits(theArray[i]) == maxDigitsSum)
		{
			++index;
			tmp[index] = theArray[i];
		}
	}
	int j = 0;
	int resLength = 1;
	while (sumOfDigits(tmp[j]) <= sumOfDigits(tmp[j + 1]) && j < length)
	{
		++resLength;
		++j;
	}
	int *res = new int[length + 1] {};
	res[length] = resLength;
	for (int i = 0; i < resLength; ++i) 
	{
		res[i] = tmp[i];
	}
	delete[] tmp;
	return res;
}

bool test()
{
	const int testLength = 10;
	int *testArr1 = new int[testLength] { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	int *answer1 = findAnswer(testArr1, testLength);
	for (int i = 0; i < 10; ++i)
	{
		if (answer1[i] != 10)
		{
			printf("Test 1 failed");
			return false;
		}
	}
	delete[] testArr1;
	delete[] answer1;

	int *testArr2 = new int[testLength] { 9998, 103, 11230, 10214, 113240, 8999, 10, 10, 10, 120 };
	int *answer2 = findAnswer(testArr2, testLength);
	if (answer2[0] != 9998 || answer2[1] != 8999)
	{
		printf("Test 2 failed");
		return false;
	}
	delete[] testArr2;
	delete[] answer2;
	printf("Passed tests\n");
	return true;
}

int main()
{
	srand(time(nullptr));
	test();
	const int length = 20;
	int *theArray = new int[length]{};

	for (int i = 0; i < length; ++i)
	{
		theArray[i] = rand() % 100 + 100;
	}

	printf("Your array:\n");
	printArray(theArray, length);

	printf("The answer is:\n");
	int *answer = findAnswer(theArray, length);
	printArray(answer, answer[length]);

	delete[] theArray;
	return 0;
}