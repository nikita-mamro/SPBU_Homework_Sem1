#define _CRT_SECURE_NO_WARNINGS
#include "List.hpp"
#include <string>
#include <iostream>

using namespace std;

struct Node
{
	string word;
	int counter;
	Node *next;
};

struct List
{
	Node *head;
	Node *tail;
	int length;
};

Node *createNode(const string & word, Node *next)
{
	return new Node{ word, 0, next };
}

List *createList()
{
	return new List{ nullptr, nullptr, 0 };
}

List *createList(Node * node)
{
	return new List{ node, node, 0 };
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

void changeCounter(List * list, const string & word, int delta)
{
	if (!exists(list, word))
	{
		return;
	}

	Node *current = list->head;

	while (current->word != word)
	{
		current = current->next;
	}

	current->counter += delta;
}

bool exists(List * list, const string & word)
{
	Node *current = list->head;

	while (current != nullptr)
	{
		if (current->word == word)
		{
			return true;
		}
		current = current->next;
	}

	return false;
}

bool isEmpty(List *list)
{
	return list == nullptr || list->head == nullptr;
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

int getLength(List * list)
{
	return list->length;
}

void printList(List * list)
{
	Node *current = list->head;
	
	while (current != nullptr)
	{
		printf("%s - %d\n", current->word, current->counter);
	}
}
