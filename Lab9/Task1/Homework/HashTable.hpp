#pragma once
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

struct HashTable;

//�������� �������
HashTable *createHashTable();
HashTable *readFromFile(ifstream &input);
// ���������� ������ � �������
void add(const string &word, HashTable *table);
// �������� �� ������������� ������ � �������
bool exists(const string &word, const HashTable *table);
// ���-�������
int hashFunction(const string &word);
// ��������� ����� �� ������� � �������� �� ��������� � �����
void printWordsFrequency(HashTable *table);
// ����������� ����������
double loadCoefficient(const HashTable *table);
// ������������ ����� ������ � ��������
int maxLenghtInSegment(const HashTable *table);
// ������� ����� ������ � ��������
double averageLengthInSegment(const HashTable *table);