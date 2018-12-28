#pragma once
#include <vector>
#include <fstream>

struct InputElement;

InputElement *createInputElement(int cityFrom, int cityTo, int roadLength);
void deleteInputElement(InputElement *element);
int getRoadLength(InputElement *element);
int getCityFrom(InputElement *element);
int getCityTo(InputElement *element);

// Read data from file into TRIPLETS array
void readFromFile(std::vector<int> &capitals, std::vector<InputElement*> &triplets, std::ifstream & input);
