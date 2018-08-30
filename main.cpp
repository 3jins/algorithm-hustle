#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind3_2017_2.cpp"

using namespace std;

int main() {
    vector<string> testCases = {
            "KAKAO",
            "TOBEORNOTTOBEORTOBEORNOT"
    };
//    vector<int> testCases2 = {
//            4, 16, 16
//    };
//    vector<int> testCases3 = {
//            2, 2, 2
//    };
//    vector<int> testCases4 = {
//            1, 1, 2
//    };

    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i], testCases4[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;

//        solution(testCases[i]);
        vector<int> result = solution(testCases[i]);
//        vector<string> result = solution(testCases[i], testCases2[i]);
//        vector<string> result = solution(testCases[i], testCases2[i], testCases3[i]);
//        for(int i=1; i<=result.size(); i++) {
//            cout << i << "\t";
//        }
        printVector(result, " ");

//        vector<vector<int>> result = solution(testCases[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}