#include <iostream>

const int MAX_SIZE = 100;
const int TO_LOWER_TO_UPPER = 32;

int strLen(const char* input) {
	int pos = 0;

	while (input[pos] != '\0')
	{
		pos++;
	}

	return pos;
}

void swap(char& first, char& second) {
	int temp = first;
	first = second;
	second = temp;
}

bool isLowerLetter(char ch) {
	return ch >= 'a' && ch <= 'z';
}

bool isUpperLetter(char ch) {
	return ch >= 'A' && ch <= 'Z';
}

bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

void toUpperLower(char* input) {
	int pos = 0;

	while (input[pos] != '\0')
	{
		if (isLowerLetter(input[pos]))
		{
			input[pos] -= TO_LOWER_TO_UPPER;
		}
		else if (isUpperLetter(input[pos]))
		{
			input[pos] += TO_LOWER_TO_UPPER;
		}

		pos++;
	}
}

bool contains(const char* input, char target) {
	int pos = 0;
	while (input[pos] != '\0')
	{
		if (input[pos] == target)
		{
			return true;
		}
		pos++;
	}

	return false;
}

void replaceSymbols(char* str, const char* delimiters, const char replacement) {
	int pos = 0;

	while (str[pos] != '\0')
	{
		/*if (contains(delimiters, str[pos]))
		{
			str[pos] = replacement;
		}*/
		if (!isLowerLetter(str[pos]) &&
			!isUpperLetter(str[pos]) &&
			!isDigit(str[pos]))
		{
			str[pos] = replacement;
		}
		pos++;
	}
}

void replaceDigits(char* str) {
	int pos = 0;

	while (str[pos] != '\0')
	{
		if (isDigit(str[pos]))
		{
			/*int replacement = ((str[pos] - '0' + 7) ^ (str[pos] - '0')) % 10;
			str[pos] = replacement + '0';*/
			str[pos] = ((str[pos] - '0') % 2) + '0';
		}
		pos++;
	}
}

void readArr(int* input, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> input[i];
	}
}

void printArr(const char* input) {
	int pos = 0;

	while (input[pos] != '\0')
	{
		std::cout << input[pos++];
	}
}

void reverse(char* input) {
	int len = strLen(input);

	for (int i = 0; i < len / 2; i++)
	{
		swap(input[i], input[len - i - 1]);
	}
}

void reverseByHalves(char* input) {
	int len = strLen(input);
	int mid = len / 2;

	for (int i = 0; i < mid / 2; i++)
	{
		swap(input[i], input[mid - i - 1]);
	}

	int secondStartPos = (len % 2 == 0) ? 0 : 1;
	for (int i = 0; i < (len - mid) / 2; i++)
	{
		swap(input[mid + i + secondStartPos], input[len - i - 1]);
	}
}

void convertString(char* input) {
	char delimiters[MAX_SIZE];

	std::cout << "Enter delimiters" << std::endl;
	std::cin.getline(delimiters, MAX_SIZE, '\n');

	replaceSymbols(input, delimiters, '*');
	toUpperLower(input);
	replaceDigits(input);
	//reverseByHalves(input);
}

int getMinSumSubSeq(int* arr, int len, int subSeqLen) {
	int outSum = 0;
	for (size_t i = 0; i <= len - subSeqLen; i++)
	{
		int currMin = arr[i];
		for (size_t j = 0; j < subSeqLen; j++)
		{
			if (arr[i+j] < currMin)
			{
				currMin = arr[i + j];
			}
		}
		outSum += currMin;
	}

	return outSum;
}

int main()
{
	/*char input[MAX_SIZE];

	std::cout << "Enter input" << std::endl;
	std::cin.getline(input, MAX_SIZE, '\n');

	convertString(input);

	printArr(input);*/

	int arr[MAX_SIZE];
	size_t size, subSeqLen;
	std::cin >> size >> subSeqLen;

	readArr(arr, size);

	std::cout << getMinSumSubSeq(arr, size, subSeqLen);
}
