#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Tree;
struct Node;
// Creating Node + Tree
Node *createNode(ifstream &input);
Tree *createTree(ifstream &input);
// Deleting Node + Tree
void deleteNode(Node *node);
void deleteTree(Tree *tree);
// Print expression
void printExpression(Node *node);
void printExpression(Tree *tree);
// Proceed expression with 2 ariables and an operand
int proceedOpernad(int a, int b, char operand);
// Get value of an expression
int getExpressionValue(Node *node);
int getExpressionValue(Tree *tree);
