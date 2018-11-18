#pragma once

#include "Stack.hpp"
#include "stdafx.hpp"

bool isDigit(char c);
bool isOperand(char c);
int charToDigit(char c);
int proceedOperand(int a, int b, char operand);
int proceedTask(const string &);