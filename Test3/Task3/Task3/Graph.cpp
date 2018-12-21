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

void refreshIsUsed(vector<bool> &isUsed)
{
	for (bool current : isUsed)
	{
		current = false;
	}
}

bool isAchievedFromAll(vector<bool> &isUsed, vector<vector<int>> &matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		if (!isUsed[i])
		{
			return false;
		}
	}

	return true;
}

int findNewVertex(vector<vector<int>> &matrix, int vertex)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		if (matrix[i][vertex] == 1)
		{
			return i;
		}
	}

	return 0;
}

void findNewPaths(vector<vector<int>> &matrix, vector<bool> &isUsed, int index, int vertex)
{
	for (int i = 0; i < matrix[0].size(); ++i)
	{
		if (matrix[index][i] == -1)
		{
			int newVertex = findNewVertex(matrix, i);

			if (!isUsed[newVertex])
			{
				isUsed[newVertex] = true;
				findNewPaths(matrix, isUsed, newVertex, vertex);
			}
		}
	}
}

void findVertexes(vector<int> &vertexes, ifstream & input)
{
	vector<vector<int>> matrix;
	readFromFile(matrix, input);

	vector<bool> isUsed(matrix.size());

	for (int i = 0; i < matrix.size(); ++i)
	{
		refreshIsUsed(isUsed);

		findNewPaths(matrix, isUsed, i, i);

		isUsed[i] = true;

		if (isAchievedFromAll(isUsed, matrix))
		{
			vertexes.push_back(i);
		}
	}
}