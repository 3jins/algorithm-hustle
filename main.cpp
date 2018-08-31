#include <iostream>
#include <vector>
#include "vector_util.h"
#include "kakao_blind3_2017_3.cpp"
//#include "sort_test.cpp"

using namespace std;

int main() {
    vector<vector<string>> testCases = {
            {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"},
            {"F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"}
    };
//    vector<int> testCases2 = {
//            4, 16, 16
//    };
//    vector<int> testCases3 = {
//            2, 2, 2
//    };
//    vector<int> testCases4 = {
//            1, 1, 2
//    };

    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << testCases[i] << endl;
//        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i]) << endl;
//        cout << solution(testCases[i], testCases2[i], testCases3[i], testCases4[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;

//        solution(testCases[i]);
        vector<string> result = solution(testCases[i]);
//        vector<string> result = solution(testCases[i], testCases2[i]);
//        vector<string> result = solution(testCases[i], testCases2[i], testCases3[i]);
//        for(int i=1; i<=result.size(); i++) {
//            cout << i << "\t";
//        }
        printVector(result, ", ");

//        vector<vector<int>> result = solution(testCases[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}