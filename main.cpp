#include <iostream>
#include <vector>
#include "pr12946.cpp"
#include "vector_util.h"

using namespace std;

int main() {
    vector<int> testCases = {
            2,
//            4
    };
//    vector<long long> testCases2 = {
//            5,
//            11
//    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;

//        vector<int> result = solution(testCases[i], testCases2[i]);
//        printVector(result, " ");
        vector<vector<int>> result = solution(testCases[i]);
        for(int i=0; i<result.size(); i++)
            printVector(result[i], " ");
    }
    return 0;
}