#include "stdafx.hpp"
#include "CycleList.hpp"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	CycleList list;
	int n = 0;
	int m = 0;

	printf("������� n: ");
	scanf("%d", &n);
	printf("������� m: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		addElement(i, list);
	}

	kill(m, list);

	printCycleList(list);

	system("pause");
	return 0;
}