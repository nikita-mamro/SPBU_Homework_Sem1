#pragma once
#include <string>
#include <cstring>
#include "ContactStruct.hpp"

struct Node;

struct List;
//Создание ноды.
Node *createNode(Contact contact, Node *next = nullptr);
//Создание списка.
List *createList();
List *createList(Node *node);
//Добавление ноды в список.
void add(List *list, Node *node);
//Склеивание списоков.
void appendList(List *listA, List *listB);
//Удаление первого элемента из списка.
Node *extractHead(List *list);
//Вернуть ноду, в которой содержится имя, идущее 1ым в алфавитном порядке.
int cmpNames(Node *nodeA, Node *nodeB);
//Вернуть ноду, в которой содержится номер, идущий 1ым в порядке сравнения.
int cmpPhoneNumbers(Node *nodeA, Node *nodeB);
//Печать списка.
void printList(List * list);
//Проверка, пустой ли список.
bool isEmpty(List *list);
//Удаление списка.
void deleteList(List *& list);
//Сортировка
List *merge(List *listA, List *listB, bool sortBy);
void mergeSort(List *&list, bool sortBy);
//Тест на отсортированность
bool testSort(List *& list, bool sortBy);