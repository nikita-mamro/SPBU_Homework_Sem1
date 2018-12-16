#include <iostream>
#include <string>
#include <fstream>
#include "PrimMST.hpp"
#include "Test.hpp"
#include "Tree.hpp"

using namespace std;

int main()
{
	cout << "Running tests..." << endl;

	vector<string> testResult;

	if (!test(testResult))
	{
		cout << "Tests failed!" << endl;
		for (unsigned int i = 0; i < testResult.size(); ++i)
		{
			cout << testResult[i] << endl;
		}
		return EXIT_FAILURE;
	}

	cout << "Tests passed!" << endl;
	for (unsigned int i = 0; i < 3; ++i)
	{
		cout << "\\(^_^)/";
	}
	cout << endl;

	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	vector<vector<int>> graph;

	readFromFile(graph, input);

	vector<int> parents(graph.size());

	primMST(parents, graph);
	// 0 - first key in array
	Tree * tree = createTree(0);

	fillTree(parents, tree);

	cout << "Spanning tree:" << endl;
	cout << "Parent : children" << endl;

	printTree(tree);

	deleteTree(tree);

	return EXIT_SUCCESS;
}