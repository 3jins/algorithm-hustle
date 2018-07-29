#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str = "";

bool isPalindrome(int head, int tail) {
    int lastIdx = (tail - head) / 2;
    for (int i = 0; i <= lastIdx; i++) {
        if (str[head + i] != str[tail - i])
            return false;
    }
    return true;
}

int solution(string s) {
    str = s;
    int strLen = str.size();
    int answer = 1;

    for (int i = 0; i < strLen - 1; i++) {
        for (int j = i + 1; j < strLen; j++) {
            if(j - i + 1 <= answer)
                continue;
            if (isPalindrome(i, j)) {
                answer = j - i + 1;
            }
        }
    }

    return answer;
}