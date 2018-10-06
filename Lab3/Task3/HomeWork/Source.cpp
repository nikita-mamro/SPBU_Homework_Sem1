#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <conio.h>

void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int* initArray(int length)
{
	int* newArray = new int[length];
	for (int i = 0; i < length; ++i)
	{
		newArray[i] = rand() % 100;
	}
	return newArray;
}

void printArray(int *theArray, int length)
{
	printf("\n\n");
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", theArray[i]);
	}
	printf("\n\n");
}

void quickSort(int* arr, int firstIndex, int lastIndex)
{
	if (firstIndex >= lastIndex)
	{
		return;
	}
	int index = firstIndex;
	int element = arr[firstIndex];
	for (int i = firstIndex; i <= lastIndex; ++i)
	{
		if (arr[i] < element)
		{
			swap(arr[i], arr[index]);
			++index;
		}
	}
	if (index == firstIndex)
	{
		++index;
	}
	quickSort(arr, firstIndex, index - 1);
	quickSort(arr, index, lastIndex);
}

int mostFrequentElement(int *theArray, int length)
{
	quickSort(theArray, 0, length - 1);
	int element = 0;
	int tmpElement = theArray[0];
	int frequency = 0;
	int tmpFrequency = 1;
	for (int i = 1; i < length; ++i)
	{
		if (theArray[i] == tmpElement)
		{
			tmpFrequency++;
		}
		else
		{
			if (tmpFrequency > frequency)
			{
				element = tmpElement;
				frequency = tmpFrequency;
			}
			tmpFrequency = 1;
			tmpElement = theArray[i];
		}
	}
	if (tmpFrequency > frequency)
	{
		return tmpElement;
	}
	else
	{
		return element;
	}
}

void test()
{
	printf("Running test...\n\n");
	int* testArray = new int[16] {100, 8123, 31, 8213, 52, 3, 8123, 3, 24803, 24803, 3, 1, 90, 90, 8123, 8123};
	printArray(testArray, 16);
	int result = mostFrequentElement(testArray, 16);
	printf("Calculated element: %d\n", result);
	result == 8123 ? printf("Passed test!\n\n") : printf("Failed test, the answer is 8123\n\n");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	test();
	int length = 0;
	printf("Введите длину массива: ");
	scanf("%d", &length);
	int *myArray = initArray(length);
	printf("Ваш массив:");
	printArray(myArray, length);
	printf("Наиболее часто встречающийся элемент в массиве: %d", mostFrequentElement(myArray, length));
	delete[] myArray;
	_getch();
	return 0;
}