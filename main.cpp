#include <iostream>
#include <vector>
#include "pr12941.cpp"
using namespace std;

int main() {
    vector<pair<vector<int>, vector<int>>> testCases = {
            {{1, 4, 2}, {5, 4, 4}},
            {{1, 2}, {3, 4}}
    };
    int numCases = testCases.size();
    for(int i=0; i<numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << solution(testCases[i]) << endl;
        cout << solution(testCases[i].first, testCases[i].second) << endl;
    }
    return 0;
}
