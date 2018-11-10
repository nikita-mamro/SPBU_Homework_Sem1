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
	printf("Из текстового документа получена длина: %d\n\n", length);
	int *myArray = initArray(length);
	printf("Ваш массив:");
	printArray(myArray, length);
	int result = mostFrequentElement(myArray, length);
	printf("Наиболее часто встречающийся элемент: %d\n\n", result);
	delete[] myArray;
	return 0;
}