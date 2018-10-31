#define _CRT_SECURE_NO_WARNINGS
#include "Module.h"

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