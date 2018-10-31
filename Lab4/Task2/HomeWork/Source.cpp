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
	printf("Первое число в данном на обработку текстовом документе - длина массива.\n");
	int length = getLength();
	printf("Из текстового документа получена длина: %d\n\n", length);
	int* myArray = initArray(length);
	printf("Ваш массив:");
	printArray(myArray, length);
	int result = mostFrequentElement(myArray, length);
	printf("Наиболее часто встречающийся элемент: %d", result);
	return 0;
}