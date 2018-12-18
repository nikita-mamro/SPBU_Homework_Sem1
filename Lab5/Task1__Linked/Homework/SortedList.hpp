#pragma once

struct ListElement;

struct SortedList;

SortedList *createList();
bool isEmpty(const SortedList &list);
ListElement *newListElement(int element, ListElement *listElement);
ListElement *lastLessThanCurrent(int element, const SortedList &list);
void printSortedList(const SortedList &list);
void addElement(int element, SortedList &list);
void removeElement(int element, SortedList &list);
void deleteSortedList(SortedList *&list);
bool isContained(int element, const SortedList &list);
ListElement *getHead(const SortedList &list);
int getElementData(const ListElement *element);
ListElement * getNext(const ListElement *element);