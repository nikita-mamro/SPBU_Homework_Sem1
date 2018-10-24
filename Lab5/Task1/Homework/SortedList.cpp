#include "SortedList.hpp"

int *initStorage(int capacity)
{
	int* res = new int[capacity];
	for (int i = 0; i < capacity; i++) res[i] = 0;
	return res;
}

void expandList(SortedList &list)
{
	int newCapacity = list.capacity * 3 / 2;
	int *tmp = initStorage(newCapacity);
	for (int i = 0; i < list.count; ++i)
	{
		tmp[i] = list.storage[i];
	}
	delete[] list.storage;
	list.storage = tmp;
	list.capacity = newCapacity;
}

void shrinkList(SortedList &list)
{
	int newCapacity = list.capacity * 2 / 3;
	int *tmp = initStorage(newCapacity);
	for (int i = 0; i < list.count; ++i)
	{
		tmp[i] = list.storage[i];
	}
	delete[] list.storage;
	list.storage = tmp;
	list.capacity = newCapacity;
}

void addElement(int element, SortedList &list)
{
	if (list.count == list.capacity)
	{
		expandList(list);
	}
	if (list.count == 0)
	{
		list.storage[0] = element;
		++list.count;
		return;
	}
	else
	{
		int position = 0;
		for (int i = 0; i < list.count; ++i)
		{
			if (list.storage[i] >= element)
			{
				break;
			}
			++position;
		}
		for (int i = list.count; i > position; --i)
		{
			list.storage[i] = list.storage[i - 1];
		}
		list.storage[position] = element;
		++list.count;
	}
}

void removeElement(int element, SortedList &list)
{
	if (list.count == 0)
	{
		return;
	}
	else
	{
		int positionToDelete = 0;
		while (list.storage[positionToDelete] != element && positionToDelete < list.capacity)
		{
			++positionToDelete;
		}

		if (positionToDelete == list.capacity)
		{
			printf("%d нет в списке!\n", element);
			return;
		}

		for (int i = positionToDelete; i < list.count - 1; ++i)
		{
			list.storage[i] = list.storage[i + 1];
		}
		printf("Удалён элемент %d!\n", element);
		--list.count;

		if (list.count < list.capacity * 2 / 3)
		{
			shrinkList(list);
		}
	}
}

void printSortedList(SortedList &list)
{
	if (list.count == 0)
	{
		printf("В списке ещё нет элементов!\n");
	}
	else
	{
		printf("Сортированный список:\n");
		for (int i = 0; i < list.count; ++i)
		{
			printf("%d ", list.storage[i]);
		}
		printf("\n");
	}
}
