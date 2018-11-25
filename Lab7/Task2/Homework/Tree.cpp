#include "Tree.hpp"
#include <iostream>

struct Node
{
	int data;
	Node *left;
	Node *right;
};

struct Tree
{
	Node *root;
};

Tree * createTree(const char * file)
{
	FILE *file = fopen(file, "r");
	return new Tree{};
}

void deleteTree(Tree * tree)
{
}
