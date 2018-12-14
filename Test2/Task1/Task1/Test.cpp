#include "Test.hpp"
#include "List.hpp"

bool test()
{
	List *testList = createList();

	add(testList, createNode(2));
	add(testList, createNode(5));
	add(testList, createNode(35));
	add(testList, createNode(26));
	add(testList, createNode(6));
	add(testList, createNode(53));
	add(testList, createNode(16));
	add(testList, createNode(7));
	add(testList, createNode(65));

	List *answer = reverseList(testList);

	if (!checkReverse(testList, answer))
	{
		deleteList(testList);
		deleteList(answer);
		return false;
	}

	deleteList(testList);
	deleteList(answer);
	return true;
}
