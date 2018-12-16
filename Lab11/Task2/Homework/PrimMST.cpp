#include "PrimMST.hpp"

void readFromFile(vector<vector<int>> & graph, ifstream & input)
{
	int current = 0;
	int i = 0;
	
	while (!input.eof())
	{
		while (input.peek() != '\n')
		{
			input >> current;
			graph[i].push_back(current);
		}
		++i;
	}
}
