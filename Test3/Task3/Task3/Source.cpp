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

	vector<int> vertexes;

	findVertexes(vertexes, input);

	input.close();

	if (vertexes.empty())
	{
		cout << "No vertexes found!" << endl;
		return EXIT_SUCCESS;
	}

	cout << "Vertexes we were looking for:" << endl;

	for (int vertex : vertexes)
	{
		cout << vertex << " ";
	}

	cout << endl;

	return EXIT_SUCCESS;
}