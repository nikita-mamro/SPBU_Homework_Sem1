#pragma once
#include <string>

using namespace std;

struct Node;

// �������� � ��������
Node *createNode();
void deleteNode(Node *node);
void deleteTree(Node *root);
// ������ � ������-������
unsigned char height(Node *node);
int balanceFactor(Node *node);
// ������������� ���������� �������� ������ ���� ����� ������������ �������� �����
void fixHeight(Node *node);
// �������� ������ ����, ���������� ������ ����������� ������
Node * rotateRight(Node * p);
Node * rotateLeft(Node * p);
// ������������ ���� p
Node * balance(Node * p);
// ���������� �����
Node * add(Node * root, int key, string str);
// ����� ���� � ����������� ������
Node * findMin(Node *root);
// ��������
Node * removeMin(Node *root);
Node * remove(Node *root, int key);
// ��������� ���� �� �������������
bool exists(Node *root, int key);
// �������� �������� �� �����
string getValue(Node *root, int key);
// ������� ��� ����, ����� ������� ����� � ��������� ������
int getKey(Node *node);
Node *getLeft(Node *node);
Node *getRight(Node *node);
string getValue(Node *node);
