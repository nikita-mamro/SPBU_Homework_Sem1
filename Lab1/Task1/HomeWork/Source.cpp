#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int X = 0;
	printf("The formula is: x^4 + x^3 + x^2 + x + 1\n");
	printf("Input X value: ");
	scanf("%d", &X);
	int sqX = X*X;
	int res = (sqX + 1) * (sqX + X) + 1;
	printf("%d^4 + %d^3 + %d^2 + %d + 1 = %d", X, X, X, X, res);
	return 0;
}