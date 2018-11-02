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
		arr[i] = rand() % 100 + 1;
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

void sort(int* arr, int length)
{
	int element = arr[0];
	int index = 0;
	for (int i = 1; i < length; ++i)
	{
		if (arr[i] < element)
		{
			swap(arr[i], arr[index]);
			++index;
		}
	}
}

bool testSort()
{
	int length = rand() % 100;
	int *arr = initArray(length);
	int firstElement = arr[0];
	sort(arr, length);
	int i = 0;
	while (arr[i] <= firstElement)
	{
		++i;
	}
	while (i < length)
	{
		if (arr[i] < firstElement)
		{
			printf("Test failed!\n");
			delete[] arr;
			return false;
		}
		++i;
	}
	printf("Passed test!\n");
	delete[] arr;
	return true;
}

int main()
{
	srand(time(NULL));
	printf("Testing algorithm...\n");
	testSort();
	testSort();
	testSort();
	testSort();
	testSort();
	int length = 0;
	printf("Input the length of an array, please: ");
	scanf("%d", &length);
	int *arr = initArray(length);
	printArray(arr, length);
	sort(arr, length);
	printf("Sorted by first element:\n");
	printArray(arr, length);
	delete[] arr;
	return 0;
}