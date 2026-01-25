#include <iostream>

long findSeq(const char* src, int target) {
	int bestLen = 0, currLen = 0;

	int len = strlen(src);
	for (size_t i = 0; i < len; i++)
	{
		if (src[i] == target)
		{
			currLen++;
			if (currLen > bestLen)
			{
				bestLen = currLen;
			}
		}
		else
		{
			currLen = 0;

		}
	}

	return bestLen;
}

void readMatrix(int rows, int cols, char** matrix) {
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new char[cols];
		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void deleteMatrix(int rows, char** matrix) {
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

bool findWord(const char* const* grid, int rows, int cols, const char* word) {
	int wordLen = strlen(word);

	for (size_t row = 0; row < rows; row++)
	{
		int temp = wordLen;
		for (size_t col = 0; col < cols; col++)
		{
			if (col + wordLen <= cols)
			{
				bool match = true;
				for (size_t k = 0; k < wordLen; k++)
				{
					if (grid[row][col + k] != word[k])
					{
						match = false;
						break;
					}
				}

				if (match)
				{
					return true;
				}
			}

			if (row + wordLen <= rows)
			{
				bool match = true;
				for (size_t k = 0; k < wordLen; k++)
				{
					if (grid[row + k][col] != word[k])
					{
						match = false;
						break;
					}
				}

				if (match)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool checkDirection(const char* const* grid, int r, int c,
	int rows, int cols, const char* word, int dRow, int dCol) {
	if (*word == '\0')
	{
		return true;
	}

	if (r >= rows || c >= cols ||
		grid[r][c] != *word)
	{
		return false;
	}

	return checkDirection(grid, r + dRow, c + dCol, rows, cols, word + 1, dRow, dCol);
}

bool findWordRecursive(const char* const* grid, int rows, int cols,
	const char* word) {
	for (size_t row = 0; row < rows; row++)
	{
		for (size_t col = 0; col < cols; col++)
		{
			// Horizontal
			if (checkDirection(grid, row, col, rows, cols, word, 1, 0))
			{
				return true;
			}

			// Vertical
			if (checkDirection(grid, row, col, rows, cols, word, 0, 1))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	// 1
	/*int size;
	std::cout << "Please enter a valid size: ";
	std::cin >> size;

	char target;
	std::cout << "Please enter the target symbol: ";
	std::cin >> target;
	std::cin.ignore();

	char* src = new char[size + 1];
	std::cin.getline(src, size + 1, '\n');

	std::cout << findSeq(src, target);*/

	// 2
	int rows, cols;
	std::cout << "Please enter valid rows and cols: ";
	std::cin >> rows >> cols;

	char** matrix = new char* [rows];
	readMatrix(rows, cols, matrix);

	int wordSize;
	std::cout << "Please enter valid word size: ";
	std::cin >> wordSize;
	std::cin.ignore();

	char* word = new char[wordSize + 1];
	std::cin.getline(word, wordSize + 1, '\n');

	//std::cout << std::boolalpha << findWord(matrix, rows, cols, word);
	std::cout << std::boolalpha << findWordRecursive(matrix, rows, cols, word);
	deleteMatrix(rows, matrix);
}
