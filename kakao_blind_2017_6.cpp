// 8:30 ~ 9:32
#include <iostream>
#include <vector>
#include <string>

#define MAX_BOARD 30

using namespace std;

int map[MAX_BOARD + 1][MAX_BOARD];
int height = 0;
int width = 0;

void printMap() {
    for (int i = 0; i <= height; i++) {
        for (int j = 0; j < width; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void convertBoardToMap(vector<string> board) {
    int height = board.size();
    int width = board[0].length();
    for (int j = 0; j < width; j++) {
        map[0][j] = -1;
    }
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = board[i - 1][j];
        }
    }
}

void removeMatchedBlocks(int y, int x) {
    if (y >= height) return;
    if (x >= width - 1) return;
    int steps[3][3] = {
            {0, 1, 1},
            {1, 0, 1}
    };
    int curBlock = map[y][x];

    for (int i = 0; i < 3; i++) {
        if (map[y + steps[0][i]][x + steps[1][i]] != curBlock) return;
    }
    for (int i = 0; i < 3; i++) {
        removeMatchedBlocks(y + steps[0][i], x + steps[1][i]);
    }
    for (int i = 0; i < 3; i++) {
        map[y + steps[0][i]][x + steps[1][i]] = 0;
    }
    map[y][x] = 0;
}

int calculateScore() {
    int score = 0;
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 0) score++;
        }
    }
    return score;
}

void blockDown() {
    for (int j = 0; j < width; j++) {
        for (int i = height; i > 0; i--) {
            if (map[i][j] > 0) continue;
            int k = i;
            while (--k >= 1 && map[k][j] <= 0);
            map[i][j] = map[k][j];
            map[k][j] = -1;
        }
    }
}

int solution(int h, int w, vector<string> board) {
    int score = 0;
    convertBoardToMap(board);
    height = h;
    width = w;

    int cnt = 0;
    while (true) {
        for (int i = 1; i <= height - 1; i++) {
            for (int j = 0; j < width - 1; j++) {
                if (map[i][j] <= 0) continue;
                removeMatchedBlocks(i, j);
            }
        }
        int curScore = calculateScore();
        if (!curScore) break;
        score += curScore;
        blockDown();
    }

    return score;
}