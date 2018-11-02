#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char lastBracketInStack(char *stack)
{
	if (stack[0] == '0') {
		return '0';
	}
	int i = 0;
	while (stack[i] != '0') {
		i++;
	}
	return stack[i - 1];
}

int lastBracketInStackIndex(char *stack)
{
	int i = 0;
	while (stack[i] != '0') {
		i++;
	}
	return i - 1;
}

void removeBracketFromStack(char *stack, int bracketIndex)
{
	stack[bracketIndex] = '0';
}

bool isBalanced(char* str, int stringLength)
{
	char *bracketStack = new char[stringLength] {'0'};
	for (int i = 0; i < stringLength; ++i) {
		bracketStack[i] = '0';
	}
	printf("Initial stack: ");
	for (int i = 0; i < stringLength; ++i) {
		printf(" %c,", bracketStack[i]);
	}
	printf("\n");
	int i = 0;
	int j = 0;
	while (str[i] != '\0') {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[' || str[i] == '<') {
			bracketStack[j] = str[i];
			printf("%c added to stack\n", str[i]);
			j++;
			i++;
			continue;
		}
		else if (str[i] == ')') {
			printf("Entered: ), Last bracket: %c\n", lastBracketInStack(bracketStack));
			if (lastBracketInStack(bracketStack) == '(') {
				printf("Removing bracket %c with stack index %d\n", lastBracketInStack(bracketStack), lastBracketInStackIndex(bracketStack));
				removeBracketFromStack(bracketStack, lastBracketInStackIndex(bracketStack));
				j--;
				i++;
			}
			else return false;
		}
		else if (str[i] == '}') {
			printf("Entered: }, Last bracket: %c\n", lastBracketInStack(bracketStack));
			if (lastBracketInStack(bracketStack) == '{') {
				printf("Removing bracket %c with stack index %d\n", lastBracketInStack(bracketStack), lastBracketInStackIndex(bracketStack));
				removeBracketFromStack(bracketStack, lastBracketInStackIndex(bracketStack));
				j--;
				i++;
			}
			else return false;
		}
		else if (str[i] == ']') {
			printf("Entered: ], Last bracket: %c\n", lastBracketInStack(bracketStack));
			if (lastBracketInStack(bracketStack) == '[') {
				printf("Removing bracket %c with stack index %d\n", lastBracketInStack(bracketStack), lastBracketInStackIndex(bracketStack));
				removeBracketFromStack(bracketStack, lastBracketInStackIndex(bracketStack));
				j--;
				i++;
			}
			else return false;
		}
		else if (str[i] == '>') {
			printf("Entered: >, Last bracket: %c\n", lastBracketInStack(bracketStack));
			if (lastBracketInStack(bracketStack) == '<') {
				printf("Removing bracket %c with stack index %d\n", lastBracketInStack(bracketStack), lastBracketInStackIndex(bracketStack));
				removeBracketFromStack(bracketStack, lastBracketInStackIndex(bracketStack));
				j--;
				i++;
			}
			else return false;
		}
		else i++;
	} // êîíåö öèêëà
	printf("%c - last bracket in stack (if 0, there are no brackets)\n\n", lastBracketInStack(bracketStack));
	if (lastBracketInStack(bracketStack) == '0') {
		delete[] bracketStack;
		return true;
	}
	else {
		delete[] bracketStack;
		return false;
	}
}

int main()
{
	int length = 0;
	printf("You can check the balance of these types of brackets: () [] {} <>\n");
	printf("Input the string's length: ");
	scanf("%d", &length);

	char *str = new char[length] {};

	scanf("%s", str);
	printf("You entered string : %s\n\n", str);
	printf("Checking bracket balance...\n\n");
	printf(isBalanced(str, length) ? "Balance: true" : "Balance: false");

	delete[] str;

	return 0;
}