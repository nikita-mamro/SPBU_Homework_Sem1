#include "Functions.hpp"
#include "Test.hpp"

int main()
{
	runTests();
	printf("Input expression in postfix form: \n");
	string input;
	getline(cin, input);
	int result = proceedTask(input);
	cout << "The result is: " << result << endl;
	return 0;
}