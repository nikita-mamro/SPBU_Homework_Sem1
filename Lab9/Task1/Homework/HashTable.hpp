#pragma once
#include "List.hpp"
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

struct HashTable;
struct Element;

//�������� �������
HashTable *createHashTable();
HashTable *readFromFile(ifstream &input);
// �������� �������
void deleteTable(HashTable *&table);
// ���������� ������ � �������
void add(const string &word, HashTable *table);
// �������� �� ������������� ������ � �������
bool exists(const string &word, const HashTable *table);
// ���-�������
long int hashFunction(const string &word);
// ���������� �������
void expand(HashTable *table);
// ����������� ����������
double loadCoefficient(const HashTable *table);
// ������������ ����� ������ � ��������
int maxLenghtInSegment(const HashTable *table);
// ������� ����� ������ � ��������
double averageLengthInSegment(const HashTable *table);
// ������ �����-�������
void fillArray(HashTable *table, vector<Element*> &res);
// ��������� ����� �� ������� � �������� �� ��������� � �����
void printWordsFrequency(vector<Element*> result);
// �������� ��������
Element *createElement(string word, int counter);
// ��������� ����� ��������
void setElementWord(Element *element, string word);
void setElementCounter(Element *element, int counter);
// ��������� �����
string getElementWord(Element *element);
int getElementCounter(Element *element);