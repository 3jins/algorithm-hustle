#include <iostream>
#include <vector>
#include "pre_kakao_2017_3.cpp"
//#include "regex_test.cpp"
#include "vector_util.h"

using namespace std;

int main() {
    vector<string> testCases = {
//            "HaEaLaLaObWORLDb",
//            "HELLOWaOaRaLaD",
//            "aHbEbLbLbOacWdOdRdLdDc",
//            "aHELLOa bWORLDb",
//            "HaEaLaLObWORLDb",
//            "HaEaLaLaOWaOaRaLaD",
//            "abHELLObaWORLD",
//            "SpIpGpOpNpGJqOqA",
            "AxAxAxAyByCzC",
            "TEST"
//            "AxAxAxAoBoBoB",
//            "HELLObWORLDbFcUcCcK"
    };

//    vector<int> testCases2 = {
//            3,
//            6
//    };
//    vector<vector<vector<int>>> testCases3 = {
//            {{0, 0, 0},          {0, 0, 0},          {0, 0, 0}},
//            {{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}}
//    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << i << ") " << testCases[i] << endl;
        cout << i << ") " << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;

//        vector<int> result = solution(testCases[i], testCases2[i], testCases3[i]);
//        printVector(result, " ");
//        vector<vector<int>> result = solution(testCases[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}