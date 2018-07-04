#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLongestPrefixLen(vector<string> input) {
    int numStrings = input.size();
    string criterion = input[0];
    int lenCriterion = criterion.size();
    int ret = lenCriterion;

    for (int i = 1; i < numStrings; i++) {
        string cmp = input[i];
        int lenCmp = input[i].size();
        int len = min(lenCriterion, lenCmp);
        int lenCommonPrefix = 0;
        for (int j = 0; j < len; j++) {
            if(criterion[j] == cmp[j]) {
                lenCommonPrefix++;
            }
        }
        if(lenCommonPrefix < ret) {
            ret = lenCommonPrefix;
        }
    }

    return ret;
}