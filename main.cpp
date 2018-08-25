#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind_2017_1.cpp"

using namespace std;

int main() {
    vector<int> testCases = {
            5, 6
    };
    vector<vector<int>> testCases2 = {
            {9, 20, 28, 18, 11},
            {46, 33, 33 ,22, 31, 50}
    };
    vector<vector<int>> testCases3 = {
            {30, 1, 21, 17, 28},
            {27 ,56, 19, 14, 14, 10}
    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;

        vector<string> result = solution(testCases[i], testCases2[i], testCases3[i]);
//        for(int i=1; i<=result.size(); i++) {
//            cout << i << "\t";
//        }
//        cout << endl;
        printVector(result, "\n");
        cout << endl;
//        vector<vector<int>> result = solution(testCases[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}