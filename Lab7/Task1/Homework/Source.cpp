#include "Menu.hpp"
#include "Test.hpp"
#include <iostream>
#include <string>

int main()
{
	std::vector<std::string> result;

	if (!test(result))
	{
		std::cout << "Tests failed!" << std::endl;
		for (int i = 0; i < result.size(); ++i)
		{
			std::cout << result[i] << std::endl;
		}
		return EXIT_FAILURE;
	}
	else
	{
		std::cout << "Tests passed!" << std::endl;
	}

	proceedTask();
	return EXIT_SUCCESS;
}