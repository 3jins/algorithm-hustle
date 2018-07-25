#include <iostream>
#include <vector>
#include "vector_util.h"
#include "pr12949.cpp"

using namespace std;

int main() {
    vector<vector<vector<int>>> testCases = {
            {{1, 4}, {3, 2}, {4, 1}},
            {{2, 3, 2}, {4, 2, 4}, {3, 1, 4}}
    };
    vector<vector<vector<int>>> testCases2 = {
            {{3, 3}, {3, 3}},
            {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}}
    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
        vector<vector<int>> result = solution(testCases[i], testCases2[i]);
        for(int i=0; i<result.size(); i++)
            printVector(result[i], " ");
    }
    return 0;
}
