// 20:20 ~ 21:32
#include <iostream>
#include <vector>

#define MAX_TURN 1000

using namespace std;

string DecToOther(int num, int radix) {
    string numStr = "";
    while(num > 0) {
        char digit;
        if(num % radix < 10) digit = num % radix + '0';
        else digit = num % radix + 'A' - 10;
        string tmp = "";
        tmp += digit;
        numStr = tmp + numStr;
        num /= radix;
    }

    return numStr;
}

string solution(int radix, int numTurns, int numMembers, int myTurn) {
    char wholeWords[MAX_TURN] = {'0'};
    string myWords = "";
    int maxTurn = (numTurns - 1) * (numMembers) + myTurn;

    int numNow = 1;
    string numNowStr = "1";
    int numLen = 1;
    int digitPointer = 0;
    int turnCount = 0;
    while (turnCount++ < maxTurn - 1) {
        wholeWords[turnCount] = numNowStr[digitPointer++];
        if (digitPointer == numLen) {
            numNow++;
            numNowStr = DecToOther(numNow, radix);
            numLen = numNowStr.length();
            digitPointer = 0;
        }
    }

    for (int i = myTurn - 1; i <= maxTurn; i += numMembers) {
        myWords += wholeWords[i];
    }

    return myWords;
}