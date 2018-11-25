#pragma once
#include <vector>

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

//�������� ���������
Set *createSet();
//�������� ���������
void deleteSet(Set * set);
//���������� ��������
void add(Set *set, int element);
//��������
bool remove(Set *set, int element);
void remove(Node *&node, int element);
//���������� �� �������
bool exists(Set *set, int element);
//������� ����
Node *mostLeft(Node *node);
Node *mostRight(Node *node);
//�������� ��������� � ������
void fillArrayAscDesc(std::vector<int> &res, Node *node, bool asc);
//����� �� �����������/��������
void printAscDesc(Set *set, bool asc);
//������� ������ (��� ������)
Node *root(Set *set);
