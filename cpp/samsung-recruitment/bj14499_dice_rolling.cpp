// 16:41 ~ 18:19, 19:01 ~ 19:20
#include <iostream>
#include <vector>

#define MAX_MAP_SIZE 20

using namespace std;

int map[MAX_MAP_SIZE + 2][MAX_MAP_SIZE + 2] = {0, };

class Coord {
public:
    int y, x;

    Coord(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

class Dice {
public:
    int up, down, east, west, south, north;
    Coord *dicePos;

    Dice(int y, int x) {
        this->up = 0;
        this->down = 0;
        this->east = 0;
        this->west = 0;
        this->south = 0;
        this->north = 0;
        this->dicePos = new Coord(y, x);
    }

    int roll(int direction) {
        int nextStepsY[4] = {0, 0, -1, 1};
        int nextStepsX[4] = {1, -1, 0, 0};
        int nextPosVal = map[dicePos->y + nextStepsY[direction - 1]][dicePos->x + nextStepsX[direction - 1]];
        if (nextPosVal < 0) return -1;
        dicePos->y += nextStepsY[direction - 1];
        dicePos->x += nextStepsX[direction - 1];
        int tmp = 0;
        switch (direction) {
            case 1: // East
                tmp = east;
                east = down;
                down = west;
                west = up;
                up = tmp;
                break;
            case 2: // West
                tmp = west;
                west = down;
                down = east;
                east = up;
                up = tmp;
                break;
            case 3: // North
                tmp = north;
                north = down;
                down = south;
                south = up;
                up = tmp;
                break;
            case 4: // South
                tmp = south;
                south = down;
                down = north;
                north = up;
                up = tmp;
                break;
        }
        if (nextPosVal == 0) {
            map[dicePos->y][dicePos->x] = down;
        } else {
            down = nextPosVal;
            map[dicePos->y][dicePos->x] = 0;
        }
        return 0;
    }
};

void solution(int y, int x, vector<vector<int>> vectorMap, vector<int> commands, int height, int width) {
    vector<int> listDiceTop;
    Dice *dice = new Dice(y + 1, x + 1);

    for (int i = 0; i <= height + 1; i++) {
        for (int j = 0; j <= width + 1; j++) {
            if (i == 0 || i == height + 1 || j == 0 || j == width + 1) {
                map[i][j] = -1;
                continue;
            }
            map[i][j] = vectorMap[i - 1][j - 1];
        }
    }

    for (int command : commands) {
        if (dice->roll(command) < 0) {
            continue;
        }
        cout << dice->up << endl;
    }
}