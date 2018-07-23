#include <iostream>
#include <vector>
#include "pr12911.cpp"
using namespace std;

int main() {
    vector<int> testCases = {
            78, 15
    };
    int numCases = testCases.size();
    for(int i=0; i<numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
        cout << solution(testCases[i]) << endl;
    }
    return 0;
}
