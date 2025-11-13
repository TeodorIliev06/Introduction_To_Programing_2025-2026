#include <iostream>

const size_t MATRIX_ROW_SIZE = 4;
const size_t MATRIX_COL_SIZE = 4;

void readMatrix(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			std::cin >> matrix[row][col];
		}
	}
}

void printMatrix(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			std::cout << matrix[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

void swap(int& firstNum, int& secondNum) {
	int temp = firstNum;
	firstNum = secondNum;
	secondNum = temp;
}

int getMin(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	int min = matrix[0][0];

	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			if (matrix[row][col] < min)
			{
				min = matrix[row][col];
			}
		}
	}

	return min;
}

void printPrimaryDiagonal(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			if (row == col)
			{
				std::cout << matrix[row][col] << " ";
			}
		}
	}
}

void printSecondaryDiagonal(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			if (row + col == MATRIX_COL_SIZE - 1)
			{
				std::cout << matrix[row][col] << " ";
			}
		}
	}
}

void printInZigZagPattern(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 0; row < rowSize; row++)
	{
		if (row % 2 == 0)
		{
			for (size_t col = 0; col < colSize; col++)
			{
				std::cout << matrix[row][col] << " ";
			}
			std::cout << std::endl;
		}
		else
		{
			for (int col = colSize - 1; col >= 0; col--)
			{
				std::cout << matrix[row][col] << " ";
			}
			std::cout << std::endl;
		}
	}
}

bool isMatrixTriangular(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 1; row < rowSize; row++)
	{
		for (size_t col = 0; col < row && col < colSize; col++)
		{
			if (matrix[row][col] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

void transpone(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = row + 1; col < colSize; col++)
		{
			swap(matrix[row][col], matrix[col][row]);
		}
	}
}

/// <summary>
/// We will get a target sum (first row for example)
/// Then we compare with each other possible sum
/// Short circuit if current sum != target sum
/// </summary>
/// <param name="matrix"></param>
/// <param name="rowSize"></param>
/// <param name="colSize"></param>
/// <returns></returns>
bool isMagicSquare(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	int targetSum = 0;
	for (size_t col = 0; col < rowSize; col++)
	{
		targetSum += matrix[0][col];
	}

	// Check all rows (besides first)
	for (size_t row = 1; row < rowSize; row++)
	{
		int rowSum = 0;
		for (size_t col = 0; col < colSize; col++)
		{
			rowSum += matrix[row][col];
		}

		if (rowSum != targetSum)
		{
			return false;
		}
	}

	for (size_t col = 0; col < colSize; col++)
	{
		int colSum = 0;
		for (size_t row = 0; row < rowSize; row++)
		{
			colSum += matrix[row][col];
		}

		if (colSum != targetSum)
		{
			return false;
		}
	}

	int primaryDiagonalSum = 0;
	for (size_t i = 0; i < rowSize; i++)
	{
		primaryDiagonalSum += matrix[i][i];
	}

	if (primaryDiagonalSum != targetSum)
	{
		return false;
	}

	int secondaryDiagonalSum = 0;
	for (size_t i = 0; i < rowSize; i++)
	{
		secondaryDiagonalSum += matrix[i][rowSize - i - 1];
	}

	if (secondaryDiagonalSum != targetSum)
	{
		return false;
	}

	return true;
}

int main()
{
	// 1
	/*int matrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	readMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	int min = getMin(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);
	std::cout << min << std::endl;*/

	// 2
	//int matrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//printPrimaryDiagonal(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);
	//std::cout << std::endl;
	//printSecondaryDiagonal(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	// 3
	//int matrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//printInZigZagPattern(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	// 4
	//int matrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//std::cout << isMatrixTriangular(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE) << std::endl;

	// 5
	/*int matrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	readMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	transpone(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);
	printMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);*/

	// 6
	//int matrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//std::cout << (isMagicSquare(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE)
	//	? "yes" : "no") << std::endl;
}
