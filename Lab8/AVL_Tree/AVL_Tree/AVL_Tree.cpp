#include "AVL_Tree.hpp"

using namespace std;

struct Node
{
	string value;
	unsigned char height = 0;
	int key = 0;
	Node *left = nullptr;
	Node *right = nullptr;
	Node(int key, string str) { this->key = key; left = right = nullptr; height = 1; value = str; }
};

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

void deleteTree(Node * root)
{
	deleteNode(root);
}

unsigned char height(Node * node)
{
	return node ? node->height : 0;
}

int balanceFactor(Node * node)
{
	return height(node->right) - height(node->left);
}

void fixHeight(Node * node)
{
	unsigned char hLeft = height(node->left);
	unsigned char hRight = height(node->right);
	node->height = (hLeft > hRight ? hLeft : hRight) + 1;
}

// Rotating around node which functions get as a parameter

Node * rotateRight(Node * node)
{
	Node *nodeLeft = node->left;
	node->left = nodeLeft->right;
	nodeLeft->right = node;
	fixHeight(node);
	fixHeight(nodeLeft);
	return nodeLeft;
}

Node * rotateLeft(Node * node)
{
	Node *nodeRight = node->right;
	node->right = nodeRight->left;
	node->left = nodeRight;
	fixHeight(node);
	fixHeight(nodeRight);
	return nodeRight;
}

Node * balance(Node * node)
{
	if (node == nullptr)
	{
		return node;
	}

	fixHeight(node);

	if (balanceFactor(node) == 2)
	{
		if (balanceFactor(node->right) < 0)
		{
			node->right = rotateRight(node->right);
		}
		return rotateLeft(node);
	}

	if (balanceFactor(node) == -2)
	{
		if (balanceFactor(node->left) > 0)
		{
			node->left = rotateLeft(node->left);
		}
		return rotateRight(node);
	}

	return node;
}

Node * getNodeByKey(Node * root, int key)
{
	if (root == nullptr)
	{
		return root;
	}
	Node *current = root;
	while (current != nullptr && current->key != key)
	{
		if (current->key < key)
		{
			current = current->right;
		}
		else
		{
			current = current->left;
		}
	}
	return current;
}

Node * add(Node * root, int key, const string & str)
{
	Node *current = getNodeByKey(root, key);

	if (current != nullptr)
	{
		current->value = str;
		return root;
	}
	if (root == nullptr)
	{
		return new Node(key, str);
	}
	if (key < root->key)
	{
		root->left = add(root->left, key, str);
	}
	else
	{
		root->right = add(root->right, key, str);
	}
	return balance(root);
}

Node * findMin(Node * root)
{
	return root->left ? findMin(root->left) : root;
}

Node * removeMin(Node * root)
{
	if (root->left == nullptr)
	{
		return root->right;
	}
	root->left = removeMin(root->left);
	return balance(root);
}

Node * remove(Node * root, int key)
{
	if (!exists(root, key))
	{
		return root;
	}
	if (root == nullptr)
	{
		return nullptr;
	}
	if (key < root->key)
	{
		root->left = remove(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = remove(root->right, key);
	}
	else 
	{
		Node* left = root->left;
		Node* right = root->right;
		delete root;
		if (right == nullptr)
		{
			return left;
		}

		Node* min = findMin(right);
		min->right = removeMin(right);
		min->left = left;
		return balance(min);
	}
	return balance(root);
}

bool exists(Node * root, int key)
{
	Node * node = getNodeByKey(root, key);
	return node != nullptr;
}

string getValue(Node * root, int key)
{
	Node * res = getNodeByKey(root, key);
	return res != nullptr ? res->value : string();
}

int getKey(Node * node)
{
	return node ? node->key : -666; // В тестах не будем давать ключ -666
}

Node * getLeft(Node * node)
{
	return node->left;
}

Node * getRight(Node * node)
{
	return node->right;
}

string getValue(Node * node)
{
	return node ? node->value : "ERR";
}
