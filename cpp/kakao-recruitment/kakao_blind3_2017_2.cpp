// 07:05 ~ 08:02
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> dictionary;
int dictionarySize = 0;

int searchDictionary(string word) {
    vector<string>::iterator iter;
    for(iter = dictionary.begin(); iter != dictionary.end(); iter++) {
        if(*iter == word) return distance(dictionary.begin(), iter);
    }
    return -1;
}

void initDictionary() {
    dictionary.clear();
    for(char c = 'A'; c <= 'Z'; c++) {
        string tmp = "";
        tmp += c;
        dictionary.emplace_back(tmp);
    }
    dictionarySize = 'Z' - 'A' + 1;
}

vector<int> solution (string msg) {
    vector<int> indexList;
    int msgLen = msg.length();
    initDictionary();

    int i = 0;
    while(i < msgLen) {
        int len = 0;
        int idx = 0;
        int longestWordIdx = 0;
        string word = "";
        while(idx >= 0) {
            if(i + len > msgLen) break;
            word = msg.substr(i, ++len);
            idx = searchDictionary(word);
            if(idx >= 0) longestWordIdx = idx;
        }
        dictionary.emplace_back(word);
        dictionarySize++;
        i += (len - 1);
        indexList.emplace_back(longestWordIdx + 1);
    }

    return indexList;
}