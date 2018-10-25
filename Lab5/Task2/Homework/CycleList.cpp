#include "CycleList.hpp"

void printCycleList(CycleList &list)
{
	if (list.length == 0)
	{
		printf("Список пустой!\n");
	}
	else
	{
		ListElement *currentElement = list.head;
		for (int i = 0; i < list.length; ++i)
		{
			printf("%d", currentElement->data);
			currentElement = currentElement->next;
		}
		printf("\n");
	}
}

void addElement(int data, CycleList &list)
{
	if (list.length == 0)
	{
		list.head = newElement(data, nullptr);
		list.head->next = list.head;
		list.tail = list.head;
	}
	else
	{
		list.tail->next = newElement(data, list.tail->next);
		list.tail = list.tail->next;
	}
	++list.length;
}

void kill(int pos, CycleList &list)
{
	ListElement* listElement = list.tail;
	while (listElement->next != listElement)
	{
		for (int i = 0; i < pos; ++i)
		{
			listElement = listElement->next;
		}
		ListElement* tmpListElement = listElement->next;
		listElement->next = tmpListElement->next;
		delete tmpListElement;
	}
	list.head = listElement;
	list.tail = listElement;
}

ListElement *newElement(int data, ListElement *next)
{
	ListElement *result = new ListElement;
	result->data = data;
	result->next = next;
	return result;
}
