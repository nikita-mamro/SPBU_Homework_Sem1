#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "Module.h"
#include "TestModule.h"
#include "SortAndFind.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	test();
	printf("������ ����� � ������ �� ��������� ��������� ��������� - ����� �������.\n");
	int length = getLength();
	printf("�� ���������� ��������� �������� �����: %d\n\n", length);
	int* myArray = initArray(length);
	printf("��� ������:");
	printArray(myArray, length);
	int result = mostFrequentElement(myArray, length);
	printf("�������� ����� ������������� �������: %d", result);
	return 0;
}