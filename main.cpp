#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind1_2017_6.cpp"

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
            4,
            6,
            5,
            3,
            30,
    };
    vector<int> testCases2 = {
            5,
            6,
            5,
            3,
            30,
    };
    vector<vector<string>> testCases3 = {
            {"CCBDE", "AAADE", "AAABF", "CCBBF"},
            {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"},
            {"TTTTT", "TTTTT", "TTTTT", "TTTTT", "TTTTT"},
            {"TTT", "TTT", "TTT"},
            {"TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT"},
    };
    int numCases = testCases.size();
//    for (int i = 0; i < numCases; i++) {
        for(int i=3; i<5; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;
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