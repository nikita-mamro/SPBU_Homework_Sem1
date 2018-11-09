#pragma once

#include "stdafx.hpp"
#include "Stack.hpp"

bool isDigit(char);
bool isOperand(char);
int charToDigit(char);
bool isOpeningBracket(char);
bool isClosingBracket(char);
int operandPriority(char);
int proceedOperand(int, int, char);
string infixToPostfix(const string&);