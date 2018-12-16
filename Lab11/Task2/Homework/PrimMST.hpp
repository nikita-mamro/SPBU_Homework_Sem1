#pragma once
#include <vector>
#include <fstream>
constexpr auto INF = 0x3F3F3F3F;

using namespace std;
// Reads graph implementation (adjacency matrix)
void readFromFile(vector<vector<int>> & graph, ifstream &input);
// Find vertex with minimum key which is NOT in tree
int minKey(vector<int> &key, vector<bool> &set);
// Parent p with inex i -> in spanning tree i is child of p
// 0'th key is always root of spannin' tree
void primMST(vector<int> &parents, vector<vector<int>> & graph);
