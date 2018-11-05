#include "Stack.hpp"

Stack *createStack()
{
	return new Stack;
}

void push(Stack &stack, int data)
{
	StackElement* newElement = new StackElement;
	newElement->data = data;
	newElement->next = stack.head;
	stack.head = newElement;
}

int pop(Stack &stack)
{
	if (stack.head == nullptr)
	{
		return -1;
	}
	StackElement *temp = stack.head;
	stack.head = stack.head->next;
	const int value = temp->data;
	delete temp;
	return value;
}

bool isEmpty(Stack stack)
{
	return stack.head == nullptr;
}

void deleteStack(Stack &stack)
{
	while (stack.head != nullptr)
	{
		StackElement *temp = stack.head;
		stack.head = temp->next;
		delete temp;
	}
}