// 17:31 ~ 18:25, fail
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    int len = min(a.length(), b.length());
    for(int i=0; i<len; i++) {
        if(a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return a.length() < b.length();
}

int solution(vector<string> s) {
    int totalCount = 0;
    int count = 0;
    int numWords = s.size();

    sort(s.begin(), s.end(), cmp);

    int indexCache = 0;
    string targetWord = s[0];
    int targetWordLen = targetWord.length();
    for (int j = 0; j < targetWordLen; j++) {
        count++;
        indexCache++;
        if(targetWord[j] != s[1][j]) break;
        if(j == targetWordLen - 1) indexCache++;
    }
    totalCount += count;

    for (int i = 1; i < s.size() - 1; i++) {
        int countCandidate = indexCache;
        indexCache = 0;
        count = 0;
        targetWord = s[i];
        targetWordLen = targetWord.length();
        for (int j = 0; j < targetWordLen; j++) {
            count++;
            indexCache++;
            if(targetWord[j] != s[i + 1][j]) break;
            if(j == targetWordLen - 1) indexCache++;
        }
        totalCount += max(count, countCandidate);
    }

    return totalCount + indexCache;
}