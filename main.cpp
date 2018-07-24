#include <iostream>
#include <vector>
#include "pr12939.cpp"
using namespace std;

int main() {
    vector<string> testCases = {
            "1 2 3 4",
            "-1 -2 -3 -4",
            "-1 -1"
    };
    int numCases = testCases.size();
    for(int i=0; i<numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
        cout << solution(testCases[i]) << endl;
    }
    return 0;
}
