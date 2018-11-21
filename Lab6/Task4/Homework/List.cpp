#define _CRT_SECURE_NO_WARNINGS
#include "List.hpp"
#include "ContactStruct.hpp"
#include <vector>

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
	}

	list->tail->next = node;
	list->tail = node;
	++list->length;
}

void appendList(List * listA, List * listB)
{
	while (head(listB) != nullptr)
	{
		Contact *contact = headContact(listB);
		Node *node = createNode(*contact);
		add(listA, node);
		extractHead(listB);
	}
}

void extractHead(List * list)
{
	if (list->length == 1)
	{
		list->head->next = nullptr;
		list->head = nullptr;
		list->tail = nullptr;
		--list->length;
	}
	else
	{
		Node *tmp = list->head;
		list->head = list->head->next;
		delete tmp;
		--list->length;
	}
}

Node * cmpNames(Node * nodeA, Node * nodeB)
{
	string nameA = nodeA->contact.name;
	string nameB = nodeB->contact.name;
	return nameA <= nameB ? nodeA : nodeB;
}

Node * cmpPhoneNumbers(Node * nodeA, Node * nodeB)
{
	string phoneA = nodeA->contact.phone;
	string phoneB = nodeB->contact.phone;
	return phoneA <= phoneB ? nodeA : nodeB;
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
	return list->head == nullptr;
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

int getLength(List *list)
{
	return list->length;
}

List *firstHalf(List *list)
{
	List *res = createList();
	int length = list->length / 2;
	
	Node *current = list->head;
	vector <Contact*> contacts;
	char name[20] = " ";
	char phone[20] = " ";
	
	for (int i = 0; i < length; ++i)
	{
		strcpy(name, current->contact.name);
		strcpy(phone, current->contact.phone);
		Contact *contact = new Contact();
		strcpy(contact->name, name);
		strcpy(contact->phone, phone);
		contacts.push_back(contact);
		current = current->next;
	}

	for (int i = 0; i < length; ++i)
	{
		Node *node = createNode(*contacts[i]);
		add(res, node);
	}
	
	return res;
}

List *secondHalf(List *list)
{
	List *res = createList();
	int length = list->length / 2;

	Node *current = list->head;

	for (int i = 0; i < length; ++i)
	{
		current = current->next;
	}

	vector <Contact*> contacts;
	char name[20] = " ";
	char phone[20] = " ";

	while (current != nullptr)
	{
		strcpy(name, current->contact.name);
		strcpy(phone, current->contact.phone);
		Contact *contact = new Contact();
		strcpy(contact->name, name);
		strcpy(contact->phone, phone);
		contacts.push_back(contact);
		current = current->next;
	}

	for (int i = 0; i < list->length - length; ++i)
	{
		Node *node = createNode(*contacts[i]);
		add(res, node);
	}

	return res;
}

Contact *priotityNameContact(Node *nodeA, Node *nodeB)
{
	Node *res = cmpNames(nodeA, nodeB);
	return &res->contact;
}

Contact *priotityPhoneContact(Node *nodeA, Node *nodeB)
{
	Node *res = cmpPhoneNumbers(nodeA, nodeB);
	return &res->contact;
}

Node *head(List *list)
{
	if (list == nullptr)
	{
		return nullptr;
	}
	return list->head;
}

Contact *headContact(List *list)
{
	return &list->head->contact;
}