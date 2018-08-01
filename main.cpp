#include <iostream>
#include <vector>
#include "pre_kakao_2017_1.cpp"
#include "vector_util.h"

using namespace std;

int main() {
    vector<int> testCases = {
//            6,
            6
    };
    vector<int> testCases2 = {
//            4,
            4
    };
    vector<vector<vector<int>>> testCases3 = {
//            {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}},
            {{1, 1, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}}
    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;

        vector<int> result = solution(testCases[i], testCases2[i], testCases3[i]);
        printVector(result, " ");
//        vector<vector<int>> result = solution(testCases[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}