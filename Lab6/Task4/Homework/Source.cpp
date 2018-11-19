#include "Menu.hpp"
#include "File.hpp"

int main()
{
	List *list = createList();
	readFromFile(list);
	proceedTask(list);
	return 0;
}