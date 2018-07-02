#include <iostream>
#include <iterator>
#include "mail10.cpp"

using namespace std;

int main() {
    cout << getLongestUnduplicatedSubstringSize("abcabd") << endl;
    cout << getLongestUnduplicatedSubstringSize("aabcbcbc") << endl;
    cout << getLongestUnduplicatedSubstringSize("aaaaaaaa") << endl;
    cout << getLongestUnduplicatedSubstringSize("abbbcedd") << endl;
    return 0;
}

