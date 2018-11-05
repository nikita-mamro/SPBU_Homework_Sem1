#pragma once

struct StackElement
{
	char data = 0;
	StackElement *next = nullptr;
};

struct Stack
{
	StackElement *head = nullptr;
};

void push(Stack&, char);
char pop(Stack&);
char top(Stack&);
bool isEmpty(Stack);
void deleteStack(Stack &stack);