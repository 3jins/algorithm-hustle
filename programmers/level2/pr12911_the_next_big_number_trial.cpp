#include <string>
#include <vector>

using namespace std;

string decaToBi(int deca) {
    string bi = "";
    while (deca > 0) {
        bi = (deca % 2 ? '1' : '0') + bi;
        deca /= 2;
    }
    return bi;
}

int biToDeca(string bi) {
    int biLen = bi.length();
    int multiplier = 1;
    int deca = 0;
    while (biLen > 0) {
        deca += (bi[--biLen] - '0') * multiplier;
        multiplier *= 2;
    }
    return deca;
}

pair<int, int> binaryDigitCounter(string bi) {
    string::iterator iter;
    int numZeros = 0;
    int numOnes = 0;
    for (iter = bi.begin(); iter != bi.end(); iter++) {
        if (*iter == '1') numOnes++;
        else numZeros++;
    }
    return pair<int, int>(numZeros, numOnes);
}

string makeSmallestBinaryByNumDigits(pair<int, int> numDigits) {
    int numZeros = numDigits.first;
    int numOnes = numDigits.second;
    string smallestBinary = "";
    for (int i = 0; i < numZeros; i++) {
        smallestBinary += '0';
    }
    for (int i = 0; i < numOnes; i++) {
        smallestBinary += '1';
    }
    return smallestBinary;
}

int solution(int n) {
    string bi = decaToBi(n);
    int lastOneIdx = bi.find_last_of("1");
    int thresholdIdx = bi.rfind("0", lastOneIdx);
    string biggerPart;
    string smallerPart;
    if (thresholdIdx < 0) {
        biggerPart = "1";
        smallerPart = bi;
    } else {
        bi.replace(thresholdIdx, 1, "1");
        biggerPart = bi.substr(0, thresholdIdx + 1);
        smallerPart = bi.substr(thresholdIdx + 1);
    }
    pair<int, int> numDigits = binaryDigitCounter(smallerPart);
    smallerPart = makeSmallestBinaryByNumDigits(pair<int, int>(numDigits.first + 1, numDigits.second - 1));
    return biToDeca(biggerPart + smallerPart);
}
