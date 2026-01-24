#include <iostream>

char* revAndReplace(char* src) {
	int len = strlen(src);

	for (size_t i = 0; i < len / 2; i++)
	{
		std::swap(src[i], src[len - i - 1]);
	}

	for (size_t i = 0; i < len; i++)
	{
		if (src[i] == 'e')
		{
			src[i] = '!';
		}
		if (src[i] == 'y')
		{
			src[i] == '*';
		}
	}

	return src;
}

bool checkDate(char* yearStr) {
	int len = strlen(yearStr);
	if (len != 7)
	{
		return false;
	}

	int year = atoi(yearStr);
	if (yearStr[4] == ' ' &&
		yearStr[5] == 'g' &&
		yearStr[6] == '.')
	{
		if ((year % 4 == 0 && year%100 != 0) || (year % 400 == 0))
		{
			return true;
		}
	}

	return false;
}

void readArr(int* arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

int* countLetters(int* first, int* second, int size) {
	int lowerCtr = 0;
	int upperCtr = 0;

	int* letters = new int[2];
	for (size_t i = 0; i < size; i++)
	{
		int currentSum = first[i] + second[i];
		if (currentSum >= 65 && currentSum <= 90)
		{
			lowerCtr++;
		}
		else if (currentSum >= 97 && currentSum <= 122)
		{
			upperCtr++;
		}
	}

	letters[0] = lowerCtr;
	letters[1] = upperCtr;

	return letters;
}

int main()
{
	// 1
	//int n;
	//std::cout << "Please enter a valid length: ";
	//std::cin >> n;
	//std::cin.ignore();

	//char* src = new char[n+1];
	//std::cin.getline(src, n + 1, '\n');
	//revAndReplace(src);
	//std::cout << src;

	// 2
	/*int n;
	std::cout << "Please enter a valid length: ";
	std::cin >> n;
	std::cin.ignore();

	char* src = new char[n+1];
	std::cin.getline(src, n + 1, '\n');
	std::cout << std::boolalpha << checkDate(src);
	delete[] src;*/

	// 3
	int size;
	std::cout << "Please enter a valid size: ";
	std::cin >> size;
	std::cin.ignore();

	int* first = new int[size];
	readArr(first, size);

	int* second = new int[size];
	readArr(second, size);

	int* letters = countLetters(first, second, size);
	std::cout << letters[0] << ' ' << letters[1];
}
