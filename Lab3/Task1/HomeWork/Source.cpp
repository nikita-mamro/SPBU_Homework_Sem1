#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int* initArray(int length)
{
	int* arr = new int[length] {};
	for (int i = 0; i < length; ++i)
	{
		arr[i] = rand() % 100 - 50;
	}
	return arr;
}

void printArray(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertionSort(int* arr, int firstIndex, int lastIndex)
{
	for (int i = firstIndex; i <= lastIndex; ++i)
	{
		for (int j = i; j > firstIndex && arr[j - 1] > arr[j]; --j)
		{
			swap(arr[j], arr[j - 1]);
		}
	}
}

void quickSort(int* arr, int firstIndex, int lastIndex)
{
	if (lastIndex - firstIndex < 10) 
	{
		insertionSort(arr, firstIndex, lastIndex);
	}
	else 
	{
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
}

bool isSorted(int *arr, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			printf("Test failed!\n");
			delete[] arr;
			return false;
		}
	}
	delete[] arr;
	printf("Successfully passed the test!\n\n");
	return true;
}

bool test()
{
	int length = rand() % 20 + 1;
	int* testArray = initArray(length);
	printf("Initial array:\n");
	printArray(testArray, length);
	quickSort(testArray, 0, length - 1, length);
	printArray(testArray, length);
	return isSorted(testArray, length);
}

int main()
{
	srand(time(NULL));
	printf("Testing algorithm...\n");
	test();
	test();
	int length = 0;
	printf("Input the length of an array, please: ");
	scanf("%d", &length);
	int *arr = initArray(length);
	printArray(arr, length);
	quickSort(arr, 0, length - 1);
	printf("Sorted array:\n");
	printArray(arr, length);
	delete[] arr;
	return 0;
}
