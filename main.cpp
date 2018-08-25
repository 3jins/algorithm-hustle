#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind_2017_4.cpp"

using namespace std;

int main() {
    vector<int> testCases = {
            1,
            2,
            2,
            1,
            1,
            10
    };
    vector<int> testCases2 = {
            1,
            10,
            1,
            1,
            1,
            60
    };
    vector<int> testCases3 = {
            5,
            2,
            2,
            5,
            1,
            45
    };
    vector<vector<string>> testCases4 = {
            {"08:00", "08:01", "08:02", "08:03"},
            {"09:10", "09:09", "08:00"},
            {"09:00", "09:00", "09:00", "09:00"},
            {"00:01", "00:01", "00:01", "00:01", "00:01"},
            {"23:59"},
            {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"},
    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//    for (int i = 5; i < 6; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;
        cout << solution(testCases[i], testCases2[i], testCases3[i], testCases4[i]) << endl;

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