#pragma once

struct Node;

struct List;

List *createList();
Node *createNode(int data, Node *next = nullptr);

void add(List *list, Node *node);

bool isEmpty(List *list);

void printList(List *list);

void deleteList(List *list);

void readFromFile(List *list);

void writeToFile(List *list);

void appendList(List * listA, List * listB);

List *proceedTask(List *list, int a, int b);