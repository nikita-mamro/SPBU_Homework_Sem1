#include "Tree.hpp"
#include <cctype>

using namespace std;

struct Node
{
	int data = 0;
	bool isDigit = false;
	Node *left = nullptr;
	Node *right = nullptr;
};

struct Tree
{
	Node *root = nullptr;
};

Node * createNode(ifstream & input)
{
	Node *node = new Node(); 
	char current = input.peek();

	if (current == '(')
	{
		input.get(); // extract (
		node->data = input.get(); // get operand
		input.get(); // extract space
		node->left = createNode(input); // braching
		input.get(); // extract space
		node->right = createNode(input);
		input.get(); // extract space
	}
	else if ((current == '-') || (isdigit(current)))
	{
		input >> node->data; // get number (taking negative numbers into account)
		node->isDigit = true;
	}

	return node;
}

Tree * createTree(ifstream & input)
{
	return new Tree{ createNode(input) };
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

void deleteTree(Tree * tree)
{
	if (tree->root != nullptr)
	{
		deleteNode(tree->root);
	}
	delete tree;
	tree = nullptr;
}

void printExpression(Node * node)
{
	if (node->isDigit)
	{
		cout << node->data;
		return;
	}

	cout << "(";
	printExpression(node->left);
	cout << " " << (char)node->data << " ";
	printExpression(node->right);
	cout << ")";
}

void printExpression(Tree * tree)
{
	printExpression(tree->root);
}

int proceedOperator(int a, int b, char theOperator)
{
	switch (theOperator)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		return -1;
	}
}

int getExpressionValue(Node * node)
{
	if (node->isDigit)
	{
		return node->data;
	}
	return proceedOperator(getExpressionValue(node->left), getExpressionValue(node->right), node->data);
}

int getExpressionValue(Tree * tree)
{
	return getExpressionValue(tree->root);
}
