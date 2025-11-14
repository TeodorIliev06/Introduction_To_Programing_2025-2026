#include <iostream>

const size_t MAX_SIZE = 100;

int getMinEl(const int matrix[][MAX_SIZE], size_t n, size_t m)
{
	if (!matrix)
		return -1;

	int min = matrix[0][0];

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
		}
	}

	return min;
}

void printMainDiagonal(const int matrix[][MAX_SIZE], size_t n) {
	if (!matrix)
		return;

	for (size_t i = 0; i < n; i++)
	{
		std::cout << matrix[i][i] << " ";
	}
	std::cout << std::endl;
}

void printSecondaryDiagonal(const int matrix[][MAX_SIZE], size_t n) {
	if (!matrix)
		return;

	for (size_t row = 0; row < n; row++, row++)
	{
		std::cout << matrix[row][n - 1 - row];
	}



	std::cout << std::endl;
}

void printZigZag(const int matrix[][MAX_SIZE], size_t n, size_t m) {
	if (!matrix)
		return;

	for (size_t row = 0; row < n; row++)
	{
		if (row % 2 == 0)
		{
			for (size_t col = 0; col < m; col++)
			{
				std::cout << matrix[row][col];
			}
		}
		else
		{
			for (int col = m - 1; col >= 0; col--)
			{
				std::cout << matrix[row][col];
			}
		}

		std::cout << std::endl;
	}
}

bool isTriangular(const int matrix[][MAX_SIZE], size_t n) {
	if (!matrix)
		return false;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (i > j && matrix[i][j] != 0)
				return false;
		}
	}

	return true;
}

void swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

void transpose(int matrix[][MAX_SIZE], size_t n) {
	if (!matrix)
		return;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}

int getMainDiagonalSum(const int matrix[][MAX_SIZE], size_t n) {
	if (!matrix)
		return -1;

	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += matrix[i][i];
	}

	return sum;
}

int getSecondaryDiagonalSum(const int matrix[][MAX_SIZE], size_t n) {
	if (!matrix)
		return -1;

	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += matrix[i][n - 1 - i];
	}

	return sum;
}

int getRowSum(const int matrix[][MAX_SIZE], size_t n, size_t row) {
	if (!matrix)
		return -1;

	int sum = 0;
	for (size_t col = 0; col < n; col++)
	{
		sum += matrix[row][col];
	}

	return sum;
}

int getColSum(const int matrix[][MAX_SIZE], size_t n, size_t col) {
	if (!matrix)
		return -1;

	int sum = 0;
	for (size_t row = 0; row < n; row++)
	{
		sum += matrix[row][col];
	}

	return sum;
}

bool isMagicSquare(const int matrix[][MAX_SIZE], size_t n) {
	if (!matrix)
		return false;

	int sum = getMainDiagonalSum(matrix, n);

	if (sum != getSecondaryDiagonalSum(matrix, n))
		return false;

	for (size_t row = 0; row < n; row++)
	{
		int rowSum = getRowSum(matrix, n, row);
		if (rowSum != sum)
		{
			return false;
		}
	}

	for (size_t col = 0; col < n; col++)
	{
		int colSum = getColSum(matrix, n, col);
		if (colSum != sum)
		{
			return false;
		}
	}

	return true;
}

void multiplyMatrices(const int matrix1[][MAX_SIZE], size_t r1, size_t c1,
	const int matrix2[][MAX_SIZE], size_t r2, size_t c2, int result[][MAX_SIZE]) {
	if (c1 != r2)
		return;

	for (size_t i = 0; i < r1; i++)
	{
		for (size_t j = 0; j < c2; j++)
		{
			for (size_t k = 0; k < c1; k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}

void readMatrix(int matrix[][MAX_SIZE], size_t n, size_t m) {
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cin >> matrix[i][j];
		}
	}
}

int main()
{
	int matrix[MAX_SIZE][MAX_SIZE];
	int matrix2[MAX_SIZE][MAX_SIZE];
	int result[MAX_SIZE][MAX_SIZE];
	int n1, m1, n2, m2;
	std::cin >> n1 >> m1;

	readMatrix(matrix, n1, m1);

	std::cin >> n2 >> m2;
	readMatrix(matrix, n2, m2);

	multiplyMatrices(matrix, n1, m1, matrix2, n2, m2, result);

	for (size_t i = 0; i < n1; i++)
	{
		for (size_t j = 0; j < m2; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

}
