#include <iostream>

using namespace std;
int main()
{
    // 1
    //int number;
    //cin >> number;

    //cout << (number % 2 == 0);

    // 2
    //int number;
    //cin >> number;

    //int firstDigit, secondDigit, thirdDigit;
    //firstDigit = number / 100;
    //secondDigit = number / 10 % 10;
    //thirdDigit = number % 10;

    //int reversed = thirdDigit * 100 + secondDigit * 10 + firstDigit;
    //cout << reversed + 1;

    // 3
    //char symbol;
    //cin >> symbol;
    //cout << (symbol == 'a' || symbol == 'e' || symbol == 'o' ||
    //    symbol == 'u' || symbol == 'i');

    // 4
    //int grade;
    //cin >> grade;

    //cout << (grade >= 2 && grade <= 6);

    // 5
    //int num;
    //cin >> num;

    //cout << num / 10;

    // 6
    //int firstNum, secondNum;
    //cin >> firstNum >> secondNum;

    //int result = pow((firstNum + secondNum), 4) - pow((firstNum - secondNum), 2);
    //cout << result;

    // 7
    /*int levaCount;
    cin >> levaCount;

    int hundredLevaBillCount = levaCount / 100;
    levaCount %= 100;

    int fiftyLevaBillCount = levaCount / 50;
    levaCount %= 50;

    int twentyLevaBillCount = levaCount / 20;
    levaCount %= 20;

    int tenLevaBillCount = levaCount / 10;
    levaCount %= 10;

    int fiveLevaBillCount = levaCount / 5;
    levaCount %= 5;

    int twoLevaBillCount = levaCount / 2;
    levaCount %= 2;

    int oneLevBillCount = levaCount %= 2;

    cout << hundredLevaBillCount << "x100lv " << fiftyLevaBillCount << "x50lv "
        << twentyLevaBillCount << "x20lv " << tenLevaBillCount << "x10lv "
        << fiveLevaBillCount << "x5lv " << twoLevaBillCount << "x2lv "
        << oneLevBillCount << "x1lv" << endl;*/

    // 8
    //int firstNum, secondNum;
    //cin >> firstNum >> secondNum;

    //bool isFirstLarger = firstNum > secondNum;
    //bool isSecondLarger = secondNum > firstNum;

    //// One of them is false, thus not affecting the sum
    //// So the sum will be the value of the larger num
    //cout << firstNum * isFirstLarger + secondNum * isSecondLarger;

    // 9
    int firstNum, secondNum;
    cin >> firstNum >> secondNum;

    cout << "Before swap: " << firstNum << " " << secondNum << endl;

    firstNum = firstNum + secondNum;
    secondNum = firstNum - secondNum;
    firstNum = firstNum - secondNum;

    cout << "After swap: " << firstNum << " " << secondNum << endl;
}