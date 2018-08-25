#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind_2017_2.cpp"

using namespace std;

int main() {
    vector<string> testCases = {
            "1S2D*3T",
            "1D2S#10S",
            "1D2S0T",
            "1S*2T*3S",
            "1D#2S*3S",
            "1T2D3D#",
            "1D2S3T*",
            "10S#10D*10T",
    };
//    vector<vector<int>> testCases2 = {
//            {9, 20, 28, 18, 11},
//            {46, 33, 33 ,22, 31, 50}
//    };
//    vector<vector<int>> testCases3 = {
//            {30, 1, 21, 17, 28},
//            {27 ,56, 19, 14, 14, 10}
//    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;

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