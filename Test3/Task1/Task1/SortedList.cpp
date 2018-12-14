#include "SortedList.hpp"

bool isContained(int element, SortedList &list)
{
	ListElement *currentElement = list.head;

	while (currentElement != nullptr)
	{
		if (currentElement->data == element)
		{
			return true;
		}
		currentElement = currentElement->next;
	}

	return false;
}

int getCount(int element, SortedList & list)
{
	ListElement* previousElement = lastLessThanCurrent(element, list);
	return previousElement->next->count;
}

bool isSorted(SortedList & list)
{
	ListElement *currentElement = list.head;

	while (currentElement->next != nullptr)
	{
		if (currentElement->data > currentElement->next->data)
		{
			return false;
		}
		currentElement = currentElement->next;
	}

	return true;
}

bool isEmpty(SortedList &list)
{
	return list.head == nullptr;
}

ListElement *newListElement(int data, ListElement *nextElement)
{
	ListElement *result = new ListElement;
	result->data = data;
	result->count = 1;
	result->next = nextElement;
	return result;
}

ListElement* lastLessThanCurrent(int element, SortedList &list)
{
	if (list.head == nullptr || list.head->data >= element)
	{
		return nullptr;
	}

	ListElement *previousElement = list.head;

	while (previousElement->next != nullptr && previousElement->next->data < element)
	{
		previousElement = previousElement->next;
	}

	return previousElement;
}

void addElement(int element, SortedList &list)
{
	if (element == 0)
	{
		return;
	}

	ListElement* previousElement = lastLessThanCurrent(element, list);

	if (isContained(element, list))
	{
		if (previousElement == nullptr)
		{
			++list.head->count;
			return;
		}

		++previousElement->next->count;
		return;
	}
	if (previousElement != nullptr)
	{
		previousElement->next = newListElement(element, previousElement->next);
	}
	else
	{
		list.head = newListElement(element, list.head);
	}
}

void printSortedList(SortedList &list)
{
	ListElement *currentElement = list.head;

	if (currentElement == nullptr)
	{
		printf("EMPTY!\n");
	}
	else
	{
		while (currentElement != nullptr)
		{
			printf("%d - %d\n", currentElement->data, currentElement->count);
			currentElement = currentElement->next;
		}
		printf("\n");
	}
}

void deleteSortedList(SortedList &list)
{
	while (!isEmpty(list))
	{
		ListElement *currentElement = list.head;
		list.head = currentElement->next;
		delete currentElement;
	}
}