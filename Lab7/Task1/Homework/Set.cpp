#include "Set.hpp"
#include <iostream>

using namespace std;

struct Node
{
	int value = 0;
	Node *left;
	Node *right;
};

struct Set
{
	Node *root;
};

Node *createNode(int value, Node *left = nullptr, Node *right = nullptr)
{
	return new Node{ value, left, right };
}

void deleteNode(Node * node)
{
	if (node->left != nullptr)
	{
		deleteNode(node->left);
	}
	else if (node->right != nullptr)
	{
		deleteNode(node->right);
	}
	delete node;
}

Set *createSet()
{
	return new Set{ nullptr };
}

void deleteSet(Set * set)
{
	if (set->root != nullptr)
	{
		deleteNode(set->root);
	}
	delete set;
}

void add(Set * set, int element)
{
	if (exists(set, element))
	{
		return;
	}
	if (set->root == nullptr)
	{
		set->root = createNode(element);
	}
	else
	{
		Node *current = set->root;

		while (true)
		{
			if (current->value > element)
			{
				if (current->left == nullptr)
				{
					current->left = createNode(element);
					break;
				}
				else
				{
					current = current->left;
					continue;
				}
			}
			if (current->value < element)
			{
				if (current->right == nullptr)
				{
					current->right = createNode(element);
					break;
				}
				else
				{
					current = current->right;
					continue;
				}
			}
		}
	}
}

bool remove(Set * set, int element)
{
	if (!exists(set, element))
	{
		return false;
	}
	
	remove(set->root, element);

	return true;
}

void remove(Node *& node, int element)
{
	if (element < node->value)
	{
		remove(node->left, element);
	}
	else if (element > node->value)
	{
		remove(node->right, element);
	}
	else
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			Node *tmp = node;
			node = nullptr;
			delete tmp;
		}
		else if (node->left != nullptr && node->right == nullptr)
		{
			Node *tmp = node;
			node = node->left;
			delete tmp;
		}
		else if (node->left == nullptr && node->right != nullptr)
		{
			Node *tmp = node;
			node = node->right;
			delete tmp;
		}
		else if (node->left != nullptr && node->right != nullptr)
		{
			node->value = mostRight(node->left)->value;
			remove(node->left, node->value);
		}
	}
}

bool exists(Set * set, int element)
{
	if (set->root == nullptr)
	{
		return false;
	}

	Node *current = set->root;

	while (true)
	{
		if (element == current->value)
		{
			return true;
		}
		else if (element < current->value)
		{
			if (current->left != nullptr)
			{
				current = current->left;
				continue;
			}
			return false;
		}
		else
		{
			if (current->right != nullptr)
			{
				current = current->right;
				continue;
			}
			return false;
		}
	}
	return true;
}

Node *mostLeft(Node *node)
{
	Node *res = node->left;

	while (res->left != nullptr)
	{
		res = res->left;
	}

	return res;
}

Node *mostRight(Node *node)
{
	Node *res = node->right;

	while (res->right != nullptr)
	{
		res = res->right;
	}

	return res;
}

void fillArrayAscDesc(std::vector<int>& orderedElements, Node * node, bool isAscending)
{
	if (node == nullptr)
	{
		return;
	}
	
	if (isAscending)
	{
		fillArrayAscDesc(orderedElements, node->left, isAscending);
	}
	else
	{
		fillArrayAscDesc(orderedElements, node->right, isAscending);
	}

	orderedElements.push_back(node->value);

	if (isAscending)
	{
		fillArrayAscDesc(orderedElements, node->right, isAscending);
	}
	else
	{
		fillArrayAscDesc(orderedElements, node->left, isAscending);
	}
}

void printAscDesc(Set * set, bool asc)
{
	cout << "------------------------------" << endl;
	if (set->root == nullptr)
	{
		cout << "EMPTY" << endl;
	}
	else
	{
		vector<int> ascElements;

		fillArrayAscDesc(ascElements, set->root, asc);

		for (int i = 0; i < ascElements.size(); ++i)
		{
			cout << ascElements[i] << " ";
		}

		cout << endl;
	}
	cout << "------------------------------" << endl;
}

Node * root(Set * set)
{
	return set->root;
}