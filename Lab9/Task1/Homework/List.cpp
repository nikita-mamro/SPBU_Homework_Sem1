#define _CRT_SECURE_NO_WARNINGS
#include "List.hpp"
#include <string>
#include <iostream>

using namespace std;

struct Node
{
	string word;
	int counter;
	bool isRehashed;
	Node *next;
};

struct List
{
	Node *head;
	Node *tail;
	int length;
};

Node *createNode(const string & word, int counter, Node *next)
{
	return new Node{ word, counter, false, next };
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
	if (exists(list, node->word))
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

void remove(List * list, Node * node)
{
	if (!list || !exists(list, node->word))
	{
		--list->length;
		return;
	}

	if (list->head->word == node->word)
	{
		Node *tmp = list->head;
		list->head = tmp->next;
		delete tmp;
		--list->length;
		return;
	}

	Node *before = list->head;

	while (before->next != node)
	{
		before = before->next;
	}

	Node *tmp = before->next;

	before->next = tmp->next;
	--list->length;
	delete tmp;
}

void setCounter(List * list, const string & word, int newValue)
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

	current->counter = newValue;
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
	if (list == nullptr)
	{
		return false;
	}

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

int getCounter(Node * node)
{
	return node->counter;
}

int getLength(List * list)
{
	return list->length;
}

string getWord(Node * node)
{
	return node->word;
}

bool isRehashed(Node * node)
{
	return node->isRehashed;
}

Node * getHead(List * list)
{
	return list ? list->head : nullptr;
}

Node * next(Node * node)
{
	return node->next;
}

void setIsRehashed(Node * node, bool newValue)
{
	node->isRehashed = newValue;
}
