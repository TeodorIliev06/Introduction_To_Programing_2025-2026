#include <iostream>

const int MAX_SIZE = 1024;

const char LOWER_LETTER_MIN = 'a';
const char LOWER_LETTER_MAX = 'z';
const char UPPER_LETTER_MIN = 'A';
const char UPPER_LETTER_MAX = 'Z';
const char REPLACEMENT = '*';

const int TOUPPER_TOLOWER = 32;

int strLen(const char* input) {
	int len = 0;

	while (input[len] != '\0')
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

bool charsEqualIgnoreCase(char a, char b) {
	// Convert both to lowercase and compare
	if (a >= UPPER_LETTER_MIN && a <= UPPER_LETTER_MAX) {
		a += TOUPPER_TOLOWER;
	}
	if (b >= UPPER_LETTER_MIN && b <= UPPER_LETTER_MAX) {
		b += TOUPPER_TOLOWER;
	}
	return a == b;
}

void printArr(const char* input) {
	int pos = 0;
	while (input[pos] != '\0')
	{
		std::cout << input[pos++];
	}
}

void toLower(char* input) {
	int pos = 0;
	while (input[pos] != '\0')
	{
		if (input[pos] >= UPPER_LETTER_MIN && input[pos] <= UPPER_LETTER_MAX)
		{
			input[pos] += TOUPPER_TOLOWER;
		}
		pos++;
	}
}

bool isLowerLetter(char ch) {
	return ch >= LOWER_LETTER_MIN && ch <= LOWER_LETTER_MAX;
}

bool isUpperLetter(char ch) {
	return ch >= LOWER_LETTER_MIN && ch <= LOWER_LETTER_MAX;
}

bool isLetter(char ch) {
	if (isLowerLetter(ch) || isUpperLetter(ch))
	{
		return true;
	}

	return false;
}

bool isWordBoundary(char ch) {
	return !isLetter(ch);
}

bool isCompleteWord(const char* source, int pos, int wordLen, int sourceLen) {
	// Check before: pos == 0 OR source[pos-1] is not a letter
	bool beforeOk = (pos == 0) || isWordBoundary(source[pos - 1]);

	// Check after: pos+wordLen == sourceLen OR source[pos+wordLen] is not a letter
	bool afterOk = (pos + wordLen >= sourceLen) || isWordBoundary(source[pos + wordLen]);

	return beforeOk && afterOk;
}

bool contains(const char* input, char target) {
	int pos = 0;
	while (input[pos] != '\0')
	{
		if (input[pos++] == target)
		{
			return true;
		}
	}

	return false;
}

void removeAt(char* input, int index) {
	//TODO: check for index out of bound or nullptr

	while (input[index] != '\0')
	{
		input[index] = input[index + 1];
		index++;
	}

	input[index] = '\0';
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

int getWordOccurrencesCount(const char* source, char* target) {
	if (!source)
	{
		return -1;
	}

	int wordCount = 0;
	bool inWord = false;

	int pos = 0;
	while (source[pos] != '\0')
	{
		if (isLetter(source[pos]))
		{
			if (!inWord)
			{
				inWord = true;
				wordCount++;
			}
		}
		else {
			inWord = false;
		}

		pos++;
	}

	return wordCount;
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

void distinct(char* input) {
	char duplicates[sizeof(input)];

	int pos = 0, ctr = 0;
	while (input[pos] != '\0')
	{
		if (!contains(duplicates, input[pos]))
		{
			duplicates[ctr++] = input[pos++];
		}
		else
		{
			removeAt(input, pos);
		}
	}
}

int findFirstOccurrence(const char* source, size_t sourceLen,
	const char* target, size_t targetLen, int startPos = 0) {
	if (targetLen == 0 || sourceLen == 0)
	{
		return -1;
	}
	if (targetLen > sourceLen)
	{
		return -1;
	}
	if(startPos < 0 || startPos >= sourceLen) {
		return -1;
	}

	for (size_t i = startPos; i <= sourceLen - targetLen; i++)
	{
		bool isContained = true;
		for (size_t j = 0; j < targetLen; j++)
		{
			if (!charsEqualIgnoreCase(source[i + j], target[j]))
			{
				isContained = false;
				break;
			}
		}

		if (isContained)
		{
			return i;
		}
	}

	return -1;
}

void replace(char* source, const char* target, char replacement = REPLACEMENT) {
	int sourceLen = strLen(source);
	int targetLen = strLen(target);

	while (true)
	{
		int foundPos = findFirstOccurrence(source, sourceLen, target, targetLen);

		if (foundPos == -1)
		{
			return;
		}

		for (size_t i = 0; i < targetLen; i++)
		{
			source[foundPos + i] = replacement;
		}
	}
}

void replaceWordsOnly(char* source, const char* target, char replacement = REPLACEMENT) {
	int sourceLen = strLen(source);
	int targetLen = strLen(target);
	int searchPos = 0;

	while (true)
	{
		int foundPos = 
			findFirstOccurrence(source, sourceLen, target, targetLen, searchPos);

		if (foundPos == -1)
		{
			return;
		}

		if (isCompleteWord(source, foundPos, targetLen, sourceLen))
		{
			for (size_t i = 0; i < targetLen; i++)
			{
				source[foundPos + i] = replacement;
			}
		}

		searchPos = foundPos + targetLen;
	}
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

	// 7
	/*char input[MAX_SIZE];

	std::cout << "Please enter the first sentence" << std::endl;
	std::cin.getline(input, MAX_SIZE, '\n');

	toLower(input);
	distinct(input);
	printArr(input);*/

	// 8
	/*char text[MAX_SIZE], word[MAX_SIZE];

	std::cout << "Please enter the sentence" << std::endl;
	std::cin.getline(text, MAX_SIZE, '\n');

	std::cout << "Please enter the target word" << std::endl;
	std::cin.getline(word, MAX_SIZE, '\n');

	int textLen = strLen(text);
	int wordLen = strLen(word);
	std::cout << findFirstOccurrence(text, textLen, word, wordLen);*/

	// 9
	/*char source[MAX_SIZE], target[MAX_SIZE];

	std::cout << "Please enter the first sentence" << std::endl;
	std::cin.getline(source, MAX_SIZE, '\n');

	std::cout << "Please enter the second sentence" << std::endl;
	std::cin.getline(target, MAX_SIZE, '\n');

	std::cout << getWordOccurrencesCount(source, target);*/

	// 10
	char input[MAX_SIZE], target[MAX_SIZE];

	std::cout << "Please enter the first sentence" << std::endl;
	std::cin.getline(input, MAX_SIZE, '\n');

	std::cout << "Please enter the target word" << std::endl;
	std::cin.getline(target, MAX_SIZE, '\n');

	//replace(input, target);
	replaceWordsOnly(input, target);

	printArr(input);
}
