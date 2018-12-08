#include "HashTable.hpp"
#include <iostream>

int main()
{
	ifstream input("input.txt", ios::in);
	
	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}