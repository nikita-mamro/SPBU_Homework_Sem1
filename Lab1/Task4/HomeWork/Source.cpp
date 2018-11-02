#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[28] = {};
	int res = 0;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				++arr[i + j + k];
			}
		}
	}

	for (int i = 0; i < 28; ++i) {
		res += arr[i] * arr[i];
	}

	printf("The result is: %d\n", res);

	return 0;
}