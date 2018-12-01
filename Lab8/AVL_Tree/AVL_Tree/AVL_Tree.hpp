#pragma once
#include <string>

using namespace std;

struct Node;

// Создание и удаление
Node *createNode();
void deleteNode(Node *node);
void deleteTree(Node *root);
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
Node * findMin(Node *root);
// Удаление
Node * removeMin(Node *root);
Node * remove(Node *root, int key);
// Проверить ключ на существование
bool exists(Node *root, int key);
// Получить значение по ключу
string getValue(Node *root, int key);
// Функции для того, чтобы вынести тесты в отдельный модуль
int getKey(Node *node);
Node *getLeft(Node *node);
Node *getRight(Node *node);
string getValue(Node *node);
