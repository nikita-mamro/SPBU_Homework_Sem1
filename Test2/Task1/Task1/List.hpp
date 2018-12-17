#pragma once

struct Node;

struct List;

List *createList();
Node *createNode(int data, Node * next = nullptr);

void add(List * list, Node * node);

bool isEmpty(List * list);

void printList(List * list);

void deleteList(List * list);

void readFromFile(List * list);

List * reverseList(List * list);
// Copy listA to listB
void cpyList(List *& listA, List *& listB);
// Check if B is reversed A (for tests)
bool checkReverse(List *listA, List * listB);