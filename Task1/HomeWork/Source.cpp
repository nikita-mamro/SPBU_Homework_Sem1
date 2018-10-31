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
		return;
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

void deleteArray(int *arr)
{
	delete[] arr;
}

bool isSorted(int *arr, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			printf("Test failed!\n");
			return false;
		}
	}
	return true;
}

bool test()
{
	int* testArray1 = new int[10]{ 1, 3, 1, 5, 1204, 12, 124, 4, 1, 0 };
	printf("Initial array:\n");
	printArray(testArray1, 10);
	quickSort(testArray1, 0, 9);
	printArray(testArray1, 10);
	if (!isSorted(testArray1, 10))
	{
		printf("Test 1 failed\n");
		delete[] testArray1;
		return false;
	}
	delete[] testArray1;

	int* testArray2 = new int[20]{ 132, 123, 123, 12, 3, 1425, 23, 6, 2, 634, 58, -23, 14, -1, 51, -2, 541, -4, 21, 10000 };
	printf("Initial array:\n");
	printArray(testArray2, 20);
	quickSort(testArray2, 0, 19);
	printArray(testArray2, 20);
	if (!isSorted(testArray2, 20))
	{
		printf("Test 1 failed\n");
		delete[] testArray2;
		return false;
	}
	delete[] testArray2;

	int length = rand() % 20 + 1;
	int* testArray3 = initArray(length);
	printf("Initial array:\n");
	printArray(testArray3, length);
	quickSort(testArray3, 0, length - 1);
	printf("Sorted array:\n");
	printArray(testArray3, length);
	if (!isSorted(testArray3, length))
	{
		printf("Test 3 failed\n");
		delete[] testArray3;
		return false;
	}
	delete[] testArray3;
	printf("Successfully passed the test!\n\n");
	return true;
}

int main()
{
	srand(time(nullptr));
	printf("Testing algorithm...\n");
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
