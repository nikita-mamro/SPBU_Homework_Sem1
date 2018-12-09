#pragma once

struct Node;

struct List;
// Создание структур
List *createList();
Node *createNode(int data, Node *next = nullptr);
// Заполнение данными из файла
void fill(List *list);
// Добавление ноды в список
void add(List *list, Node *node);
// Проверка, пустой ли список
bool isEmpty(List *list);
// Распечатать список
void printList(List *list);
// Удаление списка
void deleteList(List *list);
// Проверка на симметричность
bool checkList(List *list);