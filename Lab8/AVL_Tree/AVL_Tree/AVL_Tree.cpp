#include "AVL_Tree.hpp"

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
	p->right = q;
	fixHeight(p);
	fixHeight(q);
	return q;
}

Node * rotateLeft(Node * p)
{
	Node *q = p->right;
	p->right = q->left;
	q->left = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}

Node * balance(Node * p)
{
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
		delete p;
		if (!q) return p;
		Node* min = findMin(root);
		min->right = removeMin(q);
		min->left = p;
		return balance(min);
	}
	return balance(root);
}

