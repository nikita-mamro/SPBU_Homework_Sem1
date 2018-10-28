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

ListElement *newListElement(int, ListElement*);
ListElement *lastLessThanCurrent(int, SortedList&);
void printSortedList(SortedList&);
void addElement(int, SortedList&);
void removeElement(int, SortedList&);
void deleteSortedList(SortedList&);
bool isContained(int, SortedList&);