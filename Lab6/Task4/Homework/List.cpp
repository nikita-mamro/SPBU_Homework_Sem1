#define _CRT_SECURE_NO_WARNINGS
#include "List.hpp"
#include "ContactStruct.hpp"

struct Node
{
	Contact contact;
	Node *next;
};

struct List
{
	Node *head;
	Node *tail;
	int length;
};

Node *createNode(Contact contact, Node *next)
{
	return new Node{ contact , next };
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

Node *extractHead(List * list)
{
	if (list == nullptr || list->head == nullptr)
	{
		return nullptr;
	}
	if (list->head == list->tail)
	{
		list->tail = nullptr;
	}

	Node *res = list->head;
	list->head = list->head->next;
	res->next = nullptr;
	--list->length;

	return res;
}

int cmpNames(Node *nodeA, Node *nodeB)
{
	return strcmp(nodeA->contact.name, nodeB->contact.name);
}

int cmpPhoneNumbers(Node *nodeA, Node *nodeB)
{
	return strcmp(nodeA->contact.phone, nodeB->contact.phone);
}

void printList(List *list)
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
		cout << tmp->contact.name << " - " << tmp->contact.phone << endl;
		tmp = tmp->next;
	}

	cout << endl << endl;
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

List *merge(List *listA, List *listB, bool sortBy)
{
	List* res = createList();

	Node* nodeA = extractHead(listA);
	Node* nodeB = extractHead(listB);

	while (nodeA != nullptr && nodeB != nullptr) 
	{
		int cmp = (sortBy == 0 ? cmpNames(nodeA, nodeB) : cmpPhoneNumbers(nodeA, nodeB));

		if (cmp < 0) 
		{
			add(res, nodeA);
			nodeA = extractHead(listA);
		}
		else if (cmp > 0)
		{
			add(res, nodeB);
			nodeB = extractHead(listB);
		}
		else
		{
			add(res, nodeA);
			add(res, nodeB);
			nodeA = extractHead(listA);
			nodeB = extractHead(listB);
		}
	}

	add(res, nodeA);
	appendList(res, listA);
	add(res, nodeB);
	appendList(res, listB);
	deleteList(listA);
	deleteList(listB);
	return res;
}

void mergeSort(List *&list, bool sortBy)
{
	int length = list->length;
	List **merged = new List*[length];

	for (int i = 0; i < length; ++i)
	{
		merged[i] = createList(extractHead(list));
	}

	deleteList(list);

	while (length > 1)
	{
		for (int i = 0; i < length; i += 2)
		{
			List *listA = merged[i];
			merged[i] = nullptr;
			List *listB = createList();

			if (i + 1 < length)
			{
				listB = merged[i + 1];
				merged[i + 1] = nullptr;
			}

			merged[i / 2] = merge(listA, listB, sortBy);
		}

		length = length / 2 + length % 2;
	}

	List *res = createList();

	res = merged[0];
	merged[0] = nullptr;

	for (int i = 0; i < length; ++i)
	{
		deleteList(merged[i]);
	}

	delete[] merged;
	list = res;
}
