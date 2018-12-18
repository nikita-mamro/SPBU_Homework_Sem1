#pragma once
#include "ReadFromFile.hpp"
#include <vector>

using namespace std;

struct Node;
// Create graphs of each country
vector<Node*> getCapitalNodes(vector<int> &capitals, vector<InputElement*> &triplets);
// Adding neighbours
void addNewNeighbour(Node *node, int neighbour);
void addExistingNeighbour(Node *node, Node *neighbour);
// Check if cityA and cityB are int the same country or not
bool differentCapitals(vector<Node*> &capitalNodes, int cityA, int cityB);
// Deleting
void deleteCountry(Node * capital);
// Vector (countries) of vectors (cities)
vector<vector<int>> solveTask(ifstream &input);