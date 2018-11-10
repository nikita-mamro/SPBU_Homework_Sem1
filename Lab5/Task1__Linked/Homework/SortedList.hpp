#pragma once

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

bool isEmpty(SortedList &list);
ListElement *newListElement(int element, ListElement *listElement);
ListElement *lastLessThanCurrent(int element, SortedList &list);
void printSortedList(SortedList &list);
void addElement(int element, SortedList &list);
void removeElement(int element, SortedList &list);
void deleteSortedList(SortedList &list);
bool isContained(int element, SortedList &list);