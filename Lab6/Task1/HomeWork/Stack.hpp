#pragma once

struct StackElement
{
	int data = 0;
	StackElement *next = nullptr;
};

struct Stack
{
	StackElement *head = nullptr;
};

Stack *createStack();
void push(Stack&, int);
int pop(Stack&);
bool isEmpty(Stack);
void deleteStack(Stack &stack);