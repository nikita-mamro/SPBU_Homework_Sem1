#include "Test.hpp"
#include <vector>
#include <string>
#include "PrimMST.hpp"
#include "Tree.hpp"

using namespace std;

bool test(vector<string>& result)
{
	bool res = true;

	ifstream testInput("testinput.txt", ios::in);

	if (!testInput.is_open())
	{
		res = false;
		result.push_back("Cannot open testinput.txt file!");
		return res;
	}

	vector<vector<int>> testGraph = readFromFile(testInput);

	vector<int> parents(testGraph.size());

	primMST(parents, testGraph);

	if (parents.size() != testGraph.size())
	{
		res = false;
		result.push_back("Error : not all vertices of graph are included in set!");
		testInput.close();
		return res;
	}

	if (parents[0] != -1 || parents[1] != 0 || parents[2] != 1 || parents[3] != 0 || parents[4] != 1)
	{
		res = false;
		result.push_back("Error : wrong set of parents!");
		testInput.close();
		return res;
	}

	// 0 - first key in array
	Tree * testTree = createTree(0);

	fillTree(parents, testTree);
	deleteTree(testTree);

	testInput.close();

	return res;
}
