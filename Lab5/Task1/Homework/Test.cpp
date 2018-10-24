#include "Test.hpp"

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
}

void sort(int* array, int low, int high)
{
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		sort(array, low, mid);
		sort(array, mid + 1, high);
		merge(array, low, high, mid);
	}
}

bool test()
{
	printf("�������� �����!");
	srand(time(nullptr));

	SortedList testList;
	removeElement(1, testList);

	int *testElements = new int[100]{};
	for (int i = 0; i < 100; ++i)
	{
		testElements[i] = rand() % 1000 - 500;
		addElement(testElements[i], testList);
	}

	if (testList.count != 100)
	{
		printf("������ �������� ��������� � ������!\n");
		return false;
	}

	sort(testElements, 0, 99);

	for (int i = 0; i < 100; ++i)
	{
		if (testElements[i] != testList.storage[i])
		{
			printf("������ �� ���������������!\n");
			return false;
		}
	}

	removeElement(testElements[99], testList);

	for (int i = 0; i < 99; ++i)
	{
		if (testElements[i] != testList.storage[i])
		{
			printf("������ � ������� ��������!\n");
			return false;
		}
	}
	system("cls");
	printf("� ���� ������ ������ �� ��������!\n");
	return true;
}