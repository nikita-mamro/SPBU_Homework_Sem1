#pragma once
#include <string>
#include <cstring>

using namespace std;

struct Node;

struct List;
//Создание ноды.
Node *createNode(const string &word, int counter, Node *next = nullptr);
//Создание списка.
List *createList();
List *createList(Node *node);
//Добавление и удаление
void add(List *list, Node *node);
void remove(List *list, Node *node);
// Изменение поля колва вхождений Node на newValue
void setCounter(List *list, const string &word, int newValue);
// Увеличение поля колва вхождений Node на delta
void changeCounter(List *list, const string &word, int delta);
// Проверка, существует ли строка
bool exists(List *list, const string &word);
//Проверка, пустой ли список.
bool isEmpty(List *list);
//Удаление списка.
void deleteList(List * list);
// Получение параметра Node
int getCounter(Node *node);
// Получение параметра List
int getLength(List *list);
// Получение параметра Node
string getWord(Node *node);
// Получение параметра Node
bool isRehashed(Node *node);
// Получение параметра List
Node *getHead(List *list);
// Получение параметра Node
Node *next(Node *node);
// Изменение поля isRehashed
void setIsRehashed(Node *node, bool newValue);
