#include "Test.hpp"
#include "SortedList.hpp"
#include <iostream>

bool test()
{
	bool res = true;

	SortedList testList;
	for (int i = 100; i >= 0; --i)
	{
		addElement(i, testList);
	}

	if (!isSorted(testList))
	{
		std::cout << "List is not sorted!" << std::endl;
		res = false;
	}

	addElement(100, testList);

	if (getCount(100, testList) != 2)
	{
		std::cout << "Error in counting elements!" << std::endl;
		res = false;
	}

	deleteSortedList(testList);
	
	return res;
}