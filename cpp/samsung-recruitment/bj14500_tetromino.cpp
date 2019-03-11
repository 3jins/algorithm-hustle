// 16:21 ~ 16:59
#include <iostream>
#include <vector>

#define MAX_MAP_SIZE 500

using namespace std;

int height, width;
int map[MAX_MAP_SIZE + 2][MAX_MAP_SIZE + 2];

void initMap(int h, int w, vector<vector<int>> vectorMap) {
    height = h;
    width = w;
    for (int i = 0; i <= height + 1; i++) {
        for (int j = 0; j <= width + 1; j++) {
            if(i==0 || j==0 || i == height + 1 || j == width + 1) {
                map[i][j] = -1;
                continue;
            }
            map[i][j] = vectorMap[i - 1][j - 1];
        }
    }
}

int getTetrominoSum(int y, int x) {
    int maxSum = 0;
    int steps[19][2][4] = {
            // captain
            {{0, 0, 0, 0}, {0, 1, 2, 3}},
            {{0, 1, 2, 3}, {0, 0, 0, 0}},
            // square
            {{0, 0, 1, 1}, {0, 1, 0, 1}},
            // L
            {{0, 1, 2, 2}, {0, 0, 0, 1}},
            {{0, 0, 0, 1}, {0, 1, 2, 0}},
            {{0, 0, 1, 2}, {0, 1, 1, 1}},
            {{0, 1, 1, 1}, {2, 0, 1, 2}},
            {{0, 1, 2, 2}, {1, 1, 0, 1}},
            {{0, 1, 1, 1}, {0, 0, 1, 2}},
            {{0, 0, 1, 2}, {0, 1, 0, 0}},
            {{0, 0, 0, 1}, {0, 1, 2, 2}},
            // Z
            {{0, 0, 1, 1}, {0, 1, 1, 2}},
            {{0, 1, 1, 2}, {1, 1, 0, 0}},
            {{0, 0, 1, 1}, {1, 2, 0, 1}},
            {{0, 1, 1, 2}, {0, 0, 1, 1}},
            // T
            {{0, 1, 1, 1}, {1, 0, 1, 2}},
            {{0, 1, 1, 2}, {0, 0, 1, 0}},
            {{0, 0, 0, 1}, {0, 1, 2, 1}},
            {{0, 1, 1, 2}, {1, 0, 1, 1}}
    };

    for(int i=0; i<19; i++) {
        int sum = 0;
        for(int j=0; j<4; j++) {
            int step = map[y + steps[i][0][j]][x + steps[i][1][j]];
            if(step < 0) break;
            sum += step;
        }

        maxSum = max(sum, maxSum);
    }

    return maxSum;
}

int solution(int h, int w, vector<vector<int>> vectorMap) {
    int maxSum = 0;
    initMap(h, w, vectorMap);

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            int sum = getTetrominoSum(i, j);
            maxSum = max(sum, maxSum);
        }
    }

    return maxSum;
}