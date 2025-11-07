#include <iostream>

using namespace std;

const int MATRIX_ROW_SIZE = 3;
const int MATRIX_COL_SIZE = 4;

void readMatrix(int matrix[][MATRIX_COL_SIZE], int rowSize, int colSize) {
	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			cin >> matrix[row][col];
		}
	}
}

void printTransposed(int transposed[][MATRIX_ROW_SIZE], int rowSize, int colSize) {
	for (int col = 0; col < colSize; col++)
	{
		for (int row = 0; row < rowSize; row++)
		{
			cout << transposed[col][row] << ' ';
		}

		cout << endl;
	}
}

void transpose(int matrix[][MATRIX_COL_SIZE], int transposed[][MATRIX_ROW_SIZE],
	int rowSize, int colSize) {
	for (int row = 0; row < rowSize; row++)
	{
		for (int col = 0; col < colSize; col++)
		{
			transposed[col][row] = matrix[row][col];
		}
	}
}

int main()
{
	//Transposing
	int matrix[MATRIX_ROW_SIZE][MATRIX_COL_SIZE];
	readMatrix(matrix, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	int transposed[MATRIX_COL_SIZE][MATRIX_ROW_SIZE];
	transpose(matrix, transposed, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);

	printTransposed(transposed, MATRIX_ROW_SIZE, MATRIX_COL_SIZE);
}
