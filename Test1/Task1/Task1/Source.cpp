#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

bool* initNumber(int size)
{
	bool* result = new bool[size];
	for (int i = 0; i < size; ++i)
	{
		result[i] = rand() % 2;
	}
	return result;
}

void printNumber(bool *number, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d", number[i]);
	}
}

bool* findBigOne(bool *firstNumber, bool *secondNumber, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (firstNumber[i] > secondNumber[i])
		{
			return firstNumber;
		}
		if (firstNumber[i] < secondNumber[i])
		{
			return secondNumber;
		}
	}
}

void test()
{
	bool *first = new bool[32]{};
	bool *second = new bool[32]{};
	for (int i = 0; i < 32; ++i)
	{
		first[i] = 0;
		second[i] = 0;
	}
	second[28] = 1;
	for (int i = 29; i < 32; ++i)
	{
		first[i] = 1;
	}
	printf("Числа: \n");
	printNumber(first, 32);
	printf("\n");
	printNumber(second, 32);
	bool *result = findBigOne(first, second, 32);
	printf("\nПосчитанное большее число: \n");
	printNumber(result, 32);
	result[30] == 1 ? printf("\nТест не пройден!\n\n") : printf("\nТест пройден!\n\n");
}


int main()
{
	setlocale(LC_ALL, "Russian");
	test();
	const int size = 32;
	bool *first = initNumber(size);
	bool *second = initNumber(size);
	printf("Ваши числа: \n");
	printNumber(first, size);
	printf("\n");
	printNumber(second, size);
	bool *result = findBigOne(first, second, size);
	printf("\nБольшее число: \n");
	printNumber(result, size);
	return 0;
}