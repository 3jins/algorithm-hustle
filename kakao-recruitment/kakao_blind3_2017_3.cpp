// 09:47 ~ 11:34, fail
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FileName {
public:
    string head;
    int number;
    string tail;

    FileName(string head, int number, string tail) {
        this->head = head;
        this->number = number;
        this->tail = tail;
    }
};

typedef pair<FileName *, int> pfi;

bool cmp(pfi a, pfi b) {
    if(a.first->head == b.first->head) return a.first->number < b.first->number;
    return a.first->head < b.first->head;
}

string removeExtension(string s) {
    return s.substr(0, s.find_last_of("."));
}

string toLowerCase(string s) {
    string lowerCaseString = "";
    int strLen = s.length();
    for (int i = 0; i < strLen; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            lowerCaseString += s[i] - ('A' - 'a');
            continue;
        }
        lowerCaseString += s[i];
    }
    return lowerCaseString;
}

string removeFirstZeros(string s) {
    string removedString = "";
    bool wasNumber = false;
    int strLen = s.length();

    for (int i = 0; i < strLen; i++) {
        if (s[i] == '0' && !wasNumber) continue;
        if (s[i] >= '1' && s[i] <= '9')
            wasNumber = true;
        else
            wasNumber = false;
        removedString += s[i];
    }
    return removedString;
}

FileName *tokenizeFileName(string s) {
    string modifiedStr = toLowerCase(removeExtension(s));
    int strLen = modifiedStr.length();
    string head = "";
    string numberStr = "";
    string tail = "";
    int phase = 0;
    for (int i = 0; i < strLen; i++) {
        switch (phase) {
            case 0:
                if (modifiedStr[i] >= '0' && modifiedStr[i] <= '9') {
                    phase++;
                    numberStr += modifiedStr[i];
                    break;
                }
                head += modifiedStr[i];
                break;
            case 1:
                if (modifiedStr[i] < '0' || modifiedStr[i] > '9') {
                    phase++;
                    tail += modifiedStr[i];
                    break;
                }
                numberStr += modifiedStr[i];
                break;
            case 2:
                tail += modifiedStr[i];
                break;
        }
    }
    int number = stoi(numberStr);
    return new FileName(head, number, tail);
}

vector<string> solution(vector<string> fileNames) {
    vector<string> sortedFileNames;
    int numFiles = fileNames.size();
    vector<pfi> refinedFileNames;
    for (int i = 0; i < numFiles; i++) {
        FileName *tokenizedFileName = tokenizeFileName(fileNames[i]);
        refinedFileNames.push_back(pfi(tokenizedFileName, i));
    }

    sort(refinedFileNames.begin(), refinedFileNames.end(), cmp);

    for (int i = 0; i < numFiles; i++) {
        sortedFileNames.push_back(fileNames[refinedFileNames[i].second]);
    }
    return sortedFileNames;
}
