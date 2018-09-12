#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind1_2017_4.cpp"

using namespace std;

int main() {
    /* Baekjoon Style Main */
//    int N, M;
//    int samsungY, samsungX;
//    int K;
//    vector<vector<int>> map;
//    vector<int> commands;
//    cin >> N >> M >> samsungX >> samsungY >> K;
//    for(int i=0; i<N; i++) {
//        vector<int> row;
//        for(int j=0; j<M; j++) {
//            int coordVal;
//            cin >> coordVal;
//            row.push_back(coordVal);
//        }
//        map.push_back(row);
//    }
//    for(int i=0; i<K; i++) {
//        int command;
//        cin >> command;
//        commands.push_back(command);
//    }
//
//    solution(samsungX, samsungY, map, commands, N, M);

    /* Programmers Style Main */
    vector<int> testCases = {
            1,
            2,
            2,
            1,
            1,
            10,
            2
    };
    vector<int> testCases2 = {
            1,
            10,
            1,
            1,
            1,
            60,
            60,
    };
    vector<int> testCases3 = {
            5,
            2,
            2,
            5,
            1,
            45,
            2,
    };
    vector<vector<string>> testCases4 = {
            {"08:00", "08:01", "08:02", "08:03"},
            {"09:10", "09:09", "08:00"},
            {"09:00", "09:00", "09:00", "09:00"},
            {"00:01", "00:01", "00:01", "00:01", "00:01"},
            {"23:59"},
            {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"},
            {"00:00", "00:00", "00:00", "00:01", "00:01", "01:01"},
    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//    for (int i = 6; i < 7; i++) {
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