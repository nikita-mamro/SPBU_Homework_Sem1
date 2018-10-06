#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

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

}

int main()
{
	srand(time(nullptr));
	int length = 0;
	printf("Input the length of an array: ");
	scanf("%d", &length);
	int *myArray = initArray(length);
	printf("The array is:");
	printArray(myArray, length);
	return 0;
}