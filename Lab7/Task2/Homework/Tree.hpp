#pragma once
#include <iostream>
#include <fstream>

struct Tree;

// Creating tree
Tree *createTree(std::ifstream &input);

// Deleting Tree
void deleteTree(Tree *tree);

// Print expression
void printExpression(Tree *tree);

// Proceed expression with 2 ariables and an operand
int proceedOperator(int a, int b, char theOperator);

// Get value of an expression
int getExpressionValue(Tree *tree);
