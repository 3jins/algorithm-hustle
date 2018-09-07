// 14:33 ~ 16:51
#include <iostream>
#include <vector>

#define MAX_MAP_SIZE 100

using namespace std;

class SnakeNode {
public:
    int y, x, direction;

    SnakeNode(int y, int x, int direction) {
        this->y = y;
        this->x = x;
        this->direction = direction;
    }
};

int mapSize = 0;
int map[MAX_MAP_SIZE + 2][MAX_MAP_SIZE + 2];
vector<SnakeNode *> snake;

// For debugging
void printNow() {
    char tmp[MAX_MAP_SIZE][MAX_MAP_SIZE];
    for(int i = 0; i<mapSize; i++) {
        for(int j=0; j<mapSize; j++) {
            if(map[i+1][j+1] == 0)
                tmp[i][j] = 'O';
            if(map[i+1][j+1] == 1)
                tmp[i][j] = 'A';
        }
    }
    for(auto snakeNode : snake) {
        tmp[snakeNode->y - 1][snakeNode-> x - 1] = 'S';
    }

    for(int i = 0; i<mapSize; i++) {
        for (int j = 0; j < mapSize; j++) {
            cout << tmp[i][j];
        }
        cout << endl;
    }
    cout << "---------" << endl;
}

void initMap(int _mapSize, vector<pair<int, int>> appleCoords) {
    mapSize = _mapSize;

    // TODO: optimize this
    for (int i = 0; i <= mapSize + 1; i++) {
        for (int j = 0; j <= mapSize + 1; j++) {
            if (i == 0 || j == 0 || i == mapSize + 1 || j == mapSize + 1)
                map[i][j] = -1;
        }
    }

    for (auto appleCoord : appleCoords) {
        map[appleCoord.first][appleCoord.second] = 1;
    }
    snake.push_back(new SnakeNode(1, 1, 0));
}

bool isCollision(int y, int x) {
    if (map[y][x] < 0) return true;
    for (auto snakeNode : snake) {
        if (snakeNode->y == y && snakeNode->x == x) return true;
    }
    return false;
}

int moveSnake(int turn) {
    int ySteps[4] = {0, 1, 0, -1};
    int xSteps[4] = {1, 0, -1, 0};

    SnakeNode *head = snake.back();
    int direction = (head->direction + turn + 4) % 4;
    int y = head->y + ySteps[direction];
    int x = head->x + xSteps[direction];

//    cout << y << ", " << x << " / " << direction << " : " << map[y][x] << " ~ " << snake.size() << endl;

    if (isCollision(y, x)) return -1;
    SnakeNode *newSnakeHead = new SnakeNode(y, x, direction);
    snake.push_back(newSnakeHead);
    if (map[y][x] != 1) snake.erase(snake.begin());
    else map[y][x] = 0;

    return 0;
}

int solution(int _mapSize, vector<pair<int, int>> appleCoords, vector<pair<int, char>> snakeLogs) {
    int totalSec = 0;
    initMap(_mapSize, appleCoords);

    int turn = 0;
    int sec = 0;
    for (auto snakeLog : snakeLogs) {
        sec = snakeLog.first - totalSec;
//        cout << turn << endl;
        for (int i = 0; i < sec; i++) {
            totalSec++;
//            printNow();
//            cout << totalSec << ") ";
            if (moveSnake((i == 0 ? turn : 0)) < 0) return totalSec;
        }
        turn = snakeLog.second == 'L' ? -1 : 1;
    }
    totalSec++;
//    printNow();
    if (moveSnake(turn) < 0) return totalSec;
    while (true) {
        totalSec++;
//        printNow();
        if (moveSnake(0) < 0) return totalSec;
    }
}
