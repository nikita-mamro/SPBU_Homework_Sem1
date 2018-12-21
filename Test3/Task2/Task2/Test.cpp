#include "Test.hpp"
#include "PriorityQueue.hpp"

using namespace std;

bool test(vector<string> &errors)
{
	bool res = true;

	PriorityQueue * pQueue = createQueue();

	enqueue(pQueue, 124, 1);
	enqueue(pQueue, 58, 12);
	enqueue(pQueue, 12, 2);
	enqueue(pQueue, 131, 1);
	enqueue(pQueue, 34, 3);
	enqueue(pQueue, 53, 13);
	enqueue(pQueue, 12, 100);

	Node * tmp = getHead(pQueue);
	while (getNext(tmp) != nullptr)
	{
		if (getPriority(tmp) < getPriority(getNext(tmp)))
		{
			res = false;
			errors.push_back("Priority error!");
			break;
		}
		tmp = getNext(tmp);
	}

	bool deqRes = true;
	dequeue(pQueue, deqRes);

	if (deqRes == false || getData(getHead(pQueue)) != 53)
	{
		res = false;
		errors.push_back("Dequeue error!");
	}

	deletePQueue(pQueue);

	return res;
}
