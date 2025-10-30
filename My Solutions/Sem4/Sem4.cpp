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

int getAbsoluteValue(int num) {
	return num < 0 ? -num : num;
}

int getDigitCount(int num) {
	int ctr = 0;

	while (num > 0)
	{
		num /= 10;
		ctr++;
	}

	return ctr;
}

double getSideLength(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int getConcatenatedNum(int firstNum, int secondNum) {
	return firstNum * pow(10, getDigitCount(firstNum)) + secondNum;
}

int getReverseConcatenatedNum(int num) {
	int reversed = 0, temp = num;

	while (temp != 0)
	{
		reversed *= 10;

		reversed += temp % 10;
		temp /= 10;
	}

	return getConcatenatedNum(reversed, num);
}

int getPrimeDivisorsCount(int num)
{
	int count = 0;
	int temp = num;

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (temp % i != 0)
		{
			continue;
		}

		count++;

		// Remove duplicating prime divisors
		while (temp % i == 0)
		{
			temp /= i;
		}
	}

	// Check if there is a larger prime factor > sqrt(num)
	if (temp > 1)
	{
		count++;
	}

	return count;
}

bool isSorted(unsigned int num) {
	int temp;
	int digitsCount = getDigitCount(num);

	//Base case - less than 3 digits
	if (digitsCount < 3)
	{
		return true;
	}

	// Check if it is ascending
	bool isAscending = true;
	temp = num;
	while (temp > 0)
	{
		int lastDigit = temp % 10;
		int secondToLastDigit = temp / 10 % 10;

		if (lastDigit < secondToLastDigit)
		{
			isAscending = false;
			break;
		}

		temp /= 10;
	}

	if (isAscending)
	{
		return true;
	}

	bool isDescending = true;
	temp = num;
	while (temp > 0)
	{
		//No need for further check if it has 1 digit
		if (temp < 10)
		{
			break;
		}

		int lastDigit = temp % 10;
		int secondToLastDigit = temp / 10 % 10;

		if (lastDigit > secondToLastDigit)
		{
			isDescending = false;
			break;
		}

		temp /= 10;
	}

	if (!isAscending && !isDescending)
	{
		return false;
	}

	return true;
}

bool isWithEqualDigits(unsigned int num) {
	bool areEqual = true;

	while (num > 0)
	{
		//No need for further check if it has 1 digit
		if (num < 10)
		{
			break;
		}

		int lastDigit = num % 10;
		int secondToLastDigit = num / 10 % 10;

		if (lastDigit != secondToLastDigit)
		{
			areEqual = false;
			break;
		}

		num /= 10;
	}

	return areEqual;
}

int getNumWithSortedDigits(unsigned int num) {
	int output = 0;

	while (num > 0)
	{
		int digitToInsert = num % 10;
		num /= 10;

		int temp = output;
		int position = 0;

		// Traverse backwards to find insertion position
		while (temp > 0)
		{
			int currentDigit = temp % 10;

			if (digitToInsert >= currentDigit)
			{
				break;
			}

			position++;
			temp /= 10;
		}

		// Split in 2 parts
		// Insert: left part + digit + right part

		int divisor = getCustomPow(10, position);
		int leftPart = output / divisor;
		int rightPart = output % divisor;

		output = leftPart * getCustomPow(10, position + 1) + digitToInsert * divisor + rightPart;
	}

	return output;
}

bool isUpperLetter(char symbol) {
	return (symbol >= 'A' && symbol <= 'Z');
}

// Get the capital letter by subtracting the const
char toUpperCustom(char symbol) {
	const int TO_LOWER_TO_UPPER = 32;

	if (symbol < 'a' || symbol > 'z')
	{
		return symbol;
	}

	return (symbol - TO_LOWER_TO_UPPER);
}

int toDigit(char symbol) {
	const int TO_DIGIT = 48;

	if (symbol < '0' || symbol > '9')
	{
		return -1;
	}

	return symbol - TO_DIGIT;
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
	//int a, b, c, d;
	//cin >> a >> b >> c >> d;

	//cout << boolalpha << areRadiusesEqual(a, b, c, d) << endl;
#pragma endregion

#pragma region Exercises
	// 1
	//int num;
	//cin >> num;

	//cout << getAbsoluteValue(num) << endl;

	// 2
	//int num;
	//cin >> num;

	//cout << getDigitCount(num) << endl;

	// 3
	//int x1, y1, x2, y2, x3, y3;
	//cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	//double sideA = getSideLength(x1, y1, x2, y2);
	//double sideB = getSideLength(x2, y2, x3, y3);
	//double sideC = getSideLength(x3, y3, x1, y1);

	//cout << sideA + sideB + sideC << endl;

	// 4
	//int firstNum, secondNum;
	//cin >> firstNum >> secondNum;

	//cout << getConcatenatedNum(firstNum, secondNum) << endl;

	// 5
	//int num;
	//cin >> num;

	//cout << getReverseConcatenatedNum(num) << endl;

	// 6
	//int lowerBound, upperBound, primeDivisorsCount, output = 0;
	//cin >> lowerBound >> upperBound >> primeDivisorsCount;

	//for (int i = lowerBound; i <= upperBound; i++)
	//{
	//	int currentPrimeDivisorsCount = getPrimeDivisorsCount(i);

	//	if (currentPrimeDivisorsCount == primeDivisorsCount)
	//	{
	//		output++;
	//	}
	//}

	//cout << output << endl;

	// 7
	//unsigned int num;
	//cin >> num;

	//cout << boolalpha << isSorted(num) << endl;

	// 8
	//unsigned int num;
	//cin >> num;

	//cout << boolalpha << isWithEqualDigits(num) << endl;

	// 9
	//unsigned int num;
	//cin >> num;

	//cout << getNumWithSortedDigits(num) << endl;

	// 10
	//char symbol;
	//cin >> symbol;

	//cout << boolalpha << isUpperLetter(symbol) << endl;

	// 11
	//char symbol;
	//cin >> symbol;

	//cout << toUpperCustom(symbol) << endl;

	// 12
	//char symbol;
	//cin >> symbol;

	//cout << toDigit(symbol) << endl;

	
#pragma endregion
}
