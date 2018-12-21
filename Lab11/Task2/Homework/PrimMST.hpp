#pragma once
#include <vector>
#include <fstream>
constexpr auto INF = 0x3F3F3F3F;

// Reads graph implementation (adjacency matrix)
void readFromFile(std::vector<std::vector<int>> & graph, std::ifstream &input);

// Find vertex with minimum key which is NOT in tree
int minKey(std::vector<int> &key, std::vector<bool> &set);

// Parent p with inex i -> in spanning tree i is child of p
// 0'th key is always root of spannin' tree
void primMST(std::vector<int> &parents, std::vector<std::vector<int>> & graph);
