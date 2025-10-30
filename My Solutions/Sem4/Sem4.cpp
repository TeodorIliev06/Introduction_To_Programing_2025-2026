#include <iostream>

using namespace std;

int getPrimeNumber(int num, char _operator) {
	switch (_operator)
	{
	case '-':
		return num * 6 - 1;
	case '+':
		return num * 6 + 1;
	default:
		return -1;
	}
}

int getReversed(int num) {
	int reversedNum = 0;

	while (num != 0) {
		reversedNum *= 10;

		reversedNum += num % 10;
		num /= 10;
	}

	return reversedNum;
}

bool isPalindrome(int num) {
	int reversedNum = getReversed(num);

	return num == reversedNum;
}

bool isSuffix(int firstNum, int secondNum) {
	while (firstNum != 0 && secondNum != 0)
	{
		int firstNumCurrentDigit = firstNum % 10;
		int secondNumCurrentDigit = secondNum % 10;

		if (firstNumCurrentDigit != secondNumCurrentDigit)
		{
			return 0;
		}

		firstNum /= 10;
		secondNum /= 10;
	}

	return 1;
}

bool isPrefix(int firstNum, int secondNum) {

	// TODO: find digit count before extractng first digit
	int firstCount = 0, secondCount = 0,
		temp1 = firstNum, temp2 = secondNum;

	while (temp1 > 0)
	{
		temp1 /= 10;
		firstCount++;
	}

	while (temp2 > 0)
	{
		temp2 /= 10;
		secondCount++;
	}

	int divisor = 1;
	for (int i = 0; i < firstCount - secondCount; i++)
	{
		divisor *= 10;
	}

	int prefix = firstNum / divisor;

	return secondNum == prefix;
}

bool isInfix(int firstNum, int secondNum) {

	// TODO: find digit count before extractng first digit
	int firstCount = 0, secondCount = 0,
		temp1 = firstNum, temp2 = secondNum;

	while (temp1 > 0)
	{
		temp1 /= 10;
		firstCount++;
	}

	while (temp2 > 0)
	{
		temp2 /= 10;
		secondCount++;
	}

	for (int startPosition = 0; startPosition <= firstCount - secondCount; startPosition++)
	{
		// Extract the needed portion from given start index
		int divisor = 1;
		for (int i = 0; i < startPosition; i++)
		{
			divisor *= 10;
		}

		// Get only the digits needed (length of second num)
		int modulus = 1;
		for (int i = 0; i < secondCount; i++)
		{
			modulus *= 10;
		}

		int extracted = firstNum / divisor % modulus;

		if (extracted == secondNum)
		{
			return true;
		}
	}

	return false;
}

//TODO: fix smaller number incorrect display
int getCustomLog(int base, int argument) {
	int logarithm = 0;

	if (base == argument)
	{
		return 0;
	}

	if (argument == 0)
	{
		return 1;
	}

	while (base >= argument)
	{
		base /= argument;
		logarithm++;
	}

	return logarithm;
}

long long getCustomPow(int num, int pow) {
	long long output = 1;

	for (int i = 0; i < pow; i++)
	{
		output *= num;
	}

	return output;
}

bool areRadiusesEqual(int a, int b, int c, int d) {
	int firstRadius = a * a + b * b;
	int secondRadius = c * c + d * d;

	return firstRadius == secondRadius;
}

int main()
{
#pragma region Examples
	// 1
	//unsigned int number;
	//cin >> number;

	//// Without functions
	///*for (int i = 1; i <= number; i++)
	//{
	//	cout << 6 * i - 1 << " " << 6 * i + 1 << endl;
	//}*/

	//for (int i = 1; i <= number; i++)
	//{
	//	cout << getPrimeNumber(i, '-') << " "
	//		 << getPrimeNumber(i, '+') << endl;
	//}

	// 2
	/*unsigned int num;
	cin >> num;

	int reversedNum = getReversed(num);
	cout << reversedNum;*/

	// 3
	//unsigned int num;
	//cin >> num;

	//cout << boolalpha << isPalindrome(num) << endl;

	// 4
	//unsigned int firstNum, secondNum;
	//cin >> firstNum >> secondNum;

	//cout << boolalpha << isSuffix(firstNum, secondNum) << endl;

	// 5
	//unsigned int firstNum, secondNum;
	//cin >> firstNum >> secondNum;

	//cout << boolalpha << isPrefix(firstNum, secondNum) << endl;

	// 6
	/*unsigned int firstNum, secondNum;
	cin >> firstNum >> secondNum;

	cout << boolalpha << isInfix(firstNum, secondNum) << endl;*/

	// 7
	/*unsigned int num, power;
	cin >> num >> power;

	cout << getCustomPow(num, power) << endl;*/

	// 8
	//unsigned int base, argument;
	//cin >> base >> argument;
	//
	//cout << getCustomLog(base, argument) << endl;

	// 9
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	cout << boolalpha << areRadiusesEqual(a, b, c, d) << endl;
#pragma endregion

}
