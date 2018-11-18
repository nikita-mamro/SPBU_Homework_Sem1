#pragma once
#include <string>

struct Node;

struct List;

Node* createNode(Contact contact, Node *next = nullptr);

List* createList();

void addElement(List *list, Node *node);

Node* cmpNames(Node *nodeA, Node *nodeB);

void printList(List * list);

void deleteList(List * list);