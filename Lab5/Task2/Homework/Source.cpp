#include "stdafx.hpp"
#include "CycleList.hpp"
#include "Test.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");

	test(10, 4, 5);
	test(6, 3, 1);

	CycleList list;
	int n = 0;
	int m = 0;

	printf("¬ведите n: ");
	scanf("%d", &n);
	printf("¬ведите m: ");
	scanf("%d", &m);

	for (int i = 1; i <= n; ++i)
	{
		addElement(i, list);
	}

	kill(m, list);

	printCycleList(list);

	deleteList(list);

	return 0;
}