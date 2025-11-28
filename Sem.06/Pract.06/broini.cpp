#include <iostream>

int charToNum(char c) {
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return 10 + c - 'A';
	}
	else if (c >= 'a' && c <= 'z')
	{
		return 10 + c - 'a';
	}

	return -1;
}

char numToChar(int num) {
	if (num >= 0 && num <= 9)
	{
		return num + '0';
	}
	else if (num >= 10 && num <= 35)
	{
		return 'a' + num - 10;
	}

	return '?';
}

int toDecimal(const char* input, size_t size, int base) {
	if (base < 2 || base > 36)
	{
		return -1;
	}

	int res = 0;
	for (size_t i = 0; i < size; i++)
	{
		int digit = charToNum(input[i]);
		res = res * base + digit;

		if (digit == -1 || digit >= base)
		{
			return -1;
		}
	}

	return res;
}

void fromDecimal(int num, int base, char* res, size_t& size) {
	if (base < 2 || base > 36)
	{
		return;
	}

	size_t write = 0;
	while (num)
	{
		char currChar = numToChar(num % base);
		if (currChar == '?')
		{
			return;
		}

		res[write++] = currChar;
		num /= base;
	}

	size = write;

	for (size_t i = 0; i < write / 2; i++)
	{
		std::swap(res[i], res[write - i - 1]);
	}
}


const size_t MAX_SIZE = 1024;

int main()
{
	char input[MAX_SIZE];
	size_t size;
	std::cin >> size;

	for (size_t i = 0; i < size; i++)
	{
		std::cin >> input[i];
	}

	int decimal = toDecimal(input, size, 2);

	char result[MAX_SIZE] = {};
	size_t resSize = 0;
	fromDecimal(decimal, 11, result, resSize);

	for (size_t i = 0; i < resSize; i++)
	{
		std::cout << result[i];
	}

}
