#include "Test.hpp"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void merge(int* array, int low, int high, int mid)
{
	int i, j, k;
	int *temp = new int[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high) {
		if (array[i] < array[j]) {
			temp[k] = array[i];
			k++;
			i++;
		}
		else {
			temp[k] = array[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		temp[k] = array[i];
		k++;
		i++;
	}

	while (j <= high) {
		temp[k] = array[j];
		k++;
		j++;
	}

	for (i = low; i <= high; i++) {
		array[i] = temp[i - low];
	}

	delete[] temp;
}

void sort(int* array, int low, int high)
{
	int mid = 0;
	if (low < high) {
		mid = (low + high) / 2;
		sort(array, low, mid);
		sort(array, mid + 1, high);
		merge(array, low, high, mid);
	}
}

bool test()
{
	printf("Проводим тесты!");
	srand(time(nullptr));

	SortedList testList;
	removeElement(1, testList);

	int *testElements = new int[100]{};
	for (int i = 0; i < 99; ++i)
	{
		testElements[i] = rand() % 1000 - 500;
		addElement(testElements[i], testList);
	}

	testElements[99] = 1000;
	addElement(1000, testList);

	sort(testElements, 0, 99);
	ListElement *currentElement = testList.head;

	for (int i = 0; i < 100; ++i)
	{
		if (testElements[i] != currentElement->data)
		{
			printf("Список НЕ отсортированный!\n");
			return false;
		}
		currentElement = currentElement->next;
	}

	removeElement(testElements[99], testList);
	currentElement = testList.head;

	for (int i = 0; i < 99; ++i)
	{
		if (testElements[i] != currentElement->data)
		{
			printf("Ошибка в функции удаления!\n");
			return false;
		}
		currentElement = currentElement->next;
	}
	system(CLEAR);
	printf("В ходе тестов ошибки не выявлены!\n");
	delete[] testElements;
	deleteSortedList(testList);
	return true;
}