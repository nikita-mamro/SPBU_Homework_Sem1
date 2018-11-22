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
List *createList(Node *node);
//���������� ���� � ������.
void add(List *list, Node *node);
//���������� ��������.
void appendList(List *listA, List *listB);
//�������� ������� �������� �� ������.
Node *extractHead(List *list);
//������� ����, � ������� ���������� ���, ������ 1�� � ���������� �������.
Node *cmpNames(Node *nodeA, Node *nodeB);
//������� ����, � ������� ���������� �����, ������ 1�� � ������� ���������.
Node *cmpPhoneNumbers(Node *nodeA, Node *nodeB);
//������ ������.
void printList(List * list);
//��������, ������ �� ������.
bool isEmpty(List *list);
//�������� ������.
void deleteList(List * list);
//�������� ������ �� ����, ������� ����� ���������� ����� ������������
Contact *priotityNameContact(Node *nodeA, Node *nodeB);
Contact *priotityPhoneContact(Node *nodeA, Node *nodeB);
//����������
List *merge(List *listA, List *listB, bool sortBy);
void mergeSort(List *list, bool sortBy);