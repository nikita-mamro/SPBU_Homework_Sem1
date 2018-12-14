#pragma once

#include "List.hpp"
#include <fstream>
#include <iostream>
#include <vector> // for tests

using namespace std;

struct Node
{
	int data;
	Node *next;
};

struct List
{
	Node *head;
	Node *tail;
	int length;
};

List *createList()
{
	return new List{ nullptr, nullptr, 0 };
}

Node * createNode(int data, Node * next)
{
	return new Node{ data, next };
}

void add(List *list, Node *node)
{
	if (node == nullptr)
	{
		return;
	}

	if (list->head == nullptr)
	{
		list->head = node;

		list->tail = node;

		++list->length;

		return;
	}

	list->tail->next = node;
	list->tail = node;
	++list->length;
}

bool isEmpty(List *list)
{
	return list == nullptr || list->head == nullptr;
}

void printList(List * list)
{
	if (isEmpty(list))
	{
		cout << "The list is empty." << endl;
		return;
	}

	cout << "The list:" << endl << endl;

	Node *tmp = list->head;

	while (tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl << endl;
}

void deleteList(List *list)
{
	while (!isEmpty(list))
	{
		Node* tmp = list->head;
		list->head = list->head->next;
		delete tmp;
	}
	delete list;
	list = nullptr;
}

void readFromFile(List *list)
{
	ifstream fin;
	fin.open("input.txt");

	if (fin.is_open()) {
		while (!fin.eof()) {
			int num = 0;
			fin >> num;
			add(list, createNode(num));
		}
	}

	fin.close();
}

void cpyList(List *& listA, List *& listB)
{
	Node *current = listA->head;

	while (current != nullptr)
	{
		add(listB, createNode(current->data));
		current = current->next;
	}
}

List *reverseList(List * list)
{
	List *res = createList();

	cpyList(list, res);

	Node *current = res->head;
	Node *previous  = nullptr;
	Node *next = nullptr;


	while (current != nullptr)
	{ 
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	res->head = previous;

	return res;
}

bool checkReverse(List * listA, List * listB)
{
	const int length = listA->length;
	vector <int> listAElements;
	Node *current = listA->head;

	while (current != nullptr)
	{
		listAElements.push_back(current->data);
		current = current->next;
	}

	current = listB->head;

	for (int i = length - 1; i >= 0; --i)
	{
		if (current->data != listAElements[i])
		{
			return false;
		}
		current = current->next;
	}

	return true;
}
