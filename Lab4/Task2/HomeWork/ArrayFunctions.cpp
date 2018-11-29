#define _CRT_SECURE_NO_WARNINGS
#include "ArrayFunctions.hpp"
#include "stdafx.hpp"

int getLength()
{
	int res = 0;
	int tmp = 0;

	FILE *file = fopen("text.txt", "r");

	while (!feof(file))
	{
		fscanf(file, "%d", &tmp);
		++res;
	}

	fclose(file);
	return res;
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
	int *res = new int[length] {0};
	FILE *file = fopen("text.txt", "r");

	for (int i = 0; i < length; ++i)
	{
		fscanf(file, "%d", &res[i]);
	}

	fclose(file);
	return res;
}