#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int leftOut = arr1.size();
    int middle = arr1[0].size();
    int rightOut = arr2[0].size();

    for (int i = 0; i < leftOut; i++) {
        vector<int> row;
        for (int j = 0; j < rightOut; j++) {
            int elem = 0;
            for (int k = 0; k < middle; k++) {
                elem += arr1[i][k] * arr2[k][j];
            }
            row.emplace_back(elem);
        }
        answer.emplace_back(row);
    }
    return answer;
}
