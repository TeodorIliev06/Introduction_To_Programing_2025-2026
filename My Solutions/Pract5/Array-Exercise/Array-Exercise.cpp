#include <iostream>

const int ARRAY_SIZE = 1000;

void readArr(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void printArr(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

double getAbsValue(double num) {
	return (num > 0) ? num : -num;
}

/// <summary>
/// Compute arithmetic mean (AM) and the closest element to it
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
void getMidValue(int* arr, size_t size) {
	double AM = 0;

	for (size_t i = 0; i < size; i++)
	{
		AM += arr[i];
	}

	AM /= size;

	int minDiff = arr[0], closestIdx = 0;
	for (size_t i = 0; i < size; i++)
	{
		double currentAbs = getAbsValue(arr[i] - AM);
		if (currentAbs < minDiff)
		{
			minDiff = currentAbs;
			closestIdx = i;
		}
	}

	std::cout << AM << std::endl;
	std::cout << arr[closestIdx] << std::endl;
}

int getMin(int* arr, size_t size) {
	int min = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

int getMax(int* arr, size_t size) {
	int max = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

void removeAt(int* arr, size_t& size, int idxToRemove) {
	//TODO: check for index out of bound or nullptr

	for (size_t i = idxToRemove; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	size--;
}

void fillRange(int* arr, size_t size, int* result, size_t& resultSize, int start, int end) {
	resultSize = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] >= start && arr[i] <= end)
		{
			result[i] = arr[i];
			resultSize++;
		}
	}
}

bool isSymetric(const int* arr, size_t size) {
	for (size_t i = 0; i < size / 2; i++)
	{
		if (arr[i] != arr[size - 1 - i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	// 1
	//int arr[ARRAY_SIZE];

	//size_t size;
	//std::cin >> size;

	//readArr(arr, size);
	//getMidValue(arr, size);

	// 2
	//int arr[ARRAY_SIZE];

	//size_t size;
	//std::cin >> size;

	//readArr(arr, size);

	//std::cout << "Min: " << getMin(arr, size) << std::endl;
	//std::cout << "Max: " << getMax(arr, size) << std::endl;

	// 3
	//int arr[ARRAY_SIZE];

	//size_t size;
	//int idxToRemove;
	//std::cin >> size;

	//readArr(arr, size);

	//std::cout << "Enter index to remove at: " << std::endl;
	//std::cin >> idxToRemove;

	//removeAt(arr, size, idxToRemove);
	//printArr(arr, size);

	// 4
	/*int arr[ARRAY_SIZE];
	int result[ARRAY_SIZE];

	size_t size, resultSize;
	std::cin >> size;

	readArr(arr, size);

	std::cout << "Enter start and end values: " << std::endl;

	int start, end;
	std::cin >> start >> end;

	fillRange(arr, size, result, resultSize, start, end);
	printArr(result, resultSize);*/

	// 5
	int arr[ARRAY_SIZE];

	size_t size;
	std::cin >> size;

	readArr(arr, size);

	std::cout << std::boolalpha <<
		(isSymetric(arr, size) ? "yes" : "no") << std::endl;
}
