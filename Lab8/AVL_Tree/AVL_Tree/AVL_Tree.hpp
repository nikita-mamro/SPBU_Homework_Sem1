#pragma once
#include <string>

struct Node;

// Создание и удаление
void deleteTree(Node *root);

// Добавление ключа
Node * add(Node * root, int key, const std::string & str);

// Удаление
Node * remove(Node *root, int key);

// Проверить ключ на существование
bool exists(Node *root, int key);

// Получить значение по ключу
std::string getValue(Node *root, int key);

// Геттеры для тестов
int getKey(Node *node);
Node *getLeft(Node *node);
Node *getRight(Node *node);
std::string getValue(Node *node);
