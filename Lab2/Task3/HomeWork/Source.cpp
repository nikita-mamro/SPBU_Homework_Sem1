#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void initArray(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		arr[i] = rand() % 100 - 50;
	}
}

void printArray(int *arr, int length)
{
	printf("\n\n");
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

void bubbleSort(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int maxArrayElem(int *arr, int length)
{
	int max = arr[0];
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int minArrayElem(int *arr, int length)
{
	int min = arr[0];
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

void addToElements(int *arr, int length, int delta)
{
	for (int i = 0; i < length; ++i)
	{
		arr[i] += delta;
	}
}

void countSort(int *arr, int length)
{
	int min = minArrayElem(arr, length);
	if (min < 0)
	{
		addToElements(arr, length, -min);
	}
	int max = maxArrayElem(arr, length);
	int *tmpArr = new int[max + 1]{};
	for (int i = 0; i < length; ++i)
	{
		++tmpArr[arr[i]];
	}
	int index = 0;
	for (int i = 0; i < max + 1; ++i)
	{
		while (tmpArr[i] != 0)
		{
			arr[index] = i;
			++index;
			--tmpArr[i];
		}
	}
	delete[] tmpArr;
	if (min < 0)
	{
		addToElements(arr, length, min);
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

bool testBubbleSort()
{
	printf("Testing BubbleSort...");
	int length = rand() % 100;
	int *testArr = new int[length] {};
	initArray(testArr, length);
	printArray(testArr, length);
	bubbleSort(testArr, length);
	printf("Array after BubbleSort:");
	printArray(testArr, length);
	return isSorted(testArr, length);
}

bool testCountSort()
{
	printf("Testing CountSort...");
	int length = rand() % 100;
	int *testArr = new int[length] {};
	initArray(testArr, length);
	printArray(testArr, length);
	countSort(testArr, length);
	printf("Array after CountSort:");
	printArray(testArr, length);
	return isSorted(testArr, length);
}

int main()
{
	srand(time(nullptr));
	printf("\n\nRunning more tests....\n\n\n\n");
	testBubbleSort();
	testCountSort();
	int length = 0;
	printf("Enter array's length: ");
	scanf("%d", &length);
	int *arr = new int[length] {};
	initArray(arr, length);
	printf("\nThe array:");
	printArray(arr, length);
	bubbleSort(arr, length);
	printf("The array after Bubble Sort:");
	printArray(arr, length);
	printf("Shuffling array...\n");
	initArray(arr, length);
	printf("\nThe array:");
	printArray(arr, length);
	countSort(arr, length);
	printf("The array after Count Sort:");
	printArray(arr, length);
	delete[] arr;
	return 0;
}
