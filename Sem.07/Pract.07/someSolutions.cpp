
#include <iostream>


bool isSubarr(const int* arr, const int* subArr, size_t arrSize, size_t subArrSize) {
	if (!arr || !subArr)
		return false;

	if (subArrSize > arrSize)
		return false;

	for (size_t i = 0; i <= arrSize - subArrSize; i++)
	{
		bool isSubarray = true;

		for (size_t j = 0; j < subArrSize; j++)
		{
			if (arr[i + j] != subArr[j])
			{
				isSubarray = false;
				break;
			}
		}

		if (isSubarray)
		{
			return true;
		}
	}

	return false;
}

const size_t MAX_SIZE = 100;

int minSubMatrixSum(const int matrix[][MAX_SIZE], size_t rows, size_t cols, size_t subMatrixSize) {
	if (!matrix)
		return -1;

	int min = INT_MAX;

	for (size_t i = 0; i <= rows - subMatrixSize; i++)
	{
		for (size_t j = 0; j <= cols - subMatrixSize; j++)
		{
			int currMin = 0;

			for (size_t k = 0; k < subMatrixSize; k++)
			{
				for (size_t l = 0; l < subMatrixSize; l++)
				{
					currMin += matrix[i + k][j + l];
				}
			}

			if (currMin < min)
			{
				min = currMin;
			}
		}
	}

	return min;
}

void printSpiral(const int matrix[][MAX_SIZE], size_t rows, size_t cols) {
	if (!matrix)
		return;

	int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

	while (top <= bottom && left <= right)
	{
		for (size_t i = left; i <= right; i++)
		{
			std::cout << matrix[top][i] << " ";
		}
		top++;

		if (left <= right)
		{
			for (size_t i = top; i <= bottom; i++)
			{
				std::cout << matrix[i][right] << " ";
			}
			right--;
		}

		if (top <= bottom)
		{
			for (int i = right; i >= left; i--)
			{
				std::cout << matrix[bottom][i] << " ";
			}
			bottom--;
		}

		if (left <= right)
		{
			for (int i = bottom; i >= top; i--)
			{
				std::cout << matrix[i][left] << " ";
			}
			left++;
		}
	}
}


const int MAX_ROWS = 50;
const int MAX_COLS = 50;


void readMatrix(int arr[MAX_ROWS][MAX_COLS], int rows, int cols)
{
	if (rows < 0 || cols < 0 || rows > MAX_ROWS || cols > MAX_COLS)
	{
		std::cout << "INVALID DATA" << std::endl;
		return;
	}
	for (unsigned i = 0; i < rows; i++)
	{
		for (unsigned j = 0; j < cols; j++)
		{
			std::cin >> arr[i][j];
		}
	}

}

int sumRows(int arr[MAX_ROWS][MAX_COLS], int row, int n)
{
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += arr[row][i];
	}
	return sum;
}

int sumCols(int arr[MAX_ROWS][MAX_COLS], int cols, int n)
{
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += arr[i][cols];
	}
	return sum;
}

int sumMainDiag(int arr[MAX_ROWS][MAX_COLS], int n)
{
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += arr[i][i];
	}
	return sum;
}

int sumSecondaryDiag(int arr[MAX_ROWS][MAX_COLS], int n)
{
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		sum += arr[i][n - 1 - i];
	}
	return sum;
}
bool isMagicSquare(int arr[MAX_ROWS][MAX_COLS], int n)
{
	if (n > MAX_ROWS || n > MAX_COLS || n < 0)
	{
		std::cout << "INVALID DATA" << std::endl;
		return false;
	}
	int target = sumRows(arr, 0, n);

	for (size_t i = 0; i < n; i++)
	{
		if (sumRows(arr, i, n) != target) return false;
		if (sumCols(arr, i, n) != target) return false;
	}

	if (sumMainDiag(arr, n) != target) return false;
	if (sumSecondaryDiag(arr, n) != target) return false;

	return true;

}


int main()
{
	int n;
	std::cin >> n;
	int arr[MAX_ROWS][MAX_COLS];
	readMatrix(arr, n, n);
	if (isMagicSquare(arr, n))
	{
		std::cout << " ITS MAGIC !!!!!!! <3";
	}
	else
	{
		std::cout << " its over for me ";
	}
}
