#pragma once
#include <vector>

struct Node;

struct Set;

//Создание множества
Set *createSet();

//Удаление множества
void deleteSet(Set * set);

//Добавление элемента
void add(Set *set, int element);

//Удаление
bool remove(Set *set, int element);
void remove(Node *&node, int element);

//Содержится ли элемент
bool exists(Set *set, int element);

//Крайние ноды
Node *mostLeft(Node *node);
Node *mostRight(Node *node);

//Элементы множества в массив
void fillArrayAscDesc(std::vector<int>& orderedElements, Node * node, bool isAscending);

//Вывод по возрастанию/убыванию
void printAscDesc(Set *set, bool asc);

//Вернуть корень (для тестов)
Node *root(Set *set);
