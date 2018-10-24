#pragma once

#include <stdio.h>

struct SortedList
{
	int *storage = new int[10]{0};
	int capacity = 10;
	int count = 0;
};

void printSortedList(SortedList&);
int *initStorage(int);
void expandList(SortedList&);
void shrinkList(SortedList&);
void addElement(int, SortedList&);
void removeElement(int, SortedList&);