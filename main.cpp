#include <iostream>
#include "pr12905.cpp"
using namespace std;

int main() {
    vector<vector<int>> testCase = {{1, 0, 1, 1, 1, 0}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 0, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 0, 1, 1, 1}};
    cout << solution(testCase) << endl;
    return 0;
}
