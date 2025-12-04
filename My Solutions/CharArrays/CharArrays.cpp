#include <iostream>

const int MAX_SIZE = 100;
const char LOWER_BOUND = '0';
const char UPPER_BOUND = '9';

void printArr(const char* input, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << input[i];
	}
}

size_t strLen(const char* input) {
	int len = 0;

	while (input[len] != '\0')
	{
		len++;
	}

	return len;
}

int strCmp(const char* first, const char* second) {
	int firstSize = strLen(first);
	int secondSize = strLen(second);

	if (firstSize < secondSize)
	{
		return -1;
	}
	else if (firstSize == secondSize)
	{
		return 0;
	}

	return 1;
}

void strCat(const char* first, const char* second, char* output, size_t& outSize) {
	int len = 0;
	while (first[len] != '\0')
	{
		output[outSize++] = first[len++];
	}

	len = 0;
	while (second[len] != '\0')
	{
		output[outSize++] = second[len++];
	}

	output[outSize] = '\0';
}

void strCpy(const char* source, char* destination, size_t& size) {
	while (source[size] != '\0')
	{
		destination[size] = source[size];
		size++;
	}
}

int customAtoi(const char* input) {
	int output = 0;

	int len = 0;
	while (input[len] != '\0')
	{
		if (input[len] < LOWER_BOUND || input[len] > UPPER_BOUND)
		{
			return -1;
		}

		output = output * 10 + (input[len] - LOWER_BOUND);
		len++;
	}

	return output;
}

bool searchInText(const char* source, size_t sourceLen,
	const char* target, size_t targetLen) {
	if (targetLen == 0 || sourceLen == 0)
	{
		return false;
	}
	if (targetLen > sourceLen)
	{
		return false;
	}

	bool isContained = true;
	for (size_t i = 0; i <= sourceLen - targetLen; i++)
	{
		for (size_t j = 0; j < targetLen; j++)
		{
			if (source[i+j] != target[j])
			{
				isContained = false;
				break;
			}
		}

		if (isContained)
		{
			return true;
		}
	}

	return false;
}

int getCharOccurrencesCount(const char* source, char target) {
	int len = 0;

	int output = 0;
	while (source[len] != '\0')
	{
		if (source[len++] == target)
		{
			output++;
		}
	}

	return output;
}

int main()
{
	#pragma region Examples
	// 1
	/*char input[MAX_SIZE];
	std::cin.getline(input, MAX_SIZE, ' ');

	std::cout << strLen(input) << std::endl;*/

	// 2
	/*char first[MAX_SIZE], second[MAX_SIZE];
	std::cout << "Please enter the first sentence" << std::endl;
	std::cin.getline(first, MAX_SIZE, ' ');

	std::cout << "Please enter the second sentence" << std::endl;
	std::cin.getline(second, MAX_SIZE, ' ');

	std::cout << strCmp(first, second) << std::endl;*/

	// 3
	/*char first[MAX_SIZE], second[MAX_SIZE];

	std::cout << "Please enter the first sentence" << std::endl;
	std::cin.getline(first, MAX_SIZE, '\n');

	std::cout << "Please enter the second sentence" << std::endl;
	std::cin.getline(second, MAX_SIZE, '\n');

	char output[MAX_SIZE * 2];
	size_t outSize = 0;
	strCat(first, second, output, outSize);
	printArr(output, outSize);*/

	// 4
	/*char source[MAX_SIZE], destination[MAX_SIZE];

	std::cout << "Please enter the sentence" << std::endl;
	std::cin.getline(source, MAX_SIZE, '\n');

	size_t size = 0;
	strCpy(source, destination, size);
	printArr(destination, size);*/

	// 5
	/*char input[MAX_SIZE];

	std::cout << "Please enter the sentence" << std::endl;
	std::cin.getline(input, MAX_SIZE, '\n');

	int num = customAtoi(input);
	std::cout << num << std::endl;*/

	// 6
	/*char source[MAX_SIZE], target[MAX_SIZE];

	std::cout << "Please enter the first sentence" << std::endl;
	std::cin.getline(source, MAX_SIZE, '\n');

	std::cout << "Please enter the second sentence" << std::endl;
	std::cin.getline(target, MAX_SIZE, '\n');

	int sourceLen = strLen(source);
	int targetLen = strLen(target);

	std::cout << std::boolalpha <<
		searchInText(source, sourceLen, target, targetLen) << std::endl;*/

	// 7
	/*char source[MAX_SIZE];

	std::cout << "Please enter the first sentence" << std::endl;
	std::cin.getline(source, MAX_SIZE, '\n');

	char target;
	std::cout << "Please enter the target character" << std::endl;
	std::cin >> target;

	std::cout << getCharOccurrencesCount(source, target) << std::endl;*/
	#pragma endregion
}
