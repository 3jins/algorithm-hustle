#include <iostream>
#include <vector>
#include "vector_util.h"
#include "bj14500_samsung.cpp"

using namespace std;

int main() {
    /* Baekjoon Style Main */
    int height, width;
    vector<vector<int>> map;
    cin >> height >> width;
    for(int i=0; i<height; i++) {
        vector<int> row;
        for(int j=0; j<width; j++) {
            int val;
            cin >> val;
            row.push_back(val);
        }
        map.push_back(row);
    }
    cout << solution(height, width, map) << endl;

    /* Programmers Style Main */
//    vector<int> testCases = {
//            4,
//            6,
//            5,
//            3,
//            30,
//    };
//    vector<int> testCases2 = {
//            5,
//            6,
//            5,
//            3,
//            30,
//    };
//    vector<vector<string>> testCases3 = {
//            {"CCBDE", "AAADE", "AAABF", "CCBBF"},
//            {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"},
//            {"TTTTT", "TTTTT", "TTTTT", "TTTTT", "TTTTT"},
//            {"TTT", "TTT", "TTT"},
//            {"TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT"},
//    };
//    int numCases = testCases.size();
////    for (int i = 0; i < numCases; i++) {
//        for(int i=3; i<5; i++) {
////        cout << (solution(testCases[i]) ? "true" : "false") << endl;
////        cout << testCases[i] << endl;
////        cout << solution(testCases[i]) << endl;
////        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;
////        cout << solution(testCases[i], testCases2[i]) << endl;
//
////        vector<string> result = solution(testCases[i], testCases2[i], testCases3[i]);
////        for(int i=1; i<=result.size(); i++) {
////            cout << i << "\t";
////        }
////        cout << endl;
////        printVector(result, "\n");
////        cout << endl;
////        vector<vector<int>> result = solution(testCases[i]);
////        for(int i=0; i<result.size(); i++)
////            printVector(result[i], " ");
//    }
    return 0;
}