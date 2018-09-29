#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int subStrCount(char *str, char *substr)
{
	int count = 0;
	int subStrSize = 0;
	int strSize = 0;
	int mainIndex = 0;
	int strIndex = 0;
	int substrIndex = 0;

	strSize = strlen(str);
	subStrSize = strlen(substr);

	while (str[mainIndex] != '\0') {
		if (str[mainIndex] != substr[0]) {
			mainIndex++;
			continue;
		}
		else {
			if (strSize - mainIndex < subStrSize) {
				return count;
			}
			else {
				strIndex = mainIndex;
				while (substr[substrIndex] != '\0') {
					if (str[strIndex] == substr[substrIndex]) {
						strIndex++;
						substrIndex++;
					}
					else {
						break;
					}
				}
				if (substr[substrIndex] == '\0') {
					count++;
				}
				mainIndex++;
				substrIndex = 0;
			}
		}
	}
	return count;
}

int main()
{
	int strLength = 0;
	int subStrLength = 0;

	while (true) {
		printf("Enter the max length of a string: ");
		scanf("%d", &strLength);
		printf("Enter the max length of a substring: ");
		scanf("%d", &subStrLength);
		if (subStrLength > strLength) {
			printf("The length of a string can't be less than the length of a substring!\n");
			continue;
		}
		else {
			printf("You successfuly entered the max length of a string and the max length of a substring!\n");
			break;
		}
	}

	char *str = new char[strLength + 1]{};
	char *substr = new char[subStrLength + 1]{};

	printf("Enter the string: ");
	scanf("%s", str);
	printf("Enter the substring: ");
	scanf("%s", substr);

	printf("Substrings in string: %d\n", subStrCount(str, substr));

	delete[] str;
	delete[] substr;

	return 0;
}