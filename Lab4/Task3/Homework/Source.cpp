#include "File.hpp"
#include "Menu.hpp"
#include "Test.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");
	askForTests();
	proceedTask();
	system("PAUSE");
	return 0;
}