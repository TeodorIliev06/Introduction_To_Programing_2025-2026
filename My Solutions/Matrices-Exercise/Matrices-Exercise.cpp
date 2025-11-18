#include <iostream>

const size_t MATRIX_ROW_SIZE = 3;
const size_t MATRIX_COL_SIZE = 3;

void readMatrix(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			std::cin >> matrix[row][col];
		}
	}
}

void readMatrix(double matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
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

void swap(double& firstNum, double& secondNum) {
	double temp = firstNum;
	firstNum = secondNum;
	secondNum = temp;
}

int abs(int num) {
	return num > 0 ? num : -num;
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

void sumMatrices(int firstMatrix[][MATRIX_COL_SIZE],
	int secondMatrix[][MATRIX_COL_SIZE],
	int outputMatrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			outputMatrix[row][col] = firstMatrix[row][col] + secondMatrix[row][col];
		}
	}
}

void multiplyMatrixByANumber(int matrix[][MATRIX_COL_SIZE], int multiplier,
	int outputMatrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			outputMatrix[row][col] = matrix[row][col] * multiplier;
		}
	}
}

void multiplyMatrices(int firstMatrix[][MATRIX_COL_SIZE],
	int secondMatrix[][MATRIX_COL_SIZE], int outputMatrix[][MATRIX_COL_SIZE],
	size_t firstMatrixRowSize, size_t firstMatrixColSize,
	size_t secondMatrixRowSize, size_t secondMatrixColSize,
	size_t* outRowSize, size_t* outColSize) {
	if (firstMatrixColSize != secondMatrixRowSize)
	{
		return;
	}

	*outRowSize = firstMatrixRowSize;
	*outColSize = secondMatrixColSize;

	if (*outRowSize > MATRIX_ROW_SIZE ||
		*outColSize > MATRIX_COL_SIZE)
	{
		return;
	}

	for (size_t i = 0; i < firstMatrixRowSize; i++)
	{
		for (size_t j = 0; j < secondMatrixColSize; j++)
		{
			outputMatrix[i][j] = 0;
			for (size_t k = 0; k < firstMatrixColSize; k++)
			{
				outputMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}
}

void printInSpiral(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	int top = 0, bottom = rowSize - 1;
	int left = 0, right = colSize - 1;

	while (top <= bottom && left <= right)
	{
		// Print top row
		for (size_t col = left; col <= right; col++)
		{
			std::cout << matrix[top][col] << " ";
		}
		top++;

		// Print right col;
		for (size_t row = top; row <= bottom; row++)
		{
			std::cout << matrix[row][right] << " ";
		}
		right--;

		// Print bottom row (right to left)
		if (top <= bottom)
		{
			for (int col = right; col >= left; col--)
			{
				std::cout << matrix[bottom][col] << " ";
			}
			bottom--;
		}

		// Print left col (bottom to top)
		if (left <= right)
		{
			for (int row = bottom; row >= top; row--)
			{
				std::cout << matrix[row][left] << " ";
			}
			left++;
		}
	}
}

void rotateRight(int matrix[][MATRIX_COL_SIZE], size_t rowSize, size_t colSize) {
	transpone(matrix, rowSize, colSize);

	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize / 2; col++)
		{
			swap(matrix[row][col], matrix[row][colSize - 1 - col]);
		}
	}
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

	// 7
	//  7.1
	//int firstMatrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(firstMatrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//int secondMatrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(secondMatrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//int outputMatrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];

	//sumMatrices(firstMatrix, secondMatrix, outputMatrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//printMatrix(outputMatrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//  7.2
	//int firstMatrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(firstMatrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//std::cout << "Please enter a multiplier: ";
	//int multiplier;
	//std::cin >> multiplier;

	//int outputMatrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];

	//multiplyMatrixByANumber(firstMatrix, multiplier, outputMatrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//printMatrix(outputMatrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	// 8
	//int firstMatrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(firstMatrix, 5, 2);

	//int secondMatrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(secondMatrix, 2, 3);

	//int outputMatrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//size_t outRowSize, outColSize;

	//multiplyMatrices(firstMatrix, secondMatrix, outputMatrix,
	//	5, 2, 2, 3, &outRowSize, &outColSize);

	//printMatrix(outputMatrix, outRowSize, outColSize);

	// 9
	//int matrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//printInSpiral(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	// 10
	//int matrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	//readMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	//rotateRight(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);
	//printMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

}
