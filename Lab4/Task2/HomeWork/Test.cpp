#include "Test.hpp"
#include "stdafx.hpp"
#include "ArrayFunctions.hpp"
#include "SortAndFind.hpp"

void test()
{
	printf("���������...\n\n");
	int* testArray = new int[16]{ 100, 8123, 31, 8213, 52, 3, 8123, 3, 24803, 24803, 3, 1, 90, 90, 8123, 8123 };
	printArray(testArray, 16);
	int result = mostFrequentElement(testArray, 16);
	printf("������������ �������: %d\n", result);
	result == 8123 ? printf("���� �������!\n\n") : printf("���� �� �������, ����� 8123\n\n");
	delete[] testArray;
}