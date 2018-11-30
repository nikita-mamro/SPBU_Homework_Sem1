#include "Test.hpp"
#include "List.hpp"

bool test()
{
	List *testListTrue = createList();
	List *testListFalse = createList();

	for (int i = 0; i < 10; ++i)
	{
		add(testListFalse, createNode(i));
	}

	for (int i = 1; i < 10; ++i)
	{
		add(testListTrue, createNode(i));
	}

	for (int i = 9; i > 1; --i)
	{
		add(testListTrue, createNode(i));
	}

	if (!checkList(testListFalse) && checkList(testListTrue))
	{
		deleteList(testListFalse);
		deleteList(testListTrue);
		return false;
	}

	deleteList(testListFalse);
	deleteList(testListTrue);

	return true;
}
