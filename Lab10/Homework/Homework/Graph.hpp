#pragma once
#include "ReadFromFile.hpp"
#include <vector>
#include <fstream>

struct Node;

// Create graphs of each country
std::vector<Node*> getCountries(std::vector<int> &capitals, std::vector<InputElement*> &triplets);

// Check if cityA and cityB are int the same country or not
bool differentCapitals(const std::vector<Node*> &capitalNodes, int cityA, int cityB);

// Deleting
void deleteCountry(Node * capital);

// Vector (countries) of vectors (cities)
std::vector<std::vector<int>> solveTask(std::ifstream &input);