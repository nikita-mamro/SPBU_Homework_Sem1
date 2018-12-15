#pragma once
#include <vector>

using namespace std;

struct InputElement;

int getRoadLength(InputElement *element);
int getCityFrom(InputElement *element);
int getCityTo(InputElement *element);
void readFromFile(vector<int> &capitals, vector<InputElement*> &triplets, ifstream & input);
