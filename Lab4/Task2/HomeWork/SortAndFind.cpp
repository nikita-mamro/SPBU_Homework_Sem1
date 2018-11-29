#include "SortAndFind.hpp"
#include "stdafx.hpp"

void swap(int &a, int&b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
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