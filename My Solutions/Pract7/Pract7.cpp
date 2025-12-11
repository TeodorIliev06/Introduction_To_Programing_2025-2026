#include <iostream>

const int MAX_SIZE = 1024;

const char LOWER_LETTER_MIN = 'a';
const char LOWER_LETTER_MAX = 'z';
const char UPPER_LETTER_MIN = 'A';
const char UPPER_LETTER_MAX = 'Z';

const int TOUPPER_TOLOWER = 32;

int strLen(const char* first) {
	int len = 0;

	while (first[len] != '\0')
	{
		len++;
	}

	return len;
}

int strCmp(const char* first, const char* second) {
	int pos = 0;
	int firstLen = strLen(first);
	int secondLen = strLen(second);

	while (first[pos] != '\0' &&
		second[pos] != '\0')
	{
		if (first[pos] > second[pos])
		{
			return 1;
		}

		if (first[pos] < second[pos])
		{
			return -1;
		}

		pos++;
	}

	// Check which is shorter
	if (first[pos] == '\0' && second[pos] == '\0') {
		return 0;
	}
	if (first[pos] == '\0') {
		return -1;
	}
	return 1;
}

void printArr(const char* input) {
	int pos = 0;
	while (input[pos] != '\0')
	{
		std::cout << input[pos++];
	}
}

bool isLowerLetter(char ch) {
	return ch >= LOWER_LETTER_MIN && ch <= LOWER_LETTER_MAX;
}

void getLowerLetters(const char* input, char* output) {
	int inPos = 0, pos = 0;
	while (input[inPos] != '\0')
	{
		if (isLowerLetter(input[inPos]))
		{
			output[pos++] = input[inPos];
		}

		inPos++;
	}

	output[pos] = '\0';
}

void getSubstring(const char* input, int start, int end, char* output) {
	int pos = 0;

	int len = strLen(input);
	if (start < 0 || end < 0)
	{
		output[pos++] = '\0';
		return;
	}

	if (start > end || start >= len)
	{
		output[pos++] = '\0';
		return;
	}

	if (end > len)
	{
		end = len;
	}

	for (size_t i = start; i <= end; i++)
	{
		output[pos++] = input[i];
	}

	output[pos] = '\0';
}

void replaceInText(char* input, char toReplace, char evenRepl, char oddRepl) {
	int pos = 0, ctr = 0;
	while (input[pos] != '\0')
	{
		if (input[pos] == toReplace)
		{
			ctr++;
			if (ctr % 2 != 0)
			{
				input[pos] = oddRepl;
			}
			else
			{
				input[pos] = evenRepl;
			}
		}

		pos++;
	}
}

int getCharOccurrenceCount(const char* input, char target) {
	int pos = 0, ctr = 0;
	while (input[pos] != '\0')
	{
		if (input[pos++] == target)
		{
			ctr++;
		}
	}

	return ctr;
}

void getCommonPrefix(const char* first, const char* second,
	const char* third, char* output) {
	int inPos = 0;
	int outPos = 0;
	while (first[inPos] != '\0' &&
		second[inPos] != '\0' && third[inPos] != '\0')
	{
		if (first[inPos] != second[inPos] ||
			second[inPos] != third[inPos] ||
			first[inPos] != third[inPos])
		{
			output[outPos] = '\0';
			return;
		}

		output[outPos++] = first[inPos++];
	}

	output[outPos] = '\0';
}
int main()
{
	// 1
	/*char input[MAX_SIZE];
	std::cout << "Please enter a sentence" << std::endl;
	std::cin.getline(input, MAX_SIZE, '\n');

	char output[MAX_SIZE];
	getLowerLetters(input, output);*/

	// 2
	/*char input[MAX_SIZE];
	std::cout << "Please enter a sentence" << std::endl;
	std::cin.getline(input, MAX_SIZE, '\n');

	int start, end;
	std::cout << "Please enter start and end indices" << std::endl;
	std::cin >> start >> end;

	char output[MAX_SIZE];
	getSubstring(input, start, end, output);*/

	// 3
	/*char input[MAX_SIZE];
	std::cout << "Please enter a sentence" << std::endl;
	std::cin.getline(input, MAX_SIZE, '\n');

	char toReplace;
	std::cout << "Please enter character to replace" << std::endl;
	std::cin >> toReplace;

	char evenRepl, oddRepl;
	std::cout << "Please enter first and second character replacements" << std::endl;
	std::cin >> evenRepl >> oddRepl;

	replaceInText(input, toReplace, evenRepl, oddRepl);*/

	// 4
	//char input[MAX_SIZE];

	//std::cout << "Please enter a sentence" << std::endl;
	//std::cin.getline(input, MAX_SIZE, '\n');

	//char target;
	//std::cout << "Please enter target character" << std::endl;
	//std::cin >> target;

	//std::cout << getCharOccurrenceCount(input, target) << std::endl;

	// 5
	/*char first[MAX_SIZE], second[MAX_SIZE], third[MAX_SIZE];

	std::cout << "Please enter the first sentence" << std::endl;
	std::cin.getline(first, MAX_SIZE, '\n');

	std::cout << "Please enter the second sentence" << std::endl;
	std::cin.getline(second, MAX_SIZE, '\n');

	std::cout << "Please enter the third sentence" << std::endl;
	std::cin.getline(third, MAX_SIZE, '\n');

	char commonPrefix[MAX_SIZE];
	getCommonPrefix(first, second, third, commonPrefix);*/

	// 6
	/*char first[MAX_SIZE], second[MAX_SIZE];

	std::cout << "Please enter the first sentence" << std::endl;
	std::cin.getline(first, MAX_SIZE, '\n');

	std::cout << "Please enter the second sentence" << std::endl;
	std::cin.getline(second, MAX_SIZE, '\n');

	int result = strCmp(first, second);
	std::cout << result;*/

}
