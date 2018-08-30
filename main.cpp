#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind3_2017_1.cpp"
#include "regex_test.cpp"

using namespace std;

int main() {
    vector<int> testCases = {
            2, 16, 16
    };
    vector<int> testCases2 = {
            4, 16, 16
    };
    vector<int> testCases3 = {
            2, 2, 2
    };
    vector<int> testCases4 = {
            1, 1, 2
    };

    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;
        cout << solution(testCases[i], testCases2[i], testCases3[i], testCases4[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;

//        vector<string> result = solution(testCases[i], testCases2[i], testCases3[i]);
//        for(int i=1; i<=result.size(); i++) {
//            cout << i << "\t";
//        }
//        cout << endl;
//        printVector(result, "\n");
//        cout << endl;
//        vector<vector<int>> result = solution(testCases[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}