#include <iostream>
#include <vector>
#include "pr12907.cpp"

using namespace std;

int main() {
    vector<int> testCases = {
            12,
            5
    };
    vector<vector<int>> testCases2 = {
            {1, 2, 5, 7},
            {2, 3}
    };
    int numCases = testCases.size();
    for (int i = 0; i < numCases; i++) {
//        cout << (solution(testCases[i]) ? "true" : "false") << endl;
//        cout << solution(testCases[i]) << endl;
        cout << solution(testCases[i], testCases2[i]) << endl;
//        vector<vector<int>> result = solution(testCases[i], testCases2[i]);
//        for(int i=0; i<result.size(); i++)
//            printVector(result[i], " ");
    }
    return 0;
}