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
//Добавление ноды в список.
void add(List *list, Node *node);
//Склеивание списоков.
void appendList(List *listA, List *listB);
//Удаление первого элемента из списка.
void extractHead(List *list);
//Вернуть ноду, в которой содержится имя, идущее 2ым в алфавитном порядке.
Node *cmpNames(Node *nodeA, Node *nodeB);
//Вернуть ноду, в которой содержится номер, идущий 2ым в порядке сравнения.
Node *cmpPhoneNumbers(Node *nodeA, Node *nodeB);
//Печать списка.
void printList(List * list);
//Проверка, пустой ли список.
bool isEmpty(List *list);
//Удаление списка.
void deleteList(List * list);
//Получить длину.
int getLength(List *list);
//Получить 2 половины.
List *firstHalf(List *list);
List *secondHalf(List *list);