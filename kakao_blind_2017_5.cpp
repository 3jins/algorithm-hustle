// 22:28 ~ 22:49, 23:12 ~ 23:54 (1:01)
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define COMP 65536
using namespace std;

string toLowerCase(string str) {
    int strLen = str.length();
    for (int i = 0; i < strLen; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
    }
    return str;
}

bool isAlphabet(char c) {
    if (c < 'a' || c > 'z') return false;
    return true;
}

vector<string> makePairs(string str) {
    vector<string> pairs;
    int strLen = str.length();
    for (int i = 0; i < strLen - 1; i++) {
        if (!isAlphabet(str[i]) || !isAlphabet(str[i + 1])) continue;
        pairs.emplace_back(str.substr(i, 2));
    }
    return pairs;
}

int getIntersectionSize(vector<string> v1, vector<string> v2) {
    int interSize = 0;
    int size1 = v1.size();
    int size2 = v2.size();
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (v1[i] == v2[j]) {
                interSize++;
                v1.erase(v1.begin() + i--);
                v2.erase(v2.begin() + j--);
                size1--;
                size2--;
            }
        }
    }
    return interSize;
}

int solution(string s1, string s2) {
    s1 = toLowerCase(s1);
    s2 = toLowerCase(s2);
    vector<string> pairs1 = makePairs(s1);
    vector<string> pairs2 = makePairs(s2);
    int size1 = pairs1.size();
    int size2 = pairs2.size();
    if (size1 == 0 && size2 == 0) return COMP;
    int interSize = getIntersectionSize(pairs1, pairs2);
    return interSize * COMP / (size1 + size2 - interSize);
}