#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	// 1
	//cout << "Oh what" << endl;
	//cout << "a happy day!" << endl;
	//cout << "Oh yes" << endl;
	//cout << "what a happy day!" << endl;

	// 2
	//double width = 5.4;
	//double height = 7.9;

	//double perimeter = 2 * (width + height);
	//double area = width * height;

	//cout << "The perimeter of the rectangle is " << perimeter << endl;
	//cout << "The area of the rectangle is " << area << endl;

	// 3
	//const double CONVERSION_RATE_BGN_USD = 0.59;
	//const double CONVERSION_RATE_BGN_EUR = 0.51;

	//int priceInBGN;
	//cin >> priceInBGN;

	//cout << "The price in USD is: " << priceInBGN * CONVERSION_RATE_BGN_USD << endl;
	//cout << "The price in EUR is: " << priceInBGN * CONVERSION_RATE_BGN_EUR << endl;

	// 4
	/*cout << "Please enter the value of the first side: ";
	double width;
	cin >> width;

	cout << "Please enter the value of the second side: ";
	double height;
	cin >> height;

	double perimeter = 2 * (width + height);
	double area = width * height;

	cout << "The perimeter of the rectangle is " << perimeter << endl;
	cout << "The area of the rectangle is " << area << endl;*/

	// 5
	//int firstNum, secondNum;
	//cin >> firstNum >> secondNum;

	//bool isLesser = firstNum < secondNum;

	//cout << boolalpha << isLesser << endl;

	// 6
	//cout << "Divident: ";
	//int divident;
	//cin >> divident;

	//cout << "Divisor: ";
	//int divisor;
	//cin >> divisor;

	//int quotient = divident / divisor;
	//int remainder = divident % divisor;

	//cout << "The quotient of the division is " << quotient << endl;
	//cout << "The remainder of the division is " << remainder << endl;

	// 7
	//cout << "Apples: ";
	//int apples;
	//cin >> apples;

	//cout << "Pears: ";
	//int pears;
	//cin >> pears;

	//cout << "Bananas: ";
	//int bananas;
	//cin >> bananas;

	//cout << "Pesho, don't forget to buy " << apples << " apples, " << pears << " pears and "
	//	<< bananas << "bananas!";

	// 8
	//const double PI = 3.14;
	//double radius;
	//cin >> radius;

	//double circumference = 2 * PI * radius;
	//cout << "The circumference is: " << circumference << endl;

	//double area = PI * radius * radius;
	//cout << "The area is: " << area << endl;

	// 9
	/*int a;
	cout << "a: ";
	cin >> a;

	int b;
	cout << "b: ";
	cin >> b;

	int c;
	cout << "c: ";
	cin >> c;

	int determinant = pow(b, 2) - 4 * a * c;

	double x1, x2;
	x1 = (-b - sqrt(determinant)) / (2 * a);
	x2 = (-b + sqrt(determinant)) / (2 * a);

	cout << "x1 = " << x1 << ", x2 = " << x2 << endl;*/

	// 10
	// a) with a helper variable
	//int firstNum, secondNum, temp;
	//cin >> firstNum >> secondNum;

	//cout << "Before swap: " << firstNum << " " << secondNum << endl;

	//temp = firstNum;
	//firstNum = secondNum;
	//secondNum = temp;

	//cout << "After swap: " << firstNum << " " << secondNum << endl;

	//b) without a helper variable
	//int firstNum, secondNum;
	//cin >> firstNum >> secondNum;

	//cout << "Before swap: " << firstNum << " " << secondNum << endl;

	//firstNum = firstNum + secondNum;
	//secondNum = firstNum - secondNum;
	//firstNum = firstNum - secondNum;

	//cout << "After swap: " << firstNum << " " << secondNum << endl;

	// 11
	//int firstNum, secondNum, min, max;
	//cin >> firstNum >> secondNum;

	//bool isFirstLesser, isSecondLesser;
	//isFirstLesser = firstNum < secondNum;
	//isSecondLesser = secondNum < firstNum;

	//min = firstNum * isFirstLesser + secondNum * isSecondLesser;
	//max = firstNum + secondNum - min;

	//cout << "The min number is: " << min << endl;
	//cout << "The max number is: " << max << endl;

	// 12
	//const int SECONDS_PER_DAY = 60 * 60 * 24;
	//const int SECONDS_PER_HOUR = 60 * 60;
	//const int SECONDS_PER_MINUTES = 60;

	//int seconds;
	//cout << "Seconds: ";
	//cin >> seconds;

	//int days, hours, minutes;
	//days = seconds / SECONDS_PER_DAY;
	//seconds %= SECONDS_PER_DAY;

	//hours = seconds / SECONDS_PER_HOUR;
	//seconds %= SECONDS_PER_HOUR;

	//minutes = seconds / SECONDS_PER_MINUTES;
	//seconds %= SECONDS_PER_MINUTES;

	//cout << days << " days, " << hours << " hours, " 
	//	 << minutes << " minutes and " << seconds << " seconds";

	// 13
	/*int x1, y1, x2, y2;
	cin >> x1 >> y1;

	cout << endl;

	cin >> x2 >> y2;

	double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	cout << setprecision(3) << distance << endl;*/
	//cout << round(distance) << endl;

	// 14
	const int CREDIT_CARD_NUM_LEN = 16;

	cout << "Please enter a valid credit card with " 
		 << CREDIT_CARD_NUM_LEN << " digits" << endl;

	unsigned long long creditCard;
	cin >> creditCard;

	int lastFourDigits = creditCard % (10 * 10 * 10 * 10);
	cout << "XXXXXXXXXXXX" << lastFourDigits << endl;
	//cout << string(12, 'X') << lastFourDigits << endl;
}