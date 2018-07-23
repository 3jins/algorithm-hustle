#include <iostream>
#include <vector>
#include <algorithm>

#define ROWS 4

using namespace std;

int solution(vector<vector<int>> land) {
    int cols = land.size();
    land.insert(land.begin(), vector<int>(ROWS, 0));
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < ROWS; j++) {
            int localMax = 0;
            for (int k = 0; k < ROWS; k++) {
                if (k == j) continue;
                if (land[i][k] + land[i + 1][j] > localMax)
                    localMax = land[i][k] + land[i + 1][j];
            }
            land[i + 1][j] = localMax;
        }
    }

    return *max_element(land[cols].begin(), land[cols].end());
}
