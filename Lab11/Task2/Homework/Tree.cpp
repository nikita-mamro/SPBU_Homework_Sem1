#include "Tree.hpp"
#include <vector>
#include <iostream>

using namespace std;

struct Node
{
	int key;
	vector<Node*> children;
};

struct Tree
{
	Node *root;
	int size = 0;
};

Node * createNode(int key)
{
	return new Node{ key, vector<Node*>() };
}

Tree * createTree(int rootKey)
{
	return new Tree{ createNode(rootKey) };
}

void add(Node * parent, Node * child, Tree * tree)
{
	parent->children.push_back(child);
}

Node * getByKey(int key, Node * root)
{
	if (root->key == key)
	{
		return root;
	}
	
	for (Node * child : root->children)
	{
		return getByKey(key, child);
	}

	return nullptr;
}

void fillTree(vector<int> &parents, Node * node, Tree * tree)
{
	if (tree->size == parents.size())
	{
		return;
	}

	for (int i = 0; i < parents.size(); ++i)
	{
		if (node->key == parents[i])
		{
			add(node, createNode(i), tree);
		}
	}
	for (Node * child : node->children)
	{
		fillTree(parents, child, tree);
	}
}

void fillTree(vector<int> &parents, Tree * tree)
{
	fillTree(parents, tree->root, tree);
}

void printNode(Node * node)
{
	if (node->children.empty())
	{
		cout << node->key << " |" << endl;
		return;
	}

	cout << node->key << " : ";

	for (Node *child : node->children)
	{
		cout << child->key << "   ";
	}

	cout << endl;

	for (Node *child : node->children)
	{
		printNode(child);
	}

}

void printTree(Tree * tree)
{
	printNode(tree->root);
}

void deleteNode(Node * node)
{
	for (Node * child : node->children)
	{
		if (!child)
		{
			deleteNode(child);
		}
	}
	delete node;
}

void deleteTree(Tree * tree)
{
	deleteNode(tree->root);
	delete tree;
}

