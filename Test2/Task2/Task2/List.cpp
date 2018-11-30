#include "List.hpp"
#include <fstream>
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *previous;
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

void fill(List *list) {
	ifstream fin;
	fin.open("text.txt");

	if (fin.is_open()) {
		while (!fin.eof()) {
			int num = 0;
			fin >> num;
			add(list, createNode(num));
		}
	}

	fin.close();
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
	node->previous = list->tail;
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
		cout << tmp->data;
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

bool checkList(List *list)
{
	Node *left = list->head;
	Node *right = list->tail;
	
	for (int i = 0; i < list->length / 2; ++i)
	{
		if (left->data != right->data)
		{
			return false;
		}
		right = right->previous;
		left = left->next;
	}

	return true;
}
