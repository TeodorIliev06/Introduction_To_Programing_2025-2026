#include <iostream>

const double EPSILON = 1e-10;
const int TO_UPPER_TO_LOWER = 32;

double sqrt_a(double a, double epsilon) {
	double res = a;

	while (true)
	{
		double next = (res + a / res) / 2;
		if (std::abs(next - res) < epsilon)
		{
			return next;
		}
	}
}

void revert(char* src) {
	while (*src != '\0')
	{
		if (*src >= 'a' && *src <= 'z')
		{
			*src -= TO_UPPER_TO_LOWER;
		}
		else if (*src >= 'A' && *src <= 'Z')
		{
			*src += TO_UPPER_TO_LOWER;
		}

		src++;
	}
}

bool checkDate(char* src) {
	int len = strlen(src);

	if (len != 5)
	{
		return false;
	}

	int i = 0;
	int days = 0, months = 0;
	while (i < 2)
	{
		days = days * 10 + (src[i] - '0');
		i++;
	}

	if (src[i] != '.')
	{
		return false;
	}
	i++;

	while (i < 5)
	{
		months = months * 10 + (src[i] - '0');
		i++;
	}

	if (days < 1 || days > 31 ||
		months < 1 || months > 12)
	{
		return false;
	}

	switch (months)
	{
	case 2:
		if (days > 28)
		{
			return false;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		if (days > 30)
		{
			return false;
		}
	default:
		break;
	}

	return true;
}

int digitPos(long num, int& pos) {
	if (num == 0)
	{
		return -1;
	}

	int result = digitPos(num / 10, pos);
	if (result != -1)
	{
		return result;
	}

	pos--;
	if (pos == 0)
	{
		return num % 10;
	}

	return -1;
}

bool doExist(char* input, char* target) {
	int len = strlen(input);
	int targetLen = strlen(target);

	if (targetLen > len)
	{
		return false;
	}

	for (size_t i = 0; i <= len - targetLen; i++)
	{
		bool flag = true;
		for (size_t j = 0; j < targetLen; j++)
		{
			if (input[i+j] != target[j])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	// 1
	//int num;
	//std::cin >> num;
	//std::cout << sqrt_a(num, EPSILON);

	// 2
	/*int size;
	std::cout << "Please enter a valid size: ";
	std::cin >> size;
	std::cin.ignore();

	char* src = new char[size + 1];
	std::cin.getline(src, size+1, '\n');

	revert(src);
	std::cout << src;*/

	// 3
	/*int size;
	std::cout << "Please enter a valid size: ";
	std::cin >> size;
	std::cin.ignore();

	char* src = new char[size + 1];
	std::cin.getline(src, size + 1, '\n');

	std::cout << std::boolalpha << checkDate(src);*/

	// 4
	/*long num;
	std::cin >> num;

	int k;
	std::cout << "Please enter an index: ";
	std::cin >> k;

	std::cout << digitPos(num, k);*/

	// 5
	int inputSize;
	std::cout << "Please enter a valid input size: ";
	std::cin >> inputSize;
	std::cin.ignore();

	char* src = new char[inputSize + 1];
	std::cin.getline(src, inputSize + 1, '\n');

	int targetSize;
	std::cout << "Please enter a valid target size: ";
	std::cin >> targetSize;
	std::cin.ignore();

	char* target = new char[targetSize + 1];
	std::cin.getline(target, targetSize + 1, '\n');

	std::cout << std::boolalpha << doExist(src, target);
}
