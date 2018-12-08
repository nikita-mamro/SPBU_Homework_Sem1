#pragma once
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

struct HashTable;

//Создание таблицы
HashTable *createHashTable();
HashTable *readFromFile(ifstream &input);
// Добавление строки в таблицу
void add(const string &word, HashTable *table);
// Проверка на существование строки в таблице
bool exists(const string &word, const HashTable *table);
// Хеш-функция
int hashFunction(const string &word);
// Рачпечать слова из таблицы с частотой их вхождения в текст
void printWordsFrequency(HashTable *table);
// Коэффициент заполнения
double loadCoefficient(const HashTable *table);
// Максимальная длина списка в сегменте
int maxLenghtInSegment(const HashTable *table);
// Средняя длина списка в сегменте
double averageLengthInSegment(const HashTable *table);