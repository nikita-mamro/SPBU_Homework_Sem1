#include "Test.hpp"

bool test(int n, int m, int correctAnswer)
{
	CycleList testList;

	for (int i = 1; i <= n; ++i)
	{
		addElement(i, testList);
	}

	kill(m, testList);
	int result = testList.head->data;

	if (result != correctAnswer)
	{
		printf("Failed test: m = %d, n = %d\nThe result should be %d, output: %d\n", m, n, correctAnswer, result);
		return false;
	}
	printf("Passed test!\n");
	return true;
}