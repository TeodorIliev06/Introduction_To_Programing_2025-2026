#include <iostream>

int cmpDigits(int first, int second) {
	if (first > second)
	{
		return 1;
	}
	else if (second > first)
	{
		return -1;
	}

	return 0;
}

bool checkNum(long num) {
	bool isIncreasing = true;
	bool isDecreasing = true;

	int digits[10];
	long temp = num;
	int ctr = 0;

	while (temp > 0)
	{
		digits[ctr] = temp % 10;
		temp /= 10;
		ctr++;
	}

	if (ctr < 2)
	{
		return false;
	}

	for (size_t i = 0; i < ctr; i++)
	{
		for (size_t j = 0; j < ctr -1; j++)
		{
			if (j == i)
			{
				continue;
			}

			int result = cmpDigits(digits[j], digits[j + 1]);

			if (result != 1)
			{
				isDecreasing = false;
			}
			if (result != -1)
			{
				isIncreasing = false;
			}
		}
	}

	if (!isIncreasing && !isDecreasing)
	{
		return false;
	}
	else if (isIncreasing || isDecreasing)
	{
		return true;
	}
}

int findNumber(const char* src) {
	int len = strlen(src);

	if (len != 3)
	{
		return -1;
	}

	int first = src[0] - '0';
	int second = src[1] - '0';
	int third = src[2] - '0';

	if (cmpDigits(first, second) == 0)
	{
		return first * 100 + third * 10 + second;
	}
	else if (cmpDigits(first, third) == 0)
	{
		return first * 100 + second * 10 + third;
	}
	else if (cmpDigits(second, third) == 0)
	{
		return second * 100 + first * 10 + third;
	}

	return -1;
}

void printArr(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int readMatrix(int rows, int cols, int** matrix)
{
	int ctr = 0;
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
		for (size_t j = 0; j < cols; j++)
		{
			std::cin >> matrix[i][j];
			ctr++;
		}
	}

	return ctr;
}

int* spiralRead(int** matrix, int rows, int cols, int ctr, int& size) {
	int top = 0, bottom = rows - 1;
	int left = 0, right = cols - 1;

	int* outArr = new int[ctr];
	size = 0;
	while (top <= bottom &&
		   left <= right)
	{
		for (size_t i = left; i <= right; i++)
		{
			outArr[size] = matrix[bottom][i];
			size++;
		}
		bottom--;

		if (top < bottom)
		{
			for (int i = bottom; i >= top; i--)
			{
				outArr[size] = matrix[i][right];
				size++;
			}
			right--;
		}

		if (left < right)
		{
			for (int i = right; i >= left; i--)
			{
				outArr[size] = matrix[top][i];
				size++;
			}
			top++;
		}
		
		for (size_t i = top; i <= bottom; i++)
		{
			outArr[size] = matrix[i][left];
			size++;
		}
		left++;
	}

	return outArr;
}

int main()
{
	// 1
	/*long num;
	std::cin >> num;
	checkNum(num);

	std::cout << std::boolalpha << checkNum(num) << std::endl;*/

	// 2
	/*int n;
	std::cout << "Please enter valid length (should be 3): ";
	std::cin >> n;
	std::cin.ignore();

	char* src = new char[n + 1];
	std::cin.getline(src, n+1, '\n');
	std::cout << findNumber(src) << std::endl;

	delete[] src;*/

	// 3
	int rows, cols;
	std::cout << "Please enter rows and cols of the matrix: ";
	std::cin >> rows >> cols;

	int** matrix = new int* [rows];
	int ctr = readMatrix(rows, cols, matrix);
	
	int spiralSize = 0;
	int* spiralArr = spiralRead(matrix, rows, cols, ctr, spiralSize);
	printArr(spiralArr, spiralSize);
}
