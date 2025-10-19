#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// 1
	/*int dayOfWeek;
	cin >> dayOfWeek;

	if (dayOfWeek == 1)
	{
		cout << "Monday";
	}
	else if (dayOfWeek == 2)
	{
		cout << "Tuesday";
	}
	else if (dayOfWeek == 3) {
		cout << "Wednesday";
	}
	else if (dayOfWeek == 4) {
		cout << "Thursday";
	}
	else if (dayOfWeek == 5) {
		cout << "Friday";
	}
	else if (dayOfWeek == 6) {
		cout << "Saturday";
	}
	else if (dayOfWeek == 7) {
		cout << "Sunday";
	}
	else {
		cout << "Invalid day!";
	}*/

	// 2
	/*int number;
	cin >> number;

	if (number < 100)
	{
		cout << "Less than 100";
	}
	else if (number >= 100 && number < 200)
	{
		cout << "Between 100 and 200";
	}
	else {
		cout << "Greater than 200";
	}*/

	// 3
	/*double speed;
	cin >> speed;

	if (speed <= 10)
	{
		cout << "slow";
	}
	else if (speed > 10 && speed <= 50)
	{
		cout << "average";
	}
	else if (speed > 50 && speed <= 150)
	{
		cout << "fast";
	}
	else if (speed > 150 && speed <= 1000)
	{
		cout << "ultra fast";
	}
	else {
		cout << "extremely fast";
	}*/

	// 4
	/*const double PI = 3.14;

	char figureType;
	cin >> figureType;

	switch (figureType)
	{
		case 's':
		{
			double sideLength;
			cin >> sideLength;

			double squareArea = sideLength * sideLength;
			cout << squareArea;

			break;
		}
		case 'r':
		{
			double widthLength, heightLenght;
			cin >> widthLength >> heightLenght;

			double rectangleArea = widthLength * heightLenght;
			cout << rectangleArea;

			break;
		}
		case 'c':
		{
			double radius;
			cin >> radius;

			double circleArea = PI * radius * radius;
			cout << fixed << setprecision(3) << circleArea;

			break;
		}
		case 't':
		{
			double side, heightToSide;
			cin >> side >> heightToSide;

			double triangleArea = side * heightToSide / 2;
			cout << triangleArea;

			break;
		}
		default:
			break;
	}*/

	// 5
	/*int hours, minutes;
	cin >> hours >> minutes;

	int temp = minutes + 15;

	if (temp >= 60)
	{
		hours++;
		temp %= 60;
	}

	if (hours == 24)
	{
		hours = 0;
	}

	if (hours < 10 && temp < 10)
	{
		cout << "0" << hours << ":0" << temp;
	}
	else if (temp < 10)
	{
		cout << hours << ":0" << temp;
	}
	else if (hours < 10)
	{

		cout << "0" << hours << ":" << temp;
	}
	else
	{
		cout << hours << ":" << temp;
	}*/

	// 6
	//int firstNum, secondNum, thirdNum, fourthNum, fifthNum;
	//cin >> firstNum >> secondNum >> thirdNum
	//	>> fourthNum >> fifthNum;

	//bool isSequenceValid = false;

	//// Case + - + - +
	//if (secondNum <= firstNum && secondNum <= thirdNum &&
	//	fourthNum <= thirdNum && fourthNum <= fifthNum)
	//{
	//	isSequenceValid = true;
	//}
	//// Case - + - + -
	//else if (secondNum >= firstNum && secondNum >= thirdNum &&
	//	fourthNum >= thirdNum && fourthNum >= fifthNum)
	//{
	//	isSequenceValid = true;
	//}

	//cout << (isSequenceValid ? "yes" : "no");

	// 7
	int radius, pointX, pointY;
	cin >> radius >> pointX >> pointY;

	int distanceSqaured = pow(pointX, 2) + pow(pointY, 2);
	int radiusSquared = pow(radius, 2);

	if (distanceSqaured > radiusSquared)
	{
		cout << "Out of the circle";
	}
	else if (distanceSqaured == radiusSquared) {
		cout << "On the circle";
	}
	else
	{
		cout << "In the circle";
	}
}
