#pragma once
#include <string>

using namespace std;

struct Node;

Node *createNode();
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
Node *findMin(Node *root);
// ��������
Node *removeMin(Node *root);
Node *remove(Node *root, int key);
