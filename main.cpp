#include <iostream>
#include <vector>
#include "vector_util.h"
#include "pr12920.cpp"

using namespace std;

int main() {
    vector<int> testCases = {
            10,
//            60
    };
    vector<vector<int>> testCases2 = {
//            {3, 5, 2, 3},
            {1, 2, 3}
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
        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;

//        vector<int> result = solution(testCases[i], testCases2[i], testCases3[i]);
//        printVector(result, " ");
//        vector<vector<int>> result = solution(testCases[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}