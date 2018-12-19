#include "ReadFile.hpp"
#include <string>

std::string readFromFile(std::ifstream & input)
{
	input.seekg(0, std::ios::end);
	size_t length = input.tellg();
	input.seekg(0);
	std::string result(length + 1, '\0');
	input.read(&result[0], length);
	return result;
}
