#include <iostream>

const int DIGITS_SIZE = 10;

void readArr(long* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void readArr(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

bool isContained(int target, int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		if (target == arr[i])
		{
			return true;
		}
	}

	return false;
}

int analyzeArray(const char* src) {
	int digits[DIGITS_SIZE] = {-1};

	int pos = 0;
	int len = strlen(src);

	for (size_t i = 0; i < len; i++)
	{
		int currValue = src[i] - '0';
		if (!isContained(currValue, digits, DIGITS_SIZE)) 
		{
			digits[pos++] = currValue;
		}
	}

	if (pos < 9) 
	{
		return digits[pos-1];
	}

	return -1;
}

char* findDiff(const long* arr, int size) {
	int minDiff = INT_MAX;
	int firstIdx = 0, secondIdx = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i+1; j < size; j++)
		{
			if (i == j)
			{
				continue;
			}

			int currDiff = std::abs(arr[i] - arr[j]);
			if (currDiff < minDiff)
			{
				minDiff = currDiff;
				firstIdx = i;
				secondIdx = j;
			}
		}
	}

	char* outArr = new char[64];
	int pos = 0;
	int temp = arr[firstIdx];
	while (temp > 0)
	{
		outArr[pos] = (temp % 10) + '0';
		temp /= 10;
		pos++;
	}

	outArr[pos++] = ',';

	temp = arr[secondIdx];
	while (temp > 0)
	{
		outArr[pos] = (temp % 10) + '0';
		temp /= 10;
		pos++;
	}

	outArr[pos] = '\0';

	return outArr;
}

int findIndex(const int* src, int size) {
	// Start backwards, the largest element is the first found
	// when checking for other elements
	for (int i = size - 1; i >= 0; i--)
	{
		int count = 0;
		for (size_t j = 0; j < i; j++)
		{
			if (src[j] >= i)
			{
				count++;
			}
		}

		if (count >= i)
		{
			return i;
		}
	}

	return 0;
}

int main()
{
	// 1
	/*int size;
	std::cout << "Please enter a valid size: ";
	std::cin >> size;
	std::cin.ignore();

	char* src = new char[size + 1];
	std::cin.getline(src, size + 1, '\n');

	int biggestDigit = analyzeArray(src);
	std::cout << biggestDigit;*/

	// 2
	/*int size;
	std::cout << "Please enter a valid size: ";
	std::cin >> size;

	int* src = new int[size];
	readArr(src, size);
	std::cout << findIndex(src, size);*/

	// 3
	int size;
	std::cout << "Please enter a valid size: ";
	std::cin >> size;

	long* src = new long[size];
	readArr(src, size);

	char* diff = findDiff(src, size);
	std::cout << diff;
}
