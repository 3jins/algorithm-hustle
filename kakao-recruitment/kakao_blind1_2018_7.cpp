//
#include <iostream>
#include <vector>

#define MAX_BOARD_SIZE 50
using namespace std;

typedef pair<int, int> pii;

class CoreBlock {
public:
    pii coord;
    int kind;
    int rotate;

    CoreBlock(pii coord, int kind, int rotate) {
        this->coord = coord;
        this->kind = kind;
        this->rotate = rotate;
    }
};

int map[MAX_BOARD_SIZE + 2][MAX_BOARD_SIZE + 2] = {0,};
int mapSize;

void printMap() {
    for(int i=1; i<=mapSize; i++) {
        for(int j=1; j<=mapSize; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isCoreBlock(int y, int x, int elem) {
    bool evidence[4] = {0, 0, 0, 0};
    int steps[2][4] = {
            {0, 1, 0,  -1},
            {1, 0, -1, 0}
    };
    for (int i = 0; i < 4; i++) {
        if (map[y + steps[0][i]][x + steps[1][i]] == elem)
            evidence[i] = 1;
    }
    for (int i = 0; i < 4; i++) {
        if (evidence[i] && evidence[(i + 1) % 4]) return true;
    }
    return false;
}

CoreBlock *findCoreBlock(int y, int x, int elem) {
    vector<bool> coreEvidence = {0, 0, 0, 0};
    int steps[2][4] = {
            {0, 1, 0,  -1},
            {1, 0, -1, 0}
    };
    for (int i = 0; i < 4; i++) {
        if (map[y + steps[0][i]][x + steps[1][i]] == elem)
            coreEvidence[i] = true;
    }
    if (coreEvidence == vector<bool>({1, 1, 1, 0}))
        return new CoreBlock({y, x}, 0, 0);
    if (coreEvidence == vector<bool>({0, 1, 1, 1}))
        return new CoreBlock({y, x}, 0, 1);
    if (coreEvidence == vector<bool>({1, 0, 1, 1}))
        return new CoreBlock({y, x}, 0, 2);
    if (coreEvidence == vector<bool>({1, 1, 0, 1}))
        return new CoreBlock({y, x}, 0, 3);

    if (coreEvidence == vector<bool>({1, 0, 0, 1})) {
        if (map[y][x + 2] == elem) {
            return new CoreBlock({y, x}, 2, 1);
        } else {
            return new CoreBlock({y, x}, 1, 0);
        }
    }
    if (coreEvidence == vector<bool>({1, 1, 0, 0})) {
        if (map[y + 2][x] == elem) {
            return new CoreBlock({y, x}, 2, 2);
        } else {
            return new CoreBlock({y, x}, 1, 1);
        }
    }
    if (coreEvidence == vector<bool>({0, 1, 1, 0})) {
        if (map[y][x - 2] == elem) {
            return new CoreBlock({y, x}, 2, 3);
        } else {
            return new CoreBlock({y, x}, 1, 2);
        }
    }
    if (coreEvidence == vector<bool>({0, 0, 1, 1})) {
        if (map[y - 2][x] == elem) {
            return new CoreBlock({y, x}, 2, 0);
        } else {
            return new CoreBlock({y, x}, 1, 3);
        }
    }
}

vector<pii> findHoles(CoreBlock *coreBlock) {
    vector<pii> holes;
    int y = coreBlock->coord.first;
    int x = coreBlock->coord.second;
//    cout << y << ", " << x << endl;

    int stepsY[3][2][4] = {
            {   // T, clockwise
                    {1,  -1, -1, -1},
                    {1,  1,  -1, 1}
            },
            {   // L, clockwise
                    {-2, 1,  1,  -1},
                    {-1, 1,  2,  -1}
            },
            {   // ┘, clockwise
                    {-2, -1, 1,  1},
                    {-1, -1, 2,  1}
            },
    };
    int stepsX[3][2][4] = {
            {   // T, clockwise
                    {-1, -1, -1, 1},
                    {1,  -1, 1,  1}
            },
            {   // L, clockwise
                    {1,  1,  -1, -2},
                    {1,  2,  -1, -1}
            },
            {   // ┘, clockwise
                    {-1, 1,  1,  -2},
                    {-1, 2,  1,  -1}
            },
    };

    holes.push_back(
            {y + stepsY[coreBlock->kind][0][coreBlock->rotate], x + stepsX[coreBlock->kind][0][coreBlock->rotate]});
    holes.push_back(
            {y + stepsY[coreBlock->kind][1][coreBlock->rotate], x + stepsX[coreBlock->kind][1][coreBlock->rotate]});

    return holes;
}

bool fillable(pii hole) {
    for (int i = hole.first; i > 0; i--) {
//        cout << map[i][hole.second] << " ";
        if (map[i][hole.second] > 0)
            return false;
    }
    return true;
}

void removeBlock(int y, int x, int elem) {
    int steps[2][9] = {
            {0, 0, 0, 1, 2, 0,  0,  -1, -2},
            {0, 1, 2, 0, 0, -1, -2, 0,  0}
    };

    for (int i = 0; i < 9; i++) {
        int nextY = y + steps[0][i];
        int nextX = x + steps[1][i];
        if (nextY <= 0 || nextX <= 0 || nextY >= mapSize + 1 || nextX >= mapSize + 1) continue;
        if (map[nextY][nextX] == elem)
            map[nextY][nextX] = 0;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    mapSize = board.size();

    for (int i = 0; i <= mapSize + 1; i++) {
        for (int j = 0; j <= mapSize + 1; j++) {
            if (i == 0 || j == 0 || i == mapSize + 1 || j == mapSize + 1) {
                map[i][j] = -1;
                continue;
            }
            map[i][j] = board[i - 1][j - 1];
        }
    }

    int count = -1;
    while (count != 0) {
        count = 0;
        for (int j = 1; j <= mapSize; j++) {
            for (int i = 1; i <= mapSize; i++) {
                if (map[i][j] == 0) continue;
                if (!isCoreBlock(i, j, map[i][j])) continue;
//                cout << i << ", " << j << endl;
                CoreBlock *coreBlock = findCoreBlock(i, j, map[i][j]);
                vector<pii> holes = findHoles(coreBlock);
//                cout << holes[0].first << ", " << holes[0].second << ": " << map[holes[0].first][holes[0].second] << " / "
//                     << holes[1].first << ", " << holes[1].second << ": " << map[holes[1].first][holes[1].second] << endl;
                if (!fillable(holes[0])) continue;
                if (!fillable(holes[1])) continue;
                removeBlock(i, j, map[i][j]);
                count++;
            }
        }
        answer += count;
    }

    return answer;
}