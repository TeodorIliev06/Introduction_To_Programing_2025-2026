#include <iostream>

using namespace std;

const int ARRAY_SIZE = 3;
const int MAX_SIEVE_SIZE = 1000;

void readArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

void fillSieve(bool* primeArr, int range) {
	for (int i = 0; i <= range; i++)
	{
		primeArr[i] = true;
	}

	// Not prime by definition
	primeArr[0] = false;
	primeArr[1] = false;
}

void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int linearSearch(int* arr, int key, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			return i;
		}
	}

	return -1;
}

void swap(int& firstNum, int& secondNum) {
	int temp = firstNum;
	firstNum = secondNum;
	secondNum = temp;
}

void reverseArr(int* arr, int size) {
	for (int i = 0; i < size / 2; i++)
	{
		swap(arr[i], arr[size - 1 - i]);
	}
}

int binarySearch(int* arr, int size, int key) {
	int left = 0;
	int right = size - 1;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (arr[mid] == key)
		{
			return mid;
		}
		else if (key > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return -1;
}

void bubbleSort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		bool isSwapped = false;

		for (int j = 0; j < size - i - 1; j++)
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

/// <summary>
/// This method finds all primes via Sieve of Eratostenes
/// </summary>
/// <param name="arr">The input array</param>
/// <param name="size">Array size</param>
/// <param name="upperBound">Position of last element in array</param>
void findAllPrimes(bool* primeArr, int upperBound) {
	// Iterate from 2 to sqrt(upperBound)
	for (int i = 2; i * i <= upperBound; i++)
	{
		if (primeArr[i])
		{
			// Mark all prime multiples as non-prime
			for (int j = i * i; j <= upperBound; j += i)
			{
				primeArr[j] = false;
			}
		}
	}

	// Print all primes
	for (int i = 2; i <= upperBound; i++)
	{
		if (primeArr[i])
		{
			cout << i << " ";
		}
	}
}

int main()
{
	// Printing an array
	//int arr[ARRAY_SIZE];

	//readArr(arr, ARRAY_SIZE);
	//printArr(arr, ARRAY_SIZE);

	// Linear search
	//int arr[ARRAY_SIZE];
	//int key;
	//cin >> key;

	//readArr(arr, ARRAY_SIZE);
	//cout << "The position is: " << linearSearch(arr, key, ARRAY_SIZE) << endl;

	// Array reversal
	//int arr[ARRAY_SIZE];

	//readArr(arr, ARRAY_SIZE);
	//reverseArr(arr, ARRAY_SIZE);
	//printArr(arr, ARRAY_SIZE);

	// Binary search
	//int arr[ARRAY_SIZE];
	//int key;
	//cin >> key;

	//readArr(arr, ARRAY_SIZE);
	//cout << binarySearch(arr, ARRAY_SIZE, key);

	// Bubble sort
	//int arr[ARRAY_SIZE];
	//readArr(arr, ARRAY_SIZE);
	//bubbleSort(arr, ARRAY_SIZE);
	//printArr(arr, ARRAY_SIZE);

	// Sieve of Erathostenes
	/*int upperBound;
	cin >> upperBound;

	bool primeArr[MAX_SIEVE_SIZE];
	fillSieve(primeArr, upperBound);
	findAllPrimes(primeArr, upperBound);*/
}
