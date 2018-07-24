#include <iostream>
#include <vector>
#include "pr12945.cpp"
using namespace std;

int main() {
    vector<int> testCases = {
            3, 5, 100000
    };
    int numCases = testCases.size();
    for(int i=0; i<numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i].first, testCases[i].second) << endl;
    }
    return 0;
}
