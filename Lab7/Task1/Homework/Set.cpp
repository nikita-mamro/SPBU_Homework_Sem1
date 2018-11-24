#include "Set.hpp"
#include <iostream>
using namespace std;


Node *createNode(int value, Node *left = nullptr, Node *right = nullptr)
{
	return new Node{ value, left, right };
}

void deleteNode(Node *node)
{
	if (!node->left)
	{
		deleteNode(node->left);
	}
	else if (!node->right)
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
	if (!set->root)
	{
		deleteNode(set->root);
		delete set;
		set = nullptr;
	}
}

void add(Set * set, int element)
{
	if (set->root == nullptr)
	{
		set->root = createNode(element);
	}
	else
	{
		Node *current = set->root;

		while (1)
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

int remove(Set * set, int element)
{
	if (!exists(set, element))
	{
		cout << "Element not found :(" << endl;
		return EXIT_FAILURE;
	}

	if (set->root == nullptr)
	{
		return EXIT_FAILURE;
	}
	
	Node *current = set->root;

	if (current->value != element)
	{
		while (1)
		{
			if (element < current->value)
			{
				if (element < current->left->value)
				{
					current = current->left;
				}
				else
				{
					break;
				}
			}
			if (element > current->value)
			{
				if (element > current->right->value)
				{
					current = current->right;
				}
				else
				{
					break;
				}
			}
		}
	}

	if (current->left->value == element)
	{
		if (current->left->left == nullptr && current->left->right == nullptr)
		{
			Node *tmp = current->left;
			current->left = nullptr;
			delete tmp;
			return element;
		}

		if (current->left->left == nullptr && current->left->right != nullptr)
		{
			Node *tmp = current->left;
			current->left = tmp->right;
			delete tmp;
			return element;
		}

		if (current->left->left != nullptr && current->left->right == nullptr)
		{
			Node *tmp = current->left;
			current->left = tmp->left;
			delete tmp;
			return element;
		}

		if (current->left->left != nullptr && current->left->right != nullptr)
		{
			Node *tmp = current->left;
			Node *bottom = mostLeft(current->left->right);
			bottom->left = tmp->left;
			current->left = tmp->right;
			delete tmp;
			return element;
		}
	}

	if (current->right->value == element)
	{
		if (current->right->left == nullptr && current->right->right == nullptr)
		{
			Node *tmp = current->right;
			current->right = nullptr;
			delete tmp;
			return element;
		}

		if (current->right->left == nullptr && current->right->right != nullptr)
		{
			Node *tmp = current->right;
			current->right = tmp->right;
			delete tmp;
			return element;
		}

		if (current->right->left != nullptr && current->right->right == nullptr)
		{
			Node *tmp = current->right;
			current->right = tmp->left;
			delete tmp;
			return element;
		}

		if (current->right->left != nullptr && current->right->right != nullptr)
		{
			Node *tmp = current->right;
			Node *bottom = mostLeft(current->right);
			bottom->left = tmp->left;
			current->right = tmp->right;
			delete tmp;
			return element;
		}
	}
}

bool exists(Set * set, int element)
{
	return true;
}

Node *mostLeft(Node *node)
{
	Node *res = node;

	while (res->left != nullptr)
	{
		res = res->left;
	}

	return res;
}

Node *mostRight(Node *node)
{
	Node *res = node;

	while (res->right != nullptr)
	{
		res = res->right;
	}

	return res;
}

void printAsc(Set * set)
{

}

void printDesc(Set * set)
{

}

void test(Set *set)
{
	Node *node = set->root;
	
	cout << node->value << node->right->value << node->right->left->value;
}

