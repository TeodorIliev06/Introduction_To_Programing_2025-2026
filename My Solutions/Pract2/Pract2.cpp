#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// 1
	/*int year;
	bool isLeapYear;
	cin >> year;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		cout << "The entered year is indeed a leap one";
	}
	else
	{
		cout << "The entered year is NOT a leap one";
	}*/

	// 2
	/*const int MIN_LATIN_LETTER_BOUND = 'A';
	const int MAX_UPPER_CONSONANT_BOUND = 'Z';
	const int MIN_LOWER_CONSONANT_BOUND = 'a';
	const int MAX_LATIN_LETTER_BOUND = 'z';

	char symbol;
	cin >> symbol;

	if (symbol >= MIN_LATIN_LETTER_BOUND &&
		symbol <= MAX_LATIN_LETTER_BOUND)
	{
		if (symbol == 'a' || symbol == 'e' || symbol == 'o' ||
			symbol == 'u' || symbol == 'i')
		{
			cout << "The symbol is a lowercase vowel";
		}
		else if (symbol == 'A' || symbol == 'E' || symbol == 'O' ||
			symbol == 'U' || symbol == 'I')
		{
			cout << "The symbol is an uppercase vowel";
		}
		else if (symbol < MAX_UPPER_CONSONANT_BOUND)
		{
			cout << "The symbol is an uppercase consonant";
		}
		else if (symbol > MIN_LOWER_CONSONANT_BOUND)
		{
			cout << "The symbol is an lowercase consonant";
		}
	}
	else
	{
		cout << "The symbol is not a latin letter";
	}*/

	// 3
	//int firstNum, secondNum;
	//cin >> firstNum >> secondNum;

	//if (firstNum == secondNum)
	//{
	//	cout << "The numbers are equal";
	//	return 0;
	//}

	//cout << ((firstNum > secondNum)
	//	? "First num is bigger"
	//	: "Second num is bigger");

	// 4
	/*int percentage;
	cout << "Result: ";
	cin >> percentage;

	if (percentage > 100 || percentage < 0)
	{
		cout << "Please enter a valid percentage!";
		return 0;
	}

	if (percentage >= 90)
	{
		cout << "Grade: 6+";
	}
	else if (percentage >= 80)
	{
		cout << "Grade: 6";
	}
	else if (percentage >= 70)
	{
		cout << "Grade: 5";
	}
	else if (percentage >= 60)
	{
		cout << "Grade: 4";
	}
	else if (percentage >= 40)
	{
		cout << "Grade: 3";
	}
	else
	{
		cout << "Grade: 2";
	}*/

	// 5
	/*int a, b, c;
	bool isValidTriangle;

	cin >> a >> b >> c;

	isValidTriangle = (a + b > c) && (a + c > b) && (b + c > a);

	cout << (isValidTriangle ? "The triangle is valid" : "The triangle is NOT valid");*/

	// 6
	//int a, b, c;
	//cin >> a >> b >> c;

	//// Null checks
	//if (a == 0)
	//{
	//	if (b == 0)
	//	{
	//		if (c == 0)
	//		{
	//			cout << "Every ""x"" is a solution";
	//		}
	//		else
	//		{
	//			cout << "No real solutions";
	//		}
	//	}
	//	else
	//	{
	//		double x = -c / b;
	//		cout << "x = " << x;
	//	}

	//	return 0;
	//}

	//// Base case
	//int determinant = pow(b, 2) - 4 * a * c;

	//if (determinant < 0)
	//{
	//	cout << "No real solutions";
	//	return 0;
	//}

	//double x1, x2;
	//x1 = (-b - sqrt(determinant)) / (2 * a);
	//x2 = (-b + sqrt(determinant)) / (2 * a);

	//cout << "x1 = " << x1 << ", x2 = " << x2 << endl;

	// 7
	/*const int MIN_LATIN_LETTER_BOUND = 'A';
	const int MAX_UPPER_CONSONANT_BOUND = 'Z';
	const int MIN_LOWER_CONSONANT_BOUND = 'a';
	const int MAX_LATIN_LETTER_BOUND = 'z';
	const int TO_UPPER_TO_LOWER = MIN_LOWER_CONSONANT_BOUND - MIN_LATIN_LETTER_BOUND;

	char symbol;
	cin >> symbol;

	if (symbol >= MIN_LATIN_LETTER_BOUND &&
		symbol <= MAX_LATIN_LETTER_BOUND)
	{
		if (symbol <= MAX_UPPER_CONSONANT_BOUND)
		{
			symbol += TO_UPPER_TO_LOWER;
			cout << symbol;
		}
		else if (symbol >= MIN_LOWER_CONSONANT_BOUND)
		{
			symbol -= TO_UPPER_TO_LOWER;
			cout << symbol;
		}
	}
	else
	{
		cout << "Invalid character";
	}*/

	// 8
	/*const char ROMAN_ONE = 'I';
	const char ROMAN_FIVE = 'V';
	const char ROMAN_TEN = 'X';

	int arabicNum;
	cout << "Arabic numeral: ";
	cin >> arabicNum;

	switch (arabicNum)
	{
		case 1:
			cout << ROMAN_ONE;
			break;
		case 2:
			cout << ROMAN_ONE << ROMAN_ONE;
			break;
		case 3:
			cout << ROMAN_ONE << ROMAN_ONE << ROMAN_ONE;
			break;
		case 4:
			cout << ROMAN_ONE << ROMAN_FIVE;
			break;
		case 5:
			cout << ROMAN_FIVE;
			break;
		case 6:
			cout << ROMAN_FIVE << ROMAN_ONE;
			break;
		case 7:
			cout << ROMAN_FIVE << ROMAN_ONE << ROMAN_ONE;
			break;
		case 8:
			cout << ROMAN_FIVE << ROMAN_ONE << ROMAN_ONE << ROMAN_ONE;
			break;
		case 9:
			cout << ROMAN_ONE << ROMAN_TEN;
			break;
		default:
			break;
	}*/

	// 9
	//int firstNum, secondNum, thirdNum, temp;
	//cin >> firstNum >> secondNum >> thirdNum;

	//// a <= b
	//if (firstNum > secondNum)
	//{
	//	temp = firstNum;
	//	firstNum = secondNum;
	//	secondNum = temp;
	//}

	//// a <= c
	//if (firstNum > thirdNum)
	//{
	//	temp = firstNum;
	//	firstNum = thirdNum;
	//	thirdNum = temp;
	//}

	//// b <= c
	//if (secondNum > thirdNum)
	//{
	//	temp = secondNum;
	//	secondNum = thirdNum;
	//	thirdNum = temp;
	//}

	//cout << firstNum << " " << secondNum << " " << thirdNum;

	// 10
	//double firstOperand, secondOperand, output;
	//char _operator;

	//cin >> firstOperand >> _operator >> secondOperand;

	//switch (_operator)
	//{
	//	case '+':
	//		output = firstOperand + secondOperand;
	//		break;
	//	case '-':
	//		output = firstOperand - secondOperand;
	//		break;
	//	case '*':
	//		output = firstOperand * secondOperand;
	//		break;
	//	case '/':
	//		if (secondOperand == 0)
	//		{
	//			cout << "Can not divide by zero";
	//			return 0;
	//		}
	//		output = firstOperand / secondOperand;
	//		break;
	//	default:
	//		cout << "Please enter a valid operator";
	//		break;
	//}

	//cout << fixed << setprecision(2) << output;

	// 11 
	//int firstDigit, secondDigit, thirdDigit, temp;
	//cin >> firstDigit >> secondDigit >> thirdDigit;

	//// a <= b
	//if (firstDigit < secondDigit)
	//{
	//	temp = firstDigit;
	//	firstDigit = secondDigit;
	//	secondDigit = temp;
	//}

	//// a <= c
	//if (firstDigit < thirdDigit)
	//{
	//	temp = firstDigit;
	//	firstDigit = thirdDigit;
	//	thirdDigit = temp;
	//}

	//// b <= c
	//if (secondDigit < thirdDigit)
	//{
	//	temp = secondDigit;
	//	secondDigit = thirdDigit;
	//	thirdDigit = temp;
	//}

	//int output = firstDigit * 100 + secondDigit * 10 + thirdDigit;

	//cout << output;
	
	// 12
	//int day, month;

	//cout << "Date: ";

	//cin >> day >> month;
	//day++;

	//switch (month)
	//{
	//	case 1:
	//	case 3:
	//	case 5:
	//	case 7:
	//	case 8:
	//	case 10:
	//	case 12:
	//		if (day > 31)
	//		{
	//			day = 1;
	//			month++;
	//		}
	//		if (month > 12)
	//		{
	//			month = 1;
	//		}
	//		break;
	//	case 4:
	//	case 6:
	//	case 9:
	//	case 11:
	//		if (day > 30)
	//		{
	//			day = 1;
	//			month++;
	//		}
	//		break;
	//	case 2:
	//		if (day > 28)
	//		{
	//			day = 1;
	//			month++;
	//		}
	//		break;
	//	default:
	//		cout << "Please enter a valid date";
	//		return 0;
	//}

	//cout << "Next date: " << day << " " << month;

	// 13
	//const int MIN_VALUE = 1000;
	//const int MAX_VALUE = 9999;

	//int input;

	//cin >> input;

	//if (input < MIN_VALUE || input > MAX_VALUE)
	//{
	//	cout << "Please enter a 4-digit number!";
	//	return 0;
	//}

	//int firstNumber, secondNumber;
	//firstNumber = (input / 1000) * 10 + (input % 10);
	//secondNumber = (input / 100 % 10) * 10 + (input /10 % 10);

	//if (firstNumber < secondNumber)
	//{
	//	cout << "less (" << firstNumber << "<" << secondNumber << ")";
	//}
	//else if (firstNumber == secondNumber)
	//{
	//	cout << "equal (" << firstNumber << "=" << secondNumber << ")";
	//}
	//else
	//{
	//	cout << "greater (" << firstNumber << ">" << secondNumber << ")";
	//}
}
