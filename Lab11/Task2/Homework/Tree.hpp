#pragma once
#include <vector>

struct Node;
struct Tree;

Node * createNode(int key);
Tree * createTree(int rootKey);

void add(Node * parent, Node * child, Tree * tree);

Node *getByKey(int key, Node * root);

// Create a tree of an array from Prim's algorithm
void fillTree(std::vector<int> &parents, Tree * tree);

void printTree(Tree * tree);

void deleteTree(Tree * tree);