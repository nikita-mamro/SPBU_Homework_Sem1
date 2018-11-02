#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int a = 0;
	int b = 0;
	printf("Input dividend: ");
	scanf("%d", &a);
	while (b == 0) {
		printf("Input divider: ");
		scanf("%d", &b);
		if (b == 0) {
			printf("Divider can't be ecual to 0!\n");
		}
	}
	int counter = 0;
	bool negative = false;
	if (a < 0 && b > 0 || a > 0 && b < 0) {
		negative = true;
	}
	a = abs(a);
	b = abs(b);
	int absInitialB = b;
	while (b <= a) {
		b += absInitialB;
		++counter;
	}
	if (negative) {
		counter *= -1;
	}
	printf("Answer is %d", counter);
	return 0;
}