#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void printVector(vector<char> v, int start, int len) {
    int vectorSize = v.size();
    int end = start + len - 1;
    if(end >= vectorSize) return;
    for (int i = start; i <= end; i++) {
        cout << v[i];
    }
    cout << endl;
}

void printHashMap(unordered_map<char, int> map) {
    unordered_map<char, int>::iterator iter;
    cout << "{" << endl;
    for(iter = map.begin(); iter != map.end(); iter++) {
        cout << "  " << iter->first << ": " << iter->second << endl;
    }
    cout << "}" << endl;
}

int getLongestUnduplicatedSubstringSize(string s) {
    vector<char> v(s.begin(), s.end());
    int stringSize = v.size();
    unordered_map<char, int> map;
    int substrStart = 0;
    int ret = substrStart;

    for (int i = 0; i < stringSize; i++) {
        if(map.find(v[i]) != map.end()) {
            substrStart = map[v[i]] + 1;
        }
        map[v[i]] = i;
        ret = max(ret, i - substrStart + 1);
    }

    return ret;
}

//void test() {
//    string str = "abcd";
//    vector<char> v(str.begin(), str.end());
//    cout << v[0] << v.size() << endl;
//}
