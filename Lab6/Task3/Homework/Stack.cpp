#include "Stack.hpp"

struct StackElement
{
	char data = 0;
	StackElement *next = nullptr;
};

struct Stack
{
	StackElement *head = nullptr;
};

Stack* createStack()
{
	return new Stack;
}

void push(Stack *stack, char data)
{
	StackElement* newElement = new StackElement;
	newElement->data = data;
	newElement->next = stack->head;
	stack->head = newElement;
}

char pop(Stack *stack)
{
	if (stack->head == nullptr)
	{
		return -1;
	}
	StackElement *temp = stack->head;
	stack->head = stack->head->next;
	const char value = temp->data;
	delete temp;
	return value;
}

char top(Stack *stack)
{
	if (stack->head == nullptr)
	{
		return '\0';
	}
	return stack->head->data;
}

bool isEmpty(Stack *stack)
{
	return stack->head == nullptr;
}

void deleteStack(Stack *stack)
{
	while (stack->head != nullptr)
	{
		StackElement *temp = stack->head;
		stack->head = temp->next;
		delete temp;
	}
}