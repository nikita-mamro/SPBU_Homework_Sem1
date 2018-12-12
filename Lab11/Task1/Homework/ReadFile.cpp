#include "ReadFile.hpp"

string readFromFile(ifstream & input)
{
	input.seekg(0, ios::end);
	size_t length = input.tellg();
	input.seekg(0);
	string result(length + 1, '\0');
	input.read(&result[0], length);
	return result;
}
