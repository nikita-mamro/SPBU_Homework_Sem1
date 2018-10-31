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
		arr[i] = rand() % 1000000001;
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

bool isContained(int element, int *myArray, int start, int end)
{
	if (start > end)
	{
		return false;
	}
	if (element == myArray[(start + end) / 2])
	{
		return true;
	}
	if (element < myArray[(start + end) / 2])
	{
		return isContained(element, myArray, start, (start + end) / 2 - 1);
	}
	else
	{
		return isContained(element, myArray, (start + end) / 2 + 1, end);
	}
}

bool test()
{
	int count = 0;
	int x = 0;
	int* testBaseArray = new int[10] { 1 , 234231, 1765, 88950, 3660694, 279182, 190365, 18924691, 542, 9324809 };
	int* testElementsArray = new int[4] { 18924691, 1412, 999999999, 3660694 };
	printf("Looking for these elements:\n");
	printArray(testElementsArray, 4);
	printf("Among these:\n");
	printArray(testBaseArray, 10);
	for (int i = 0; i < 4; ++i)
	{
		if (isContained(testElementsArray[i], testBaseArray, 0, 9))
		{
			count++;
			x = testElementsArray[i];
		}
	}
	printf("Elements found: %d, the last element found is: %d", count, x);
	if (count == 2 && x == 3660694)
	{
		printf("\nPassed teh test!\n\n");
		delete[] testBaseArray;
		delete[] testElementsArray;
		return true;
	}
	else
	{
		printf("\nFailed the test!\n\n");
		delete[] testBaseArray;
		delete[] testElementsArray;
		return false;
	}
}

int main()
{
	printf("Running tests...\n");
	test();
	srand(time(nullptr));
	int n = 0;
	int k = 0;
	printf("Input n: ");
	scanf("%d", &n);
	int length = n;
	printf("Input k: ");
	scanf("%d", &k);
	int *arr = initArray(n);
	printArray(arr, length);
	quickSort(arr, 0, length - 1);
	int el = 0;
	for (int i = 0; i < k; ++i)
	{
		el = rand() % 1000000001;
		if (isContained(el, arr, 0, length - 1))
		{
			printf("Found %d\n", el);
		}
		else
		{
			printf("%d not found\n", el);
		}
	}
	delete[] arr;
	return 0;
}
