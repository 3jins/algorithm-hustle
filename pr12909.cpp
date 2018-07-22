#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
    stack<int> parenthesises;
    string::iterator iter;
    for (iter = s.begin(); iter != s.end(); iter++) {
        if(*iter == '(') {
            parenthesises.push(1);
            continue;
        }
        if(parenthesises.empty()) return false;
        parenthesises.pop();
    }

    if(parenthesises.empty()) return true;
    return false;
}
