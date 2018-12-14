#include <iostream>
#include <vector>
#include "Test.hpp"

using namespace std;

struct Point
{
	int x = 0;
	int y = 0;
};

int maxInVector(vector<int> &theVector)
{
	int max = theVector[0];
	
	for (int i = 0; i < theVector.size(); ++i)
	{
		if (max < theVector[i])
		{
			max = theVector[i];
		}
	}

	return max;
}

bool isMin(int element, vector<int> &theVector)
{
	for (int i = 0; i < theVector.size(); ++i)
	{
		if (element > theVector[i])
		{
			return false;
		}
	}
	return true;
}

vector<Point*> findPoints(vector<vector<int>> &matrix, int height, int width)
{
	vector<Point*> res;
	int tmp = 0;

	for (int i = 0; i < width; ++i)
	{
		tmp = maxInVector(matrix[i]);
		
		int j = 0;

		while (matrix[i][j] != tmp)
		{
			++j;
		}

		if (isMin(tmp, matrix[j]))
		{
			Point *point = new Point();
			point->x = i;
			point->y = j;
			res.push_back(point);
		}
	}

	return res;
}

int main()
{
	cout << "Running tests!" << endl;

	if (!test())
	{
		cout << "Tests failed!" << endl;
		return EXIT_FAILURE;
	}

	cout << "Tests passed!" << endl;

	int height = 0;
	cout << "Enter matrix heigth: ";
	cin >> height;

	int width = 0;
	cout << "Enter matrix width: ";
	cin >> width;

	int size = 0;
	size = (height > width) ? height : width;

	vector<vector<int>> matrix(size); // 1 -> columns 2 -> rows
	int currentInput = 0;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cin >> currentInput;
			matrix[i].push_back(currentInput);
		}
	}

	cout << "Input is done!" << endl;
	cout << "Matrix:" << endl;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	vector<Point*> answer = findPoints(matrix, height, width);

	cout << "Answer:" << endl;

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i]->x << " " << answer[i]->y << endl;
	}

	return EXIT_SUCCESS;
}