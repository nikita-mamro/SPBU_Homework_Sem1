#pragma once
#include <string>

struct Node;

struct List;

Node* createNode(Contact contact, Node *next = nullptr);

List* createList();

void addElement(List *list, Node *node);

Node* cmpNames(Node *nodeA, Node *nodeB);

//List* listCreate(Node* node);

//int listLength(List* list);

//void listAddFirst(List* list, Node* node);

//void listAppend(List* list, Node* node);

//void listAppend(List* list, List* append);

//Node* listExtractFirst(List* list);

void printList(List * list);

void deleteList(List * list);