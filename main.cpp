#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind_2017_7.cpp"
#include "regex_test.cpp"

using namespace std;

int main() {
    vector<vector<string>> testCases = {
            {"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"},
            {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"},
            {"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"}
    };

    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
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
    return 0;
}