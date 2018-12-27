#pragma once
#include <vector>

struct Tree;

Tree * createTree(int rootKey);

// Create a tree of an array from Prim's algorithm
void fillTree(std::vector<int> &parents, Tree * tree);

void printTree(Tree * tree);

void deleteTree(Tree * tree);