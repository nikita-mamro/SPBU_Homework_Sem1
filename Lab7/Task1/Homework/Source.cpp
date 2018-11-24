#include "Menu.hpp"

int main()
{
	Set *set = createSet();
	add(set, 5);
	add(set, 2);
	add(set, 8);
	add(set, 1);
	add(set, 3);
	add(set, 6);
	add(set, 10);
	add(set, 7);
	add(set, 9);
	remove(set, 8);
	test(set);
	return 0;
}