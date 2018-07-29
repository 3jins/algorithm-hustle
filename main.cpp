#include <iostream>
#include <vector>
#include "pr12904.cpp"

using namespace std;

int main() {
    vector<string> testCases = {
            "abcdcba",
            "abacde",
            "tomato",
            "aatomot"
    };
//    vector<vector<vector<int>>> testCases2 = {
//            {{3, 3}, {3, 3}},
//            {{5, 4, 3}, {2, 4, 1}, {3, 1, 1}}
//    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
        cout << solution(testCases[i]) << endl;
//        cout << solution(testCases[i], testCases2[i]) << endl;
//        vector<vector<int>> result = solution(testCases[i], testCases2[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}
