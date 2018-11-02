#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int length = 0;
	printf("Input array length: ");
	scanf("%d", &length);

	int* arr = new int[length];

	for (int i = 0; i < length; ++i) {
		scanf("%d", &arr[i]);
	}

	int zeroCounter = 0;

	for (int i = 0; i < length; ++i) {
		if (arr[i] == 0) {
			++zeroCounter;
		}
	}

	delete[] arr;

	printf("Number of 0's in array: %d", zeroCounter);

	return 0;
}
