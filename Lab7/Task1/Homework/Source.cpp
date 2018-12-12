#include "Menu.hpp"
#include "Test.hpp"
#include <iostream>
#include <string>

int main()
{
	std::vector<std::string> testResult;

	if (!test(testResult))
	{
		std::cout << "Tests failed!" << std::endl;
		for (int i = 0; i < testResult.size(); ++i)
		{
			std::cout << testResult[i] << std::endl;
		}
		return EXIT_FAILURE;
	}
	std::cout << "Tests passed!" << std::endl;

	proceedTask();
	return EXIT_SUCCESS;
}