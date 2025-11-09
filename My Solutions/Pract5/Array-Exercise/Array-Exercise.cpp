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

void copyArr(const int* source, size_t size, int* destination) {
	for (size_t i = 0; i < size; i++)
	{
		destination[i] = source[i];
	}
}

double getAbsValue(double num) {
	return (num > 0) ? num : -num;
}

/// <summary>
/// Compute arithmetic mean (AM) and find the closest element to it
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

unsigned getLongestDecreasingSubsequence(const int* arr, size_t size) {
	if (size == 0)
	{
		return 0;
	}

	unsigned currentSeqLength = 1, bestSeqLength = 1;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			currentSeqLength++;

			if (bestSeqLength < currentSeqLength)
			{
				bestSeqLength = currentSeqLength;
			}
		}
		else
		{
			currentSeqLength = 1;
		}
	}

	return bestSeqLength;
}

unsigned getLongestSubsequenceOfEquals(const int* arr, size_t size) {
	if (size == 0)
	{
		return 0;
	}

	unsigned currentSeqLength = 1, bestSeqLength = 1;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			currentSeqLength++;

			if (bestSeqLength < currentSeqLength)
			{
				bestSeqLength = currentSeqLength;
			}
		}
		else
		{
			currentSeqLength = 1;
		}
	}

	return bestSeqLength;
}

void setAsNull(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++)
	{
		int currentNum = arr[i];
		bool isContained = false;

		while (currentNum > 0)
		{
			int currentDigit = currentNum % 10;

			if (currentDigit == i)
			{
				isContained = true;
				break;
			}

			currentNum /= 10;
		}

		if (!isContained)
		{
			arr[i] = 0;
		}
	}
}

void swap(int& firstNum, int& secondNum) {
	int temp = firstNum;
	firstNum = secondNum;
	secondNum = temp;
}

void bubbleSort(int* arr, size_t size) {
	for (size_t i = 0; i < size - 1; i++)
	{
		bool isSwapped = false;

		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				isSwapped = true;
			}
		}

		if (!isSwapped)
		{
			break;
		}
	}
}

int getFrequencyCount(const int* arr, size_t size, int key) {
	int count = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			count++;
		}
	}

	return count;
}

int getMostFrequentNumber(const int* arr, size_t size, int* copy) {
	if (size == 1)
	{
		return arr[0];
	}

	// Find the most frequent in the copy
	int maxFrequency = 1, currentFrequnecy = 1;

	for (size_t i = 1; i < size; i++)
	{
		if (copy[i] == copy[i - 1])
		{
			currentFrequnecy++;

			if (currentFrequnecy > maxFrequency)
			{
				maxFrequency = currentFrequnecy;
			}
		}
		else
		{
			currentFrequnecy = 1;
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		int count = getFrequencyCount(copy, size, arr[i]);

		if (count == maxFrequency)
		{
			return arr[i];
		}
	}

	return arr[0];
}

void customIntersect(const int* firstArr, size_t firstArrSize,
	const int* secondArr, size_t secondArrSize, int* result, size_t& intersectionSize) {
	size_t resultPos = 0;

	for (size_t i = 0; i < firstArrSize; i++)
	{
		bool isAddedToResult = false;
		for (size_t k = 0; k < resultPos; k++)
		{
			if (result[k] == firstArr[i])
			{
				isAddedToResult = true;
				break;
			}
		}

		if (isAddedToResult)
		{
			continue;
		}

		for (size_t j = 0; j < secondArrSize; j++)
		{
			if (firstArr[i] == secondArr[j])
			{
				result[resultPos++] = firstArr[i];
				break;
			}
		}
	}

	intersectionSize = resultPos;
}

void customUnion(const int* firstArr, size_t firstArrSize,
	const int* secondArr, size_t secondArrSize, int* result, size_t& unionSize) {
	size_t resultPos = 0;

	// fill the union with one array
	// then compare with the other

	copyArr(firstArr, firstArrSize, result);
	resultPos = firstArrSize;

	for (size_t i = 0; i < secondArrSize; i++)
	{
		bool isAddedToResult = false;
		for (size_t k = 0; k < resultPos; k++)
		{
			if (result[k] == secondArr[i])
			{
				isAddedToResult = true;
				break;
			}
		}

		if (isAddedToResult)
		{
			continue;
		}

		result[resultPos++] = secondArr[i];
	}

	unionSize = resultPos;
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
	//int arr[ARRAY_SIZE];

	//size_t size;
	//std::cin >> size;

	//readArr(arr, size);

	//std::cout << std::boolalpha <<
	//	(isSymetric(arr, size) ? "yes" : "no") << std::endl;

	// 6
	//int arr[ARRAY_SIZE];

	//size_t size;
	//std::cin >> size;

	//readArr(arr, size);

	//unsigned seqLength = getLongestDecreasingSubsequence(arr, size);
	//std::cout << seqLength << std::endl;

	// 7
	//int arr[ARRAY_SIZE];

	//size_t size;
	//std::cin >> size;

	//readArr(arr, size);

	//unsigned seqLength = getLongestSubsequenceOfEquals(arr, size);
	//std::cout << seqLength << std::endl;

	// 8
	//int arr[ARRAY_SIZE];

	//size_t size;
	//std::cin >> size;

	//readArr(arr, size);
	//setAsNull(arr, size);
	//printArr(arr, size);

	// 9
	//int arr[ARRAY_SIZE];
	//int copy[ARRAY_SIZE];

	//size_t size;
	//std::cin >> size;

	//readArr(arr, size);

	//copyArr(arr, size, copy);
	//bubbleSort(copy, size);

	//std::cout << getMostFrequentNumber(arr, size, copy) << std::endl;

	// 10
	/*int firstArr[ARRAY_SIZE], secondArr[ARRAY_SIZE];

	size_t firstArrSize, secondArrSize;

	std::cout << "Please enter first sequence size" << std::endl;
	std::cin >> firstArrSize;
	std::cout << "Please enter first sequence of numbers" << std::endl;
	readArr(firstArr, firstArrSize);

	std::cout << "Please enter second sequence size" << std::endl;
	std::cin >> secondArrSize;
	std::cout << "Please enter second sequence of numbers" << std::endl;
	readArr(secondArr, secondArrSize);

	int intersectionArr[ARRAY_SIZE];
	size_t intersecitonSize = 0;
	customIntersect(firstArr, firstArrSize, secondArr, secondArrSize, intersectionArr, intersecitonSize);

	std::cout << "Intersection: ";
	printArr(intersectionArr, intersecitonSize);
	std::cout << std::endl;

	int unionArr[2 * ARRAY_SIZE];
	size_t unionSize = 0;
	customUnion(firstArr, firstArrSize, secondArr, secondArrSize, unionArr, unionSize);

	std::cout << "Union: ";
	printArr(unionArr, unionSize);*/
}
