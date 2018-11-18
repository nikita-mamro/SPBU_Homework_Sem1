#pragma once

struct StackElement;

struct Stack;

Stack* createStack();
void push(Stack *stack, char data);
char pop(Stack *stack);
char top(Stack *stack);
bool isEmpty(Stack stack);
void deleteStack(Stack *stack);