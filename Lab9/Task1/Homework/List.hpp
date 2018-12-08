#pragma once
#include <string>
#include <cstring>

using namespace std;

struct Node;

struct List;
//Создание ноды.
Node *createNode(const string &word, Node *next = nullptr);
//Создание списка.
List *createList();
List *createList(Node *node);
//Добавление ноды в список.
void add(List *list, Node *node);
// Изменение поля "кол-во вхождений"
void changeCounter(List *list, const string &word, int delta);
// Проверка, существует ли строка
bool exists(List *list, const string &word);
//Проверка, пустой ли список.
bool isEmpty(List *list);
//Удаление списка.
void deleteList(List * list);
// Получение длины
int getLength(List *list);
// Вывод списка с учётом счётчика слов
void printList(List *list);
