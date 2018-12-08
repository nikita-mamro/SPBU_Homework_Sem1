#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

struct HashTable;

void add(const string &word, HashTable &table);
bool exists(const string &word, const HashTable &table);
int hashFunction(const string &word);
void printWordsFrequency(HashTable &table);