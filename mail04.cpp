#include <iostream>
#include <cmath>

using namespace std;

// If num is 100, it returns 3.
int getNumOfDigits(int num) {
    int result = 0;
    while (num > 0) {
        num /= 10;
        result++;
    }
    return result;
}

int getIntPow(int base, int idx) {
    int result = 1;
    for (int i = 0; i < idx; i++) {
        result *= base;
    }
    return result;
}

string isPalindrome(int num) {
    int numDigits = getNumOfDigits(num);
    for (int i = 0; i < (numDigits + 1) / 2; i++) {
        int smallerPowerTen = getIntPow(10, i);
        int biggerPowerTen = getIntPow(10, numDigits - i - 1);
        int smallerDigit = num % (smallerPowerTen * 10) / smallerPowerTen;
        if(i == (numDigits + 1) / 2 - 1 && numDigits % 2 == 1) {
            num -= smallerDigit * smallerPowerTen;
        }
        else {
            num -= smallerDigit * (smallerPowerTen + biggerPowerTen);
        }
    }
    return num == 0 ? "True" : "False";
}