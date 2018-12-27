#include "PriorityQueue.hpp"
#include <iostream>

struct Node
{
	int data = 0;
	int priority = 0;
	Node *next = nullptr;
};

struct PriorityQueue
{
	Node *head = nullptr;
};

PriorityQueue * createQueue()
{
	return new PriorityQueue;
}

bool isEmpty(PriorityQueue * pQueue)
{
	return (pQueue->head == nullptr) ;
}

void enqueue(PriorityQueue * pQueue, const int data, const int priority)
{
	Node * newNode = new Node{ data, priority, nullptr };

	if (isEmpty(pQueue) || priority >= pQueue->head->priority)
	{
		newNode->next = pQueue->head;
		pQueue->head = newNode;
		return;
	}
	Node * pointer = pQueue->head;
	while (pointer->next != nullptr && pointer->next->priority >= priority)
	{
		pointer = pointer->next;
	}
	newNode->next = pointer->next;
	pointer->next = newNode;
}

int dequeue(PriorityQueue * pQueue, bool & result)
{
	if (isEmpty(pQueue))
	{
		result = false;
		return -1;
	}

	const int minData = pQueue->head->data;

	Node * tmp = pQueue->head;
	pQueue->head = pQueue->head->next;
	delete tmp;
	return minData;
}

void deletePQueue(PriorityQueue *& pQueue)
{
	while (!isEmpty(pQueue))
	{
		Node *temp = pQueue->head;
		pQueue->head = pQueue->head->next;
		delete temp;
	}

	delete pQueue;
	pQueue = nullptr;
}

void printPQueue(PriorityQueue * pQueue)
{
	if (isEmpty(pQueue))
	{
		std::cout << "Priority queue is empty!" << std::endl;
		return;
	}

	Node * pointer = pQueue->head;

	std::cout << "Priority queue ELEMENT(PRIORITY):" << std::endl;
	while (pointer != nullptr) 
	{
		std::cout << pointer->data << "(" << pointer->priority << ") ";
		pointer = pointer->next;
	}
	std::cout << std::endl;
}

int getData(Node * node)
{
	return node != nullptr ? node->data : -666;
}

int getPriority(Node * node)
{
	return node != nullptr ? node->priority : -999;
}

Node * getHead(PriorityQueue * pQueue)
{
	return pQueue->head;
}

Node * getNext(Node * node)
{
	return node != nullptr ? node->next : nullptr;
}
