#pragma once

struct ListElement
{
	int data = 0;
	ListElement *next = nullptr;
};

struct CycleList
{
	ListElement *head = nullptr;
	ListElement *tail = nullptr;
	int length = 0;
};

void printCycleList(const CycleList &list);
void addElement(int data, CycleList &list);
void kill(int pos, CycleList &list);
void deleteList(CycleList &list);
ListElement *newElement(int data, ListElement *element);