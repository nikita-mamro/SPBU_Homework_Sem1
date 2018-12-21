#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Graph.hpp"

using namespace std;

int main()
{
	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	vector<int> verticles;

	findVerticles(verticles, input);

	input.close();

	if (verticles.empty())
	{
		cout << "No verticles found!" << endl;
		return EXIT_SUCCESS;
	}

	cout << "Verticles we were looking for:" << endl;

	for (int verticle : verticles)
	{
		cout << verticle << " ";
	}

	cout << endl;

	return EXIT_SUCCESS;
}