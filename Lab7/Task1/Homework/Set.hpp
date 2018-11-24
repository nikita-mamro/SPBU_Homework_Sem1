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

//�������� ���������
Set *createSet();
//�������� ���������
void deleteSet(Set * set);
//���������� ��������
void add(Set *set, int element);
//��������
int remove(Set *set, int element);
//���������� �� �������
bool exists(Set *set, int element);
//������� ����
Node *mostLeft(Node *node);
Node *mostRight(Node *node);
//����� �� �����������/��������
void printAsc(Set *set);
void printDesc(Set *set);

//��������� ��� ����

void test(Set *set);
