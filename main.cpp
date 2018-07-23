#include <iostream>
#include <vector>
#include "pr12911_trial.cpp"
using namespace std;

int main() {
    vector<int> testCases = {
            78, 15, 1000000, 999999
    };
    int numCases = testCases.size();
    for(int i=0; i<numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
        cout << solution(testCases[i]) << endl;
    }
    return 0;
}
