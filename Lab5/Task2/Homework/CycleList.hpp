#pragma once

#include "stdafx.hpp"

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

void printCycleList(CycleList&);
void addElement(int, CycleList&);
void kill(int, CycleList&);
void deleteList(CycleList&);
ListElement *newElement(int, ListElement*);