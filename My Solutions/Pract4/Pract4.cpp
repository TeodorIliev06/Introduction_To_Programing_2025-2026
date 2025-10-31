#include <iostream>

using namespace std;

const int TO_UPPER_TO_LOWER = 32;

int sum(int a, int b) {
	return a + b;
}

bool isEven(int num) {
	return num % 2 == 0;
}

bool isPositive(int num) {
	return num > 0;
}

bool isNegative(int num) {
	return num < 0;
}

int customAbs(int num) {
	return num < 0 ? -num : num;
}

double customFAbs(double num) {
	return num < 0 ? -num : num;
}

void print(char ch, int count) {
	for (int i = 0; i < count; i++)
	{
		cout << ch;
	}
}

bool isLetter(char symbol) {
	if ((symbol >= 'a' && symbol <= 'z') ||
		(symbol >= 'A' && symbol <= 'Z'))
	{
		return true;
	}

	return false;
}

bool isCapitalLetter(char ch) {
	if (!isLetter(ch))
	{
		return false;
	}

	return (ch >= 'A' && ch <= 'Z');
}

char toUpper(char ch) {
	if (!isLetter(ch))
	{
		return '-1';
	}

	return ch - TO_UPPER_TO_LOWER;
}

char toLower(char ch) {
	if (!isLetter(ch))
	{
		return '-1';
	}

	return ch + TO_UPPER_TO_LOWER;
}

int getNumLength(int num) {
	int result = 0;

	while (num > 0)
	{
		result++;
		num /= 10;
	}

	return result;
}

int getTargetDigit(int num, int targetDigitPosition) {
	int targetDigit = 0;

	if (targetDigitPosition <= 0)
	{
		return -1;
	}

	for (int i = 1; i <= targetDigitPosition; i++)
	{
		int currentPos = getNumLength(num);
		int divisor = pow(10, currentPos - 1);

		targetDigit = num % divisor;
		num %= divisor;
	}

	return targetDigit;
}

bool isPerfectRoot(int num) {
	double root = sqrt(num);

	int temp = floor(root);

	if (temp * temp == num)
	{
		return true;
	}
	else
	{
		temp = ceil(root);
		return temp * temp == num;
	}
}

int getLCD(int firstNum, int secondNum, int thirdNum) {
	int lcd = 1;

	int upperBound = min(min(firstNum, secondNum), thirdNum);

	for (int i = 2; i < upperBound; i++)
	{
		if (firstNum % i == 0 &&
			secondNum % i == 0 &&
			thirdNum % i == 0)
		{
			lcd = i;
		}
	}

	return lcd;
}

int getGCD(int a, int b, int c, int d) {

}

int getConcatenatedNum(int firstNum, int secondNum) {
	return firstNum * pow(10, getNumLength(firstNum)) + secondNum;
}

bool isInInterval(int num, int lowerBound, int upperBound) {
	for (int i = lowerBound; i <= upperBound; i++)
	{
		if (num == i)
		{
			return true;
		}
	}

	return false;
}

void askUser(int from, int to) {
	int num;

	cout << "Enter a num in the range [" << from << ";" << to << "]" << endl;
	cin >> num;

	while (!isInInterval(num, from, to))
	{
		cin >> num;
		cout << "Enter a num in the range [" << from << ";" << to << "]" << endl;
	}

	cout << "Correct!";
}

int getCustomPow(int num, int power) {
	int temp = 1;

	for (int i = 0; i < power; i++)
	{
		temp *= num;
	}

	return temp;
}

void calculate(int firstNum, int secondNum, char _operator) {
	switch (_operator)
	{
	case '+':
		cout << firstNum + secondNum;
		break;
	case '-':
		cout << firstNum - secondNum;
		break;
	case '*':
		cout << firstNum * secondNum;
		break;
	case '/':
		if (secondNum == 0)
		{
			cout << "Division by zero is not supported" << endl;
			return;
		}

		cout << firstNum / secondNum << endl;

		break;
	case '%':
		cout << firstNum % secondNum << endl;
		break;
	default:
		cout << firstNum + secondNum << endl;
		break;
	}
}

bool isPrime(int num) {
	for (int i = 2; i < sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

void getFactorization(int num) {
	int temp = num;

	for (int i = 2; i < sqrt(num); i++)
	{
		if (isPrime(i) && temp % i == 0)
		{
			while (temp % i == 0)
			{
				if (temp == i)
				{
					cout << i;
					break;
				}

				temp /= i;
				cout << i << '.';
			}
		}
	}
}

int getClosestPowerOf2(int num) {
	int powerOf2 = 0, nextNumber = 1;

	// Get the number that is a power of 2 bigger than input
	while (nextNumber <= num)
	{
		nextNumber *= 2;
		powerOf2++;
	}

	int prevoiusNumber = nextNumber / 2;
	if (nextNumber - num < num - prevoiusNumber)
	{
		return powerOf2;
	}
	else
	{
		return powerOf2 - 1;
	}
}

int main()
{
	// 1
	//int firstNum, secondNum;
	//cin >> firstNum >> secondNum;

	//cout << sum(firstNum, secondNum) << endl;

	// 2
	//int num;
	//cin >> num;

	//cout << boolalpha << isEven(num) << endl;

	// 3
	//int num;
	//cin >> num;

	//cout << boolalpha << isPositive(num) << endl;
	//cout << boolalpha << isNegative(num) << endl;

	// 4
	//int firstNum;
	//double secondNum;
	//cin >> num;

	//cout << getCustomAbs(firstNum) << endl;
	//cout << getCustomFabs(secondNum) << endl;

	// 5
	//char ch;
	//int count;

	//cin >> ch >> count;

	//print(ch, count);

	// 6
	//char ch;
	//cin >> ch;

	//cout << boolalpha << isCapitalLetter(ch) << endl;

	// 7
	/*char ch;
	cin >> ch;

	cout << toUpper(ch) << endl;
	cout << toLower(ch) << endl;*/

	// 8
	//int num;
	//cin >> num;

	//cout << getNumLength(num) << endl;

	// 9
	//int num, targetDigitPos;
	//cin >> num >> targetDigitPos;

	//cout << getTargetDigit(num, targetDigitPos) << endl;

	// 10
	//int num;
	//cin >> num;

	//cout << (isPerfectRoot(num) ? "yes" : "no") << endl;

	// 11
	//int firstNum, secondNum, thirdNum;
	//cin >> firstNum >> secondNum >> thirdNum;

	//cout << getLCD(firstNum, secondNum, thirdNum) << endl;

	// 12
	//int firstNum, secondNum;
	//cin >> firstNum >> secondNum;

	//cout << getConcatenatedNum(firstNum, secondNum) << endl;

	// 13
	/*int num, lowerBound, upperBound;
	cin >> lowerBound >> upperBound;

	askUser(lowerBound, upperBound);*/

	// 14
	//int num, power;
	//cin >> num >> power;

	//cout << getCustomPow(num, power);

	// 15
	//int firstNum, secondNum;
	//char _operator;
	//cin >> firstNum >> secondNum >> _operator;

	//calculate(firstNum, secondNum, _operator);
}
