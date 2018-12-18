#include "SortedList.hpp"

#include <stdio.h>

struct ListElement
{
	int data;
	ListElement *next = nullptr;
};

struct SortedList
{
	ListElement *head = nullptr;
};

bool isContained(int element, const SortedList &list)
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

ListElement * getHead(const SortedList & list)
{
	return list.head;
}

int getElementData(const ListElement * element)
{
	return element->data;
}

ListElement * getNext(const ListElement * element)
{
	return element->next;
}

int getElementData(const ListElement & element)
{
	return element.data;
}

SortedList * createList()
{
	return new SortedList;
}

bool isEmpty(const SortedList &list)
{
	return list.head == nullptr;
}

ListElement *newListElement(int data, ListElement *nextElement)
{
	ListElement *result = new ListElement;
	result->data = data;
	result->next = nextElement;
	return result;
}

ListElement* lastLessThanCurrent(int element, const SortedList &list)
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
	ListElement* previousElement = lastLessThanCurrent(element, list);
	if (previousElement != nullptr)
	{
		previousElement->next = newListElement(element, previousElement->next);
	}
	else
	{
		list.head = newListElement(element, list.head);
	}
	printf("Добавлен элемент %d!\n", element);
}

void removeElement(int element, SortedList &list)
{
	if (!isContained(element, list))
	{
		printf("Элемент не найден!\n");
		return;
	}

	if (list.head == nullptr)
	{
		return;
	}

	ListElement *previousElement = lastLessThanCurrent(element, list);

	if (previousElement == nullptr)
	{
		while (list.head != nullptr && list.head->data == element)
		{
			ListElement *tmp = list.head;
			list.head = list.head->next;
			delete tmp;
		}
	}
	else
	{
		while (previousElement->next != nullptr && previousElement->next->data == element)
		{
			ListElement *tmp = previousElement->next;
			previousElement->next = tmp->next;
			delete tmp;
		}
	}
	printf("Удалён элемент %d!\n", element);
}

void printSortedList(const SortedList &list)
{
	ListElement *currentElement = list.head;

	if (currentElement == nullptr)
	{
		printf("Нет элементов!\n");
	}
	else
	{
		while (currentElement != nullptr)
		{
			printf("%d ", currentElement->data);
			currentElement = currentElement->next;
		}
		printf("\n");
	}
}

void deleteSortedList(SortedList *&list)
{
	while (!isEmpty(*list))
	{
		ListElement *currentElement = list->head;
		list->head = currentElement->next;
		delete currentElement;
	}
	delete list;
}