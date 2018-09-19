#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind1_2018_7.cpp"

using namespace std;

int main() {
    /* Baekjoon Style Main */
//    int daysLeft;
//    vector<pair<int, int>> schedule;
//    cin >> daysLeft;
//    for(int i=0; i<daysLeft; i++) {
//        int timeRequired, profit;
//        cin >> timeRequired >> profit;
//        schedule.push_back({timeRequired, profit});
//    }
//    cout << solution(daysLeft, schedule) << endl;

    /* Programmers Style Main */
    vector<vector<vector<int>>> testCases = {
//            {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 4, 0, 0, 0}, {0, 0, 0, 0, 0, 4, 4, 0, 0, 0}, {0, 0, 0, 0, 3, 0, 4, 0, 0, 0}, {0, 0, 0, 2, 3, 0, 0, 0, 5, 5}, {1, 2, 2, 2, 3, 3, 0, 0, 0, 5}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 5}},
            {
                    {1, 0, 0, 2, 0, 0},
                    {1, 2, 2, 2, 3, 0},
                    {1, 1, 0, 3, 3, 3},
                    {4, 0, 5, 6, 6, 6},
                    {4, 5, 5, 5, 6, 0},
                    {4, 4, 0, 0, 0, 0},
            }
    };
//    vector<int> testCases2 = {
//            5,
//            40
//    };
//    vector<vector<string>> testCases3 = {
//            {"CCBDE", "AAADE", "AAABF", "CCBBF"},
//            {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"},
//            {"TTTTT", "TTTTT", "TTTTT", "TTTTT", "TTTTT"},
//            {"TTT", "TTT", "TTT"},
//            {"TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT"},
//    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//    for (int i = 1; i < 2; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;

//        vector<int> result = solution(testCases[i], testCases2[i]);
//        for(int i=1; i<=result.size(); i++) {
//            cout << i << "\t";
//        }
//        cout << endl;
//        printVector(result, " ");
//        cout << endl;
//        vector<vector<int>> result = solution(testCases[i]);
//        for (int i = 0; i < result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}