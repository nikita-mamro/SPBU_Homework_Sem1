#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool isSimple(int a)
{
	for (int i = 2; i < a / 2 + 1; ++i) {
		if (a % i == 0)
			return false;
	}
	return true;
}

int main()
{
	printf("Input your number: ");
	int n = 0;
	scanf("%d", &n);

	for (int i = 2; i < n; ++i) {
		if (isSimple(i)) {
			printf("%d\n", i);
		}
	}

	return 0;
}
