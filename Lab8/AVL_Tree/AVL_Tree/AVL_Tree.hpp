#pragma once
#include <string>

using namespace std;

struct Node;

Node *createNode();
// Высота и баланс-фактор
unsigned char height(Node *node);
int balanceFactor(Node *node);
// Устанавливаем корректное значение высоты узла после балансировки дочерних узлов
void fixHeight(Node *node);
// Повороты вокруг ноды, возвращают корень полученного дерева
Node * rotateRight(Node * p);
Node * rotateLeft(Node * p);
// Балансировка узла p
Node * balance(Node * p);
// Добавление ключа
Node * add(Node * root, int key, string str);
// Поиск узла с минимальным ключом
Node *findMin(Node *root);
// Удаление
Node *removeMin(Node *root);
Node *remove(Node *root, int key);
