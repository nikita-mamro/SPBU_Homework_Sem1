#include "Graph.hpp"
#include <fstream>

using namespace std;

void readFromFile(vector<vector<int>>& matrix, ifstream & input)
{
	int current = 0;
	int i = 0;

	while (!input.eof())
	{
		vector<int> matrixRow;
		matrix.push_back(matrixRow);

		while (!input.eof() && input.peek() != '\n')
		{
			input >> current;
			matrix[i].push_back(current);
		}
		input.get();
		++i;
	}
}

void findVerticles(vector<int> &verticles, ifstream & input)
{
	vector<vector<int>> matrix;
	readFromFile(matrix, input);
}
