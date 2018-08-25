#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind_2017_5.cpp"
#include "regex_test.cpp"

using namespace std;

int main() {
    vector<string> testCases = {
            "FRANCE",
            "handshake",
            "aa1+aa2",
            "E=M*C^2"
    };
    vector<string> testCases2 = {
            "french",
            "shake hands",
            "AAAA12",
            "e=m*c^2"
    };
//    vector<int> testCases3 = {
//            5,
//            2,
//            2,
//            5,
//            1,
//            45
//    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
//        cout << solution(testCases[i]) << endl;
        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;
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
    test2();
    return 0;
}