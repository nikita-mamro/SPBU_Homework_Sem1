#define _CRT_SECURE_NO_WARNINGS
#include "Module.h"

void swap(int &a, int&b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int getLength()
{
	FILE *file = fopen("text.txt", "r");
	if (!file) {
		printf("file not found!");
		return 0;
	}
	int *data[100] = {};
	int linesRead = 0;
	while (!feof(file)) {
		int *buffer = new int[100];
		const int readBytes = fscanf(file, "%d", buffer);
		if (readBytes < 0) {
			break;
		}
		data[linesRead] = buffer;
		++linesRead;
	}
	fclose(file);
	return *data[0];
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

int* initArray(int length)
{
	int* newArray = new int[length];
	for (int i = 0; i < length; ++i)
	{
		newArray[i] = rand() % 100;
	}
	return newArray;
}

void quickSort(int* theArray, int firstIndex, int lastIndex)
{
	if (firstIndex >= lastIndex)
	{
		return;
	}
	int index = firstIndex;
	int element = theArray[firstIndex];
	for (int i = firstIndex; i <= lastIndex; ++i)
	{
		if (theArray[i] < element)
		{
			swap(theArray[i], theArray[index]);
			++index;
		}
	}
	if (index == firstIndex)
	{
		++index;
	}
	quickSort(theArray, firstIndex, index - 1);
	quickSort(theArray, index, lastIndex);
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