#include "AVL_Tree.hpp"

using namespace std;

struct Node
{
	string value;
	unsigned char height = 0;
	int key = 0;
	Node *left = nullptr;
	Node *right = nullptr;
	Node(int Key, string Str) { key = Key; left = right = nullptr; height = 1; value = Str; }
};

Node * createNode()
{
	Node *res = nullptr;
	return res;
}

void deleteNode(Node * node)
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

Node * rotateRight(Node * p)
{
	Node *q = p->left;
	p->left = q->right;
	q->right = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}

Node * rotateLeft(Node * p)
{
	Node *q = p->right;
	p->right = q->left;
	p->left = q;
	fixHeight(p);
	fixHeight(q);
	return q;
}

Node * balance(Node * p)
{
	if (p == nullptr)
	{
		return p;
	}

	fixHeight(p);

	if (balanceFactor(p) == 2)
	{
		if (balanceFactor(p->right) < 0)
		{
			p->right = rotateRight(p->right);
		}
		return rotateLeft(p);
	}

	if (balanceFactor(p) == -2)
	{
		if (balanceFactor(p->left) > 0)
		{
			p->left = rotateLeft(p->left);
		}
		return rotateRight(p);
	}

	return p;
}

Node * add(Node * root, int key, string str)
{
	if (exists(root, key))
	{
		Node *current = root;
		while (current->key != key)
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
		current->value = str;
		return root;
	}
	if (!root)
	{
		Node *res = new Node(key, str);
		return res;
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
		return balance(root);
	}
	if (!root)
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
		Node* p = root->left;
		Node* q = root->right;
		delete root;
		if (!q) return p;
		Node* min = findMin(q);
		min->right = removeMin(q);
		min->left = p;
		return balance(min);
	}
	return balance(root);
}

bool exists(Node * root, int key)
{
	if (root != nullptr && root->key == key)
	{
		return true;
	}
	if (root != nullptr && root->key > key)
	{
		return exists(root->left, key);
	}
	if (root != nullptr && root->key < key)
	{
		return exists(root->right, key);
	}
	return false;
}

string getValue(Node * root, int key)
{
	if (!exists(root, key))
	{
		return string();
	}
	if (root != nullptr && root->key == key)
	{
		return root->value;
	}
	if (root != nullptr && root->key > key)
	{
		return getValue(root->left, key);
	}
	if (root != nullptr && root->key < key)
	{
		return getValue(root->right, key);
	}
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
