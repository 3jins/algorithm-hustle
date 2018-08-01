#include <iostream>
#include <vector>
#include "pre_kakao_2017_4.cpp"
#include "vector_util.h"

using namespace std;

int main() {
    vector<int> testCases = {
//        15, 24, 41,
        2147483647
    };
//    vector<int> testCases2 = {
//            3,
//            6
//    };
//    vector<vector<vector<int>>> testCases3 = {
//            {{0, 0, 0},          {0, 0, 0},          {0, 0, 0}},
//            {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}
//    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;

//        vector<int> result = solution(testCases[i], testCases2[i], testCases3[i]);
//        printVector(result, " ");
//        vector<vector<int>> result = solution(testCases[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}