#pragma once
#include <string>

struct Node;

// �������� � ��������
void deleteTree(Node *root);

// ���������� �����
Node * add(Node * root, int key, const std::string & str);

// ��������
Node * remove(Node *root, int key);

// ��������� ���� �� �������������
bool exists(Node *root, int key);

// �������� �������� �� �����
std::string getValue(Node *root, int key);

// ������� ��� ������
int getKey(Node *node);
Node *getLeft(Node *node);
Node *getRight(Node *node);
std::string getValue(Node *node);
