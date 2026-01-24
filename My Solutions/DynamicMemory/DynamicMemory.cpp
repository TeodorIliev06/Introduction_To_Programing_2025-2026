#include <iostream>
#include <tuple>

int strLen(const char* input) {
	int pos = 0;
	while (input[pos] != '\0')
	{
		pos++;
	}

	return pos;
}

bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

bool isLowerLetter(char ch) {
	return ch >= 'a' && ch <= 'z';
}

bool isUpperLetter(char ch) {
	return ch >= 'A' && ch <= 'Z';
}

void swap(char& first, char& second) {
	char temp = first;
	first = second;
	second = temp;
}

char* getCensoredArr(char* input, char replacement = '*') {
	int len = strLen(input);
	char* output = new char[len + 1];

	for (size_t i = 0; i < len; i++)
	{
		if (isDigit(input[i]))
		{
			output[i] = replacement;
		}
		else
		{
			output[i] = input[i];
		}
	}

	output[len] = '\0';

	return output;
}

std::tuple<char*, char*> getLowerUpperLetters(char* input) {
	int len = strLen(input);
	char* lower = new char[len + 1];
	char* upper = new char[len + 1];

	int lowCtr = 0, upCtr = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (isLowerLetter(input[i]))
		{
			lower[lowCtr++] = input[i];
		}
		else if (isUpperLetter(input[i]))
		{
			upper[upCtr++] = input[i];
		}
	}

	lower[lowCtr] = '\0';
	upper[upCtr] = '\0';

	return { lower, upper };
}

void bubbleSort(char* input, size_t size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		bool areSwapped = false;
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (input[j] > input[j + 1])
			{
				swap(input[j], input[j + 1]);
				areSwapped = true;
			}
		}

		if (!areSwapped) {
			break;
		}
	}
}

char* concatAndSort(const char* firstArr, size_t firstSize,
	const char* secondArr, size_t secondSize) {
	int outSize = firstSize + secondSize;
	char* outArr = new char[outSize + 1];

	int startPos = 0;
	for (size_t i = 0; i < firstSize; i++)
	{
		outArr[startPos + i] = firstArr[i];
	}

	startPos = firstSize;
	for (size_t i = 0; i < secondSize; i++)
	{
		outArr[startPos + i] = secondArr[i];
	}

	outArr[outSize] = '\0';
	//std::cout << outArr << std::endl;
	bubbleSort(outArr, outSize);

	return outArr;
}

char* getSortedLowerLetters(char* input) {
	int len = strLen(input);
	char* output = new char[len + 1];

	int outSize = 0;
	for (size_t i = 0; i < len; i++)
	{
		if (isLowerLetter(input[i]))
		{
			output[outSize++] = input[i];
		}
	}

	bubbleSort(output, outSize);

	output[outSize] = '\0';

	return output;
}

void readMatrix(int n, int m, int** matrix)
{
	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new int[m];

		for (size_t j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void readMatrix(int n, int** matrix)
{
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];

		for (int j = 0; j < n; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void printMatrix(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void deleteMatrix(int n, int** matrix) {
	if (!matrix)
	{
		return;
	}

	for (size_t i = 0; i < n; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

int getSumAbovePrimDiag(int n, int** matrix) {
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i < j)
			{
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}

int** transposeMatrix(int** matrix, int n, int m)
{
	int** transposed = new int* [m];

	for (size_t i = 0; i < m; i++)
	{
		transposed[i] = new int[n];
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			transposed[j][i] = matrix[i][j];
		}
	}

	return transposed;
}

int** multiplyMatrices(int** first, int** second, int firstRows, int firstCols,
	int secondRows, int secondCols) {
	if (!first || !second)
	{
		return nullptr;
	}

	if (firstCols != secondRows)
	{
		return nullptr;
	}

	int outRows = firstRows, outCols = secondCols;
	int** result = new int* [outRows];

	for (int i = 0; i < firstRows; i++)
	{
		result[i] = new int[outCols];
		for (int j = 0; j < secondCols; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < firstCols; k++)
			{
				result[i][j] += first[i][k] * second[k][j];
			}
		}
	}

	return result;
}

int main()
{
#pragma region Examples
	// 1
	/*size_t size;
	std::cin >> size;
	size_t buffer = size + 1;

	char* input = new char[buffer];
	std::cin.ignore();
	std::cin.getline(input, buffer, '\n');

	char* output = getCensoredArr(input);
	std::cout << output << std::endl;

	delete[] input;
	delete[] output;*/

	// 2
	/*size_t size;
	std::cin >> size;
	size_t buffer = size + 1;

	char* input = new char[buffer];
	std::cin.ignore();
	std::cin.getline(input, buffer, '\n');

	auto result = getLowerUpperLetters(input);
	char* lower = std::get<0>(result);
	char* upper = std::get<1>(result);

	std::cout << lower << std::endl;
	std::cout << upper << std::endl;*/

	// 3
	/*size_t firstSize, secondSize;
	std::cin >> firstSize >> secondSize;
	std::cin.ignore();

	char* firstArr = new char[firstSize + 1];
	std::cin.getline(firstArr, firstSize + 1, '\n');

	char* secondArr = new char[secondSize + 1];
	std::cin.getline(secondArr, secondSize + 1, '\n');

	int firstLen = strLen(firstArr);
	int secondLen = strLen(secondArr);
	char* outArr = concatAndSort(firstArr, firstLen, secondArr, secondLen);
	std::cout << outArr << std::endl;*/

	// 4
	/*size_t size;
	std::cin >> size;
	size_t buffer = size + 1;

	char* input = new char[buffer];
	std::cin.ignore();
	std::cin.getline(input, buffer, '\n');

	char* output = getSortedLowerLetters(input);
	std::cout << output << std::endl;

	delete[] input;
	delete[] output;*/
#pragma endregion

#pragma region Exercises
	// 1
	/*int n;
	std::cin >> n;
	int* arr = new int[n];*/

	// 2
	/*int n, m;
	std::cin >> n >> m;
	int** arr = new int* [n];

	for (size_t i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}*/

	// 3
	/*int n, m, q;
	std::cin >> n >> m >> q;
	int*** arr = new int** [n];

	for (size_t i = 0; i < n; i++)
	{
		arr[i] = new int*[m];
		for (size_t j = 0; j < m; j++)
		{
			arr[i][j] = new int[q];
		}
	}*/

	// 4
	/*int n;
	std::cin >> n;

	int** matrix = new int* [n];
	readMatrix(n, matrix);

	int sum = getSumAbovePrimDiag(n, matrix);
	std::cout << sum << std::endl;

	deleteMatrix(n, matrix);*/

	// 5
	/*int n, m;
	std::cin >> n >> m;
	int** matrix = new int* [n];
	readMatrix(n, m, matrix);

	int** transposed = transposeMatrix(matrix, n, m);
	printMatrix(transposed, m, n);

	deleteMatrix(n, matrix);
	deleteMatrix(m, transposed);*/

	// 6
	int n, m, p, q;
	std::cin >> n >> m >> p >> q;

	int** firstMatrix = new int* [n];
	int** secondMatrix = new int* [p];
	readMatrix(n, m, firstMatrix);
	readMatrix(p, q, secondMatrix);

	int** outMatrix = multiplyMatrices(firstMatrix, secondMatrix, n, m, p, q);

	if (outMatrix)
	{
		printMatrix(outMatrix, n, q);
		deleteMatrix(n, outMatrix);
	}

	deleteMatrix(n, firstMatrix);
	deleteMatrix(p, secondMatrix);
#pragma endregion
}
