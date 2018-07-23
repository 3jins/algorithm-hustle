#include <iostream>
#include <vector>
#include "pr12913.cpp"
using namespace std;

int main() {
    vector<vector<vector<int>>> testCases = {
            {{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}}
    };
    int numCases = testCases.size();
    for(int i=0; i<numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
        cout << solution(testCases[i]) << endl;
    }
    return 0;
}
