#pragma once

struct Node;
struct PriorityQueue;

// Create queue
PriorityQueue *createQueue();

// Check if queue is empty
bool isEmpty(PriorityQueue * pQueue);

// Adding element
void enqueue(PriorityQueue * pQueue, const int data, const int priority);

// Deleting element 
int dequeue(PriorityQueue *pQueue, bool &result);

// Deleting the whole queue
void deletePQueue(PriorityQueue *&pQueue);

// Printing queue
void printPQueue(PriorityQueue * pQueue);

// Getters
int getData(Node * node);
int getPriority(Node * node);
Node *getHead(PriorityQueue * pQueue);
Node *getNext(Node * node);
