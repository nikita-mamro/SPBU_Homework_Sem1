#pragma once
#include <string>
#include <cstring>
#include "ContactStruct.hpp"

struct Node;

struct List;

Node *createNode(Contact contact, Node *next = nullptr);

List *createList();

void add(List *list, Node *node);

Node *cmpNames(Node *nodeA, Node *nodeB);

Node *cmpPhoneNumbers(Node *nodeA, Node *nodeB);

void printList(List * list);

void deleteList(List * list);