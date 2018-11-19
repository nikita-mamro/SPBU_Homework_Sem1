#pragma once
#include <string>
#include <cstring>
#include "ContactStruct.hpp"

struct Node;

struct List;
//�������� ����.
Node *createNode(Contact contact, Node *next = nullptr);
//�������� ������.
List *createList();
//���������� ���� � ������.
void add(List *list, Node *node);
//���������� ��������.
void appendList(List *listA, List *listB);
//�������� ������� �������� �� ������.
void extractHead(List *list);
//������� ����, � ������� ���������� ���, ������ 2�� � ���������� �������.
Node *cmpNames(Node *nodeA, Node *nodeB);
//������� ����, � ������� ���������� �����, ������ 2�� � ������� ���������.
Node *cmpPhoneNumbers(Node *nodeA, Node *nodeB);
//������ ������.
void printList(List * list);
//��������, ������ �� ������.
bool isEmpty(List *list);
//�������� ������.
void deleteList(List * list);
//�������� �����.
int getLength(List *list);
//�������� 2 ��������.
List *firstHalf(List *list);
List *secondHalf(List *list);