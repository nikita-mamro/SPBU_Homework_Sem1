#include "Graph.hpp"
#include <fstream>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

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
			if (current == 1)
			{
				current = 999;
			}
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


	for (int k = 0; k < matrix.size(); ++k)
	{
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix.size(); ++j)
			{
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	// found shortest ways, need to check if != 0

	for (int i = 0; i < matrix.size(); ++i)
	{
		bool isAchieved = true;

		for (int j = 0; j < matrix.size(); ++j)
		{
			if (matrix[i][j] == 0 || matrix[i][j] == 999)
			{
				isAchieved = false;
			}
		}

		if (isAchieved)
		{
			verticles.push_back(i);
		}
	}
}
