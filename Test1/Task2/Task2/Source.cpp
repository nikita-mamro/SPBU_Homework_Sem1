#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int* initArray(int length)
{
	int* arr = new int[length] {};
	for (int i = 0; i < length; ++i)
	{
		arr[i] = rand() % 100 - 50;
	}
	return arr;
}

void printArray(int *arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void selectionSort(int *theArray, int length)
{
	int minIndex = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < length; ++j)
		{
			if (theArray[j] < theArray[minIndex])
			{
				minIndex = j;
			}
		}
		swap(theArray[minIndex], theArray[i]);
	}
}

bool isSorted(int *theArray, int length)
{
	for (int i = 0; i < length - 1; ++i)
	{
		if (theArray[i] > theArray[i + 1])
		{
			printf("Тест не пройден!\n");
			delete[] theArray;
			return false;
		}
	}
	delete[] theArray;
	printf("Тест пройден!\n\n");
	return true;
}

bool test()
{
	int length = 10;
	int* testArray = initArray(length);
	printf("Изначальный массив: \n");
	printArray(testArray, length);
	selectionSort(testArray, length);
	printArray(testArray, length);
	return isSorted(testArray, length);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	printf("Проводим тесты...\n\n");
	test();
	test();
	int *theArray = new int[10]{};
	printf("Введите 10 элементов массива:\n");
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &theArray[i]);
	}
	printf("Ваш массив: \n");
	printArray(theArray, 10);
	selectionSort(theArray, 10);
	printf("\nОтсортированный массив: \n");
	printArray(theArray, 10);
	delete[] theArray;
	return 0;
}