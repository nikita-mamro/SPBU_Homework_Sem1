#pragma once

#include "Stack.hpp"
#include "stdafx.hpp"

bool isDigit(char);
bool isOperand(char);
int charToDigit(char);
int proceedOperand(int, int, char);
int proceedTask(const string &);