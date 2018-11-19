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

void add(List *list, Node *node)
{
	if (node == nullptr)
	{
		return;
	}

	if (list->head == nullptr)
	{
		node->next = list->head;
		list->head = node;

		list->tail = node;

		list->length++;
	}

	list->tail = node;
	list->length++;
}

Node * cmpNames(Node * nodeA, Node * nodeB)
{
	string nameA = nodeA->contact.name;
	string nameB = nodeB->contact.name;
	return nameA >= nameB ? nodeA : nodeB;
}

Node * cmpPhoneNumbers(Node * nodeA, Node * nodeB)
{
	string phoneA = nodeA->contact.phone;
	string phoneB = nodeB->contact.phone;
	return phoneA >= phoneB ? nodeA : nodeB;
}

void printList(List *list)
{
	if (list->head == nullptr || list == nullptr)
	{
		cout << "The list is empty." << endl;
		return;
	}

	Node *tmp = list->head;

	while (tmp != nullptr)
	{
		cout << tmp->contact.name << " - " << tmp->contact.phone << endl;
		tmp = tmp->next;
	}
}

void deleteList(List *list)
{
	if (list->head == nullptr)
	{
		return;
	}

	Node *tmp = list->head;

	while (tmp != nullptr) 
	{
		Node *ttmp = tmp;
		tmp = tmp->next;
		delete ttmp;
	}

	delete list;
	list = nullptr;
}