#include <iostream>
#include <vector>
#include "vector_util.h"
#include "pr12923.cpp"

using namespace std;

int main() {
    vector<long long> testCases = {
            1,
    };
    vector<long long> testCases2 = {
            30,
    };
//    vector<vector<vector<int>>> testCases3 = {
//            {{0, 0, 0},          {0, 0, 0},          {0, 0, 0}},
//            {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}
//    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;

        vector<int> result = solution(testCases[i], testCases2[i]);
        for(int i=1; i<=result.size(); i++) {
            cout << i << "\t";
        }
        cout << endl;
        printVector(result, "\t");
//        vector<vector<int>> result = solution(testCases[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}