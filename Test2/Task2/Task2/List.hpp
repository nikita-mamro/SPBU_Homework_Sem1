#pragma once

struct Node;

struct List;
// �������� ��������
List *createList();
Node *createNode(int data, Node *next = nullptr);
// ���������� ������� �� �����
void fill(List *list);
// ���������� ���� � ������
void add(List *list, Node *node);
// ��������, ������ �� ������
bool isEmpty(List *list);
// ����������� ������
void printList(List *list);
// �������� ������
void deleteList(List *list);
// �������� �� ��������������
bool checkList(List *list);