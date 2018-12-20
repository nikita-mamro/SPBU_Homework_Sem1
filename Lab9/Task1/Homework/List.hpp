#pragma once
#include <string>
#include <cstring>

using namespace std;

struct Node;

struct List;
//�������� ����.
Node *createNode(const string &word, int counter, Node *next = nullptr);
//�������� ������.
List *createList();
List *createList(Node *node);
//���������� � ��������
void add(List *list, Node *node);
void remove(List *list, Node *node);
// ��������� ���� ����� ��������� Node �� newValue
void setCounter(List *list, const string &word, int newValue);
// ���������� ���� ����� ��������� Node �� delta
void changeCounter(List *list, const string &word, int delta);
// ��������, ���������� �� ������
bool exists(List *list, const string &word);
//��������, ������ �� ������.
bool isEmpty(List *list);
//�������� ������.
void deleteList(List * list);
// ��������� ��������� Node
int getCounter(Node *node);
// ��������� ��������� List
int getLength(List *list);
// ��������� ��������� Node
string getWord(Node *node);
// ��������� ��������� Node
bool isRehashed(Node *node);
// ��������� ��������� List
Node *getHead(List *list);
// ��������� ��������� Node
Node *next(Node *node);
// ��������� ���� isRehashed
void setIsRehashed(Node *node, bool newValue);
