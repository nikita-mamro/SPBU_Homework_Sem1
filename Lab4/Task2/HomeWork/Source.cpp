#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.hpp"
#include "ArrayFunctions.hpp"
#include "Test.hpp"
#include "SortAndFind.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	test();
	int length = getLength();
	printf("�� ���������� ��������� �������� �����: %d\n\n", length);
	int *myArray = initArray(length);
	printf("��� ������:");
	printArray(myArray, length);
	int result = mostFrequentElement(myArray, length);
	printf("�������� ����� ������������� �������: %d\n\n", result);
	delete[] myArray;
	return 0;
}