#pragma once

#include "List.hpp"
#include <fstream>
#include <iostream>

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

void writeToFile(List *list)
{
	ofstream fout;
	fout.open("output.txt");

	Node *current = list->head;

	while (current != nullptr)
	{
		fout << current->data << " ";
		current = current->next;
	}

	fout.close();
}

void appendList(List * listA, List * listB)
{
	if (listB == nullptr || listB->head == nullptr)
	{
		return;
	}
	listA->tail->next = listB->head;
	listA->tail = listB->tail;
	listA->length += listB->length;
	listB->head = nullptr;
	listB->tail = nullptr;
	listB->length = 0;
}

List *proceedTask(List *list, int a, int b)
{
	List *lessThanA = createList();
	List *fromAtoB = createList();
	List *moreThanB = createList();

	Node *current = list->head;

	while (current != nullptr)
	{
		if (current->data < a)
		{
			add(lessThanA, createNode(current->data));
		}
		current = current->next;
	}

	current = list->head;

	while (current != nullptr)
	{
		if (current->data >= a && current->data <= b)
		{
			add(fromAtoB, createNode(current->data));
		}
		current = current->next;
	}

	current = list->head;

	while (current != nullptr)
	{
		if (current->data > b)
		{
			add(moreThanB, createNode(current->data));
		}
		current = current->next;
	}

	List *res = createList();

	res = lessThanA;
	appendList(res, fromAtoB);
	appendList(res, moreThanB);

	return res;
}

bool testListFunc(List * list, int a, int b)
{
	Node *current = list->head;

	while (current->data < a && current != nullptr)
	{
		current = current->next;
	}
	while (current->data < b && current != nullptr)
	{
		if (current->data < a)
		{
			return false;
		}
		current = current->next;
	}
	while (current != nullptr)
	{
		if (current->data < b)
		{
			return false;
		}
		current = current->next;
	}

	return true;
}
