#pragma once
#include "List.hpp"
#include <string>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

struct HashTable;
struct Element;

//Создание таблицы
HashTable *createHashTable();
HashTable *readFromFile(ifstream &input);
// Удаление таблицы
void deleteTable(HashTable *&table);
// Добавление строки в таблицу
void add(const string &word, HashTable *table);
// Проверка на существование строки в таблице
bool exists(const string &word, const HashTable *table);
// Хеш-функция
long int hashFunction(const string &word);
// Расширение таблицы
void expand(HashTable *table);
// Коэффициент заполнения
double loadCoefficient(const HashTable *table);
// Максимальная длина списка в сегменте
int maxLenghtInSegment(const HashTable *table);
// Средняя длина списка в сегменте
double averageLengthInSegment(const HashTable *table);
// Массив СЛОВО-ЧАСТОТА
void fillArray(HashTable *table, vector<Element*> &res);
// Рачпечать слова из таблицы с частотой их вхождения в текст
void printWordsFrequency(vector<Element*> result);
// Создание элемента
Element *createElement(string word, int counter);
// Изменение полей элемента
void setElementWord(Element *element, string word);
void setElementCounter(Element *element, int counter);
// Получение полей
string getElementWord(Element *element);
int getElementCounter(Element *element);