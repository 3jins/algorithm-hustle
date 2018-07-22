#include <iostream>
#include <vector>
#include "pr12909.cpp"
using namespace std;

int main() {
    vector<string> testCases = {
            "()()", "(())()", ")()(", "(()("
    };
    int numCases = testCases.size();
    for(int i=0; i<numCases; i++) {
        cout << (solution(testCases[i]) ? "true" : "false") << endl;
    }
    return 0;
}
