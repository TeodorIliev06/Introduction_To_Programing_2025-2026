#include <iostream>

using namespace std;

int main()
{
	// 1
	/*int num, sum = 0;

	while (true) {
		cin >> num;

		if (num == 0)
		{
			cout << sum;
			return 0;
		}

		sum += num;
	}*/

	// 2
	/*unsigned num;
	cin >> num;

	int reversedNum = 0;

	while (num != 0) {
		reversedNum *= 10;

		reversedNum += num % 10;
		num /= 10;
	}

	reversedNum++;

	cout << reversedNum;*/

	// 3
	/*int num, mostCommonDigit = , ctr = 0;
	cin >> num;

	while (num != 0)
	{
		int currentDigit = num % 10;


	}*/

	// 4
	/*int firstNum, secondNum, highestCommonFactor = 1;
	cin >> firstNum >> secondNum;

	for (int i = 1; i <= firstNum || i <= secondNum; i++)
	{
		if (firstNum % i == 0 && secondNum % i == 0)
		{
			highestCommonFactor = i;
		}
	}

	cout << highestCommonFactor;*/

	// 5
	/*int firstNum, secondNum, lowestCommonMultiple = 1;
	cin >> firstNum >> secondNum;

	for (int i = 2; i <= min(firstNum, secondNum); i++)
	{
		if (firstNum % i == 0 && secondNum % i == 0)
		{
			lowestCommonMultiple = i;
			break;
		}
	}

	cout << lowestCommonMultiple;*/

	// 6
	/*int num;
	cin >> num;

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			cout << "Not prime";

			return 0;
		}
	}

	cout << "Prime";*/

	// 7
	int num, ctr = 0;
	bool isDivisorPrime;
	cin >> num;

	for (int divisor = num - 1; divisor >= 2; divisor--)
	{
		while (num % divisor == 0)
		{
			isDivisorPrime = true;

			for (int i = 2; i <= sqrt(divisor); i++)
			{
				if (divisor % i == 0)
				{
					isDivisorPrime = false;
					break;
				}
			}

			if (!isDivisorPrime)
			{
				break;
			}

			ctr++;
			num /= divisor;

			continue;
		}
		if (ctr != 0)
		{
			cout << divisor << " ^ " << ctr << " ";
			ctr = 0;
		}
	}
}
