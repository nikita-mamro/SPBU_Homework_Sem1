#include <iostream>
#include <fstream>
#include <vector>
#include "AnalyzingData.hpp"

using namespace std;

int main()
{
	ifstream input("input.txt", ios::in);

	if (!input.is_open())
	{
		cout << "Cannot open input.txt file!" << endl;
		return EXIT_FAILURE;
	}

	vector<int> answer = mostPopularPeriod(input);

	cout << "Most popular hours:" << endl;
	cout << "From " << answer[0] << " to " << answer[1] << endl;

	return EXIT_SUCCESS;
}