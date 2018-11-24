#pragma once

struct Node
{
	int value = 0;
	Node *left;
	Node *right;
};

struct Set
{
	Node *root;
};

//Создание множества
Set *createSet();
//Удаление множества
void deleteSet(Set * set);
//Добавление элемента
void add(Set *set, int element);
//Удаление
int remove(Set *set, int element);
//Содержится ли элемент
bool exists(Set *set, int element);
//Крайние ноды
Node *mostLeft(Node *node);
Node *mostRight(Node *node);
//Вывод по возрастанию/убыванию
void printAsc(Set *set);
void printDesc(Set *set);

//Минитесты для себя

void test(Set *set);
