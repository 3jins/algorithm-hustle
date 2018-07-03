#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool isEachLetterMatched(string str1, string str2) {
    vector<char> v1(str1.begin(), str1.end());
    vector<char> v2(str2.begin(), str2.end());
    int strLen1 = v1.size();
    int strLen2 = v2.size();
    unordered_map<char, char> map1;
    unordered_map<char, char> map2;

    for (int i = 0; i < strLen1; i++) {
        if(map1.find(v1[i]) == map1.end()) {
            map1[v1[i]] = v2[i];
        } else {
            if (map1[v1[i]] != v2[i])
                return false;
        }
        if(map2.find(v2[i]) == map2.end()) {
            map2[v2[i]] = v1[i];
        } else {
            if (map2[v2[i]] != v1[i])
                return false;
        }
    }

    return true;
}
