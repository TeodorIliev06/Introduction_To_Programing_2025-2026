#include <iostream>

struct Point {
	int x;
	int y;
};

long processNum(long num) {
	int multiplier = 10;
	int currLen = 1, bestLen = 0;
	long currSeq = num % 10, bestSeq = 0;

	int prevDigit = num % 10;
	num /= 10;
	while (num > 0)
	{
		int digit = num % 10;

		if (digit > prevDigit)
		{
			currSeq = digit * multiplier + currSeq;
			multiplier *= 10;
			if (currSeq > bestSeq)
			{
				bestSeq = currSeq;
			}
		}
		else
		{
			if (currLen > bestLen || (currLen == bestLen && currSeq > bestSeq))
			{
				bestLen = currLen;
				bestSeq = currSeq;
			}

			currSeq = digit;
			currLen = 1;
			multiplier = 10;
		}

		prevDigit = digit;
		num /= 10;
	}

	if (currLen > bestLen || (currLen == bestLen && currSeq > bestSeq))
	{
		bestSeq = currSeq;
	}

	return bestSeq;
}

void readArr(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void printArr(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int* mergeArrays(int* first, int* second, int size) {
	int* result = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		result[i] = first[i] + second[size - 1 - i];
	}

	return result;
}

int checkQ(Point point) {
	if (point.x == 0 && point.y == 0)
	{
		return 0;
	}

	if (point.x > 0)
	{
		if (point.y > 0)
		{
			return 1;
		}
		else if (point.y < 0)
		{
			return 2;
		}
	}
	else if (point.x < 0)
	{
		if (point.y < 0)
		{
			return 3;
		}
		else if (point.y > 0)
		{
			return 4;
		}
	}
}

int main()
{
	// 1
	/*long num;
	std::cin >> num;
	std::cout << processNum(num);*/

	// 2
	/*int size;
	std::cout << "Please enter a valid size: ";
	std::cin >> size;

	int* first = new int[size];
	int* second = new int[size];
	readArr(first, size);
	readArr(second, size);

	int* merged = mergeArrays(first, second, size);
	printArr(merged, size);*/

	// 3
	Point point;
	std::cin >> point.x >> point.y;

	std::cout << checkQ(point);
}
