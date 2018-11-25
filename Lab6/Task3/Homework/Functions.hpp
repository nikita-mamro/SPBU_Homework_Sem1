#pragma once

#include "Stack.hpp"
#include "stdafx.hpp"

bool isDigit(char c);
bool isOperand(char c);
int charToDigit(char c);
bool isOpeningBracket(char c);
bool isClosingBracket(char c);
int operandPriority(char operand);
int proceedOperand(int a, int b, char operand);
string infixToPostfix(const string &input);