#include <iostream>

using namespace std;

int main()
{
	// 1
	/*int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << j;
		}

		cout << endl;
	}*/


	// 2
	// TODO: find all solutions of x + y = n
	//int x, y, n;
	//cin >> n;

	//for (int i = 1; i < n; i++)
	//{
	//	int j = n - i;

	//	cout << "x = " << i << " y = " << j << endl;
	//}

	// 3
	//int num;
	//cin >> num;

	//int squaredNum = num * num;
	//int reverseSquared = 0;

	//while (squaredNum > 0)
	//{
	//	reverseSquared *= 10;

	//	reverseSquared += squaredNum % 10;
	//	squaredNum /= 10;
	//}

	//cout << reverseSquared;

	// 4
	//int num;
	//cin >> num;

	//int factorial = 1;

	//for (int i = 1; i <= num; i++)
	//{
	//	factorial *= i;
	//}

	//cout << "Factorial: " << factorial;

	// 5
	/*int m, n, ctr = 1;
	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ctr++ << " ";
		}
		cout << endl;
	}*/

	// 6
	/*const int LOWER_BOUND = 0;
	const int UPPER_BOUND = 100;

	int num;
	cin >> num;

	while (num < LOWER_BOUND || num > UPPER_BOUND)
	{
		cout << "Please enter a number in the range [0;100]" << endl;
		cin >> num;
	}

	int input, ctr = 0;
	cin >> input;

	while (input != num)
	{
		if (input < num)
		{
			cout << "The entered number is lower than " << num << endl;
		}
		else if (input > num)
		{
			cout << "The entered number is higher than " << num << endl;
		}

		ctr++;
		cin >> input;
	}

	cout << "Made suggestions: " << ctr;*/

	// 7
	/*int num, sum = 0;
	cin >> num;

	const int LOWER_BOUND = 1;
	const int UPPER_BOUND = num - 1;

	int targetSum = num * (num + 1) / 2;
	for (int i = 0; i < num - 1; i++)
	{
		int input;
		cin >> input;

		while (input < LOWER_BOUND || input > UPPER_BOUND)
		{
			cout << "Please enter a number in the range [1;" << num -1 << "]" << endl;
			cin >> input;
		}

		sum += input;
	}

	int missingNum = (targetSum - sum);
	cout << "The missing number is: " << missingNum;*/

	// 8
	/*int num;
	cin >> num;

	for (int i = 1; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			for (int k = 1; k < num; k++)
			{
				if (i * i + j * j == k * k)
				{
					cout << i << " " << j << " " << k << endl;
				}
			}
		}
	}*/

	// 9
	//const int LOWER_BOUND = 2;
	//const int UPPER_BOUND = 9;


	//int repetitionCount = 0;
	//char symbol;

	//cin >> repetitionCount >> symbol;

	//while (repetitionCount < LOWER_BOUND || repetitionCount > UPPER_BOUND)
	//{
	//	cout << "Please enter a number in the range [" << LOWER_BOUND << ";" << UPPER_BOUND << "]" << endl;
	//	cin >> repetitionCount;
	//}

	//// Print upper half
	//for (int i = 1; i < repetitionCount; i++)
	//{
	//	for (int j = 0; j < repetitionCount - i; j++)
	//	{
	//		cout << " ";
	//	}

	//	for (int k = 0; k < 2 * i - 1; k++)
	//	{
	//		cout << symbol;
	//	}

	//	cout << endl;
	//}

	//// Print middle
	//for (int i = 0; i < 2 * repetitionCount - 1; i++)
	//{
	//	cout << symbol;
	//}

	//cout << endl;

	//// Print lower half
	//for (int i = repetitionCount - 1; i >= 1; i--)
	//{
	//	for (int j = 0; j < repetitionCount - i; j++)
	//	{
	//		cout << " ";
	//	}

	//	for (int k = 0; k < 2 * i - 1; k++)
	//	{
	//		cout << symbol;
	//	}

	//	cout << endl;
	//}

	// 10
	/*int lowerBound, upperBound;
	cin >> lowerBound >> upperBound;

	for (int i = lowerBound; i <= upperBound; i++)
	{
		int sum = 0;

		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				sum += j;
			}
		}

		if (sum == i)
		{
			cout << i << endl;
		}
	}*/

	// 11
	/*int num, firstNum = 1, secondNum = 1;
	cin >> num;
	cout << firstNum << " " << secondNum << " ";

	int sum = firstNum + secondNum;
	while (sum <= num)
	{
		cout << sum << " ";

		firstNum = secondNum;
		secondNum = sum;
		sum = firstNum + secondNum;
	}*/

	
}
