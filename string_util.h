#ifndef ALGORITHM_HUSTLE_STRING_UTIL_H_H
#define ALGORITHM_HUSTLE_STRING_UTIL_H_H

#include <vector>

using namespace std;

vector<string> split(string s, string delim) {
    vector<string> ret;
    while (true) {
        int cutIdx = s.find(delim);
        if (cutIdx < 0) {
            ret.emplace_back(s);
            break;
        }
        ret.emplace_back(s.substr(0, cutIdx));
        s = s.substr(cutIdx + delim.length());
    }
    return ret;
}

#endif //ALGORITHM_HUSTLE_STRING_UTIL_H_H
