#pragma once
#include <string>
#include <cstring>

using namespace std;

struct Node;

struct List;
//�������� ����.
Node *createNode(const string &word, Node *next = nullptr);
//�������� ������.
List *createList();
List *createList(Node *node);
//���������� ���� � ������.
void add(List *list, Node *node);
// ��������� ���� "���-�� ���������"
void changeCounter(List *list, const string &word, int delta);
// ��������, ���������� �� ������
bool exists(List *list, const string &word);
//��������, ������ �� ������.
bool isEmpty(List *list);
//�������� ������.
void deleteList(List * list);
// ��������� �����
int getLength(List *list);
// ����� ������ � ������ �������� ����
void printList(List *list);
