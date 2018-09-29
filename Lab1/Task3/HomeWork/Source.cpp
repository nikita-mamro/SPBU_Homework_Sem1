#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int &a, int &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverseArray(int* arr, int first, int last)
{
	for (int i = first, j = last; i < (first + (last - first) / 2); ++i, --j) {
		swap(arr[i], arr[j - 1]);
	}
}

void printArray(int* arr, int length)
{
	for (int i = 0; i < length; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int n = 0;
	printf("Input n: ");
	scanf("%d", &n);

	int m = 0;
	printf("Input m: ");
	scanf("%d", &m);

	int* arr = new int[n + m];

	for (int i = 0; i < n + m; ++i) {
		arr[i] = i;
	}

	printArray(arr, n + m);
	reverseArray(arr, 0, m);
	reverseArray(arr, m, n + m);
	reverseArray(arr, 0, n + m);
	printArray(arr, n + m);


	delete[] arr;

	return 0;
}
