#pragma once
#include <vector>

struct Node;

struct Set;

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
void fillArrayAscDesc(std::vector<int>& orderedElements, Node * node, bool isAscending);

//����� �� �����������/��������
void printAscDesc(Set *set, bool asc);

//������� ������ (��� ������)
Node *root(Set *set);
