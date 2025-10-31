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
	int minAB = min(a, b);
	int minABC = min(minAB, c);
	int minABCD = min(minABC, c);

	while (minABCD > 0)
	{
		if (a % minABCD == 0 &&
			b % minABCD == 0 &&
			c % minABCD == 0 &&
			d % minABCD == 0)
		{
			break;
		}
		minABCD--;
	}

	return minABCD;
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

int getSumOfDigits(long long num) {
	int sum = 0;

	while (getNumLength((int)num) > 1)
	{
		int sum = 0;
		long long temp = num;

		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}

		num = sum;
	}

	return sum;
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

void getPrimeNumbersInRange(int range) {
	for (int i = 1; i <= range; i++)
	{
		if (isPrime(i))
		{
			cout << i << " ";
		}
	}

	cout << endl;
}

bool isEqualToSumOfPrimeNumbers(int num) {
	for (int i = 0; i < sqrt(num); i++)
	{
		for (int j = i; j < sqrt(num); j++)
		{
			if (!isPrime(i) || !isPrime(j))
			{
				continue;
			}

			if (i + j == num)
			{
				return true;
			}
		}
	}

	return false;
}

int sortDigits(int num) {
	if (num == 0) return 0;

	int result = 0;

	while (num > 0) {
		int digitToInsert = num % 10;
		num /= 10;

		// Find the correct position to insert the digit
		int temp = result;
		int position = 0;

		// Traverse result from right to left to find insertion position
		while (temp > 0) {
			int currentDigit = temp % 10;
			if (digitToInsert >= currentDigit) {
				break;
			}
			position++;
			temp /= 10;
		}

		// Split result into left and right parts
		int divisor = pow(10, position);
		int rightPart = result % divisor;
		int leftPart = result / divisor;

		// Insert: leftPart + digit + rightPart
		result = leftPart * pow(10, position + 1) + digitToInsert * divisor + rightPart;
	}

	return result;
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

	// 16


	// 17
	//const int LOWER_BOUND = 100;
	//const int UPPER_BOUND = 100000;
	//int num;
	//cin >> num;

	//while (!isInInterval(num, LOWER_BOUND, UPPER_BOUND))
	//{
	//	cout << "Please enter a valid num";
	//	cin >> num;
	//}

	//cout << getClosestPowerOf2(num);

	// 18
	//int a, b, c, d;
	//cin >> a >> b >> c >> d;

	//cout << getGCD(a, b, c, d);

	// 19
	//long long num;
	//cin >> num;

	//cout << getSumOfDigits(long long num) << endl;

	// 20
	//int num, range;
	//cin >> num >> range;

	//cout << boolalpha << isPrime(num);

	//getPrimeNumbersInRange(range);

	//cout << (isEqualToSumOfPrimeNumbers(num) ? "yes" : "no") << endl;

	// 21
	//int num;
	//cin >> num;

	//getFactorization(num);

	// 22
	/*long long num;
	cin >> num;

	cout << getSumOfDigits(num) << endl;*/

	// 23
	
}
