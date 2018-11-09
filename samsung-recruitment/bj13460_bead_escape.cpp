// 10:25 ~ 11:39, 15:00 ~ 15:12, 15:44 ~ 16:00?, 16:40 ~ 17:30, 18:00 ~ 20:20, fail (
#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 10
using namespace std;

class Coord {
public:
    int y;
    int x;
    int By;
    int Bx;
    int count;
    bool isSuccess;

    Coord() {}

    Coord(int y, int x, int By, int Bx, int count, bool isSuccess) {
        this->y = y;
        this->x = x;
        this->By = By;
        this->Bx = Bx;
        this->count = count;
        this->isSuccess = isSuccess;
    }
};

char map[MAX_SIZE][MAX_SIZE];
int rowSize, colSize;
int isVisited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
queue<Coord *> bfsQ;

vector<Coord *> findNextSteps(Coord *curPos) {
    vector<Coord *> nextSteps;

    int count = curPos->count;
    if (count == 10) return nextSteps;
    int ySteps[4] = {0, 1, 0, -1};
    int xSteps[4] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
        bool isBlueEscaped = false;
        int nextY = curPos->y + ySteps[i];
        int nextX = curPos->x + xSteps[i];
        int nextBy = curPos->By + ySteps[i];
        int nextBx = curPos->Bx + xSteps[i];
//        if(curPos->y == 4 && curPos->x == 2 && curPos->By == 5 && curPos->Bx == 1) {
//            cout << nextY << nextX << ", " << nextBy << nextBx << ": " << isVisited[nextY][nextX][nextBy][nextBx] << ", " << map[nextY][nextX] << "/" << map[nextBy][nextBx] << endl;
//        }
        if (map[nextY][nextX] == '#' && map[nextBy][nextBx] == '#') continue;
        if (isVisited[nextY][nextX][nextBy][nextBx]) continue;

        bool blueShouldBack = false;
        while (map[nextBy][nextBx] != '#') {
            if (map[nextBy][nextBx] == 'O') {
                isBlueEscaped = true;
                break;
            }
            if (nextBy == curPos->y && nextBx == curPos->x) blueShouldBack = true;
            nextBy += ySteps[i];
            nextBx += xSteps[i];
        }
        if (isBlueEscaped) continue;

        bool isSuccess = false;
        bool redShouldBack = false;
        while (map[nextY][nextX] != '#') {
            if (map[nextY][nextX] == 'O') {
                isSuccess = true;
                break;
            }
            if (nextY == curPos->By && nextX == curPos->Bx) redShouldBack = true;
            nextY += ySteps[i];
            nextX += xSteps[i];
        }

        int stepBacks[4] = {-ySteps[i], -xSteps[i], -ySteps[i], -xSteps[i]};
        if(!isSuccess) {
            if (redShouldBack) {
                stepBacks[0] *= 2;
                stepBacks[1] *= 2;
            }
        } else {
            stepBacks[0] = 0;
            stepBacks[1] = 0;
        }
        if (blueShouldBack) {
            stepBacks[2] *= 2;
            stepBacks[3] *= 2;
        }

//        cout << nextY << nextX << "/" << nextY + stepBacks[0] << nextX + stepBacks[1] << endl;
//        cout << "(" << nextY << nextX << nextBy << nextBx << ")" << endl;

        if(isSuccess) {
            nextSteps.push_back(new Coord(0, 0, 0, 0, count+1, true));
            continue;
        }
        Coord *nextStepCandidate = new Coord(
                nextY + stepBacks[0],
                nextX + stepBacks[1],
                nextBy + stepBacks[2],
                nextBx + stepBacks[3],
                count + 1,
                isSuccess
        );
        if (nextStepCandidate->y == curPos->y &&
            nextStepCandidate->x == curPos->x &&
            nextStepCandidate->By == curPos->By &&
            nextStepCandidate->Bx == curPos->Bx)
            continue;
//        if(nextY == 4 && nextX == 3 && nextBy == 5 && nextBx == 2) {
//            cout << "hawi" << endl;
//        }
        nextSteps.push_back(nextStepCandidate);
        isVisited[nextStepCandidate->y][nextStepCandidate->x][nextStepCandidate->By][nextStepCandidate->Bx] = 1;
    }

    return nextSteps;
}

int solution(vector<string> mapVector) {
    int minCount = 0;
    rowSize = mapVector.size();
    colSize = mapVector[0].size();
//    cout << rowSize << " " << colSize << endl;
//    for (int i = 0; i < rowSize; i++) {
//        for (int j = 0; j < colSize; j++) {
//            cout << mapVector[i][j];
//        }
//        cout << endl;
//    }

    Coord *goal;
    Coord *curPos = new Coord();
    curPos->count = 0;
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (mapVector[i][j] == 'R') {
                curPos->y = i;
                curPos->x = j;
                map[i][j] = '.';
                continue;
            }
            if (mapVector[i][j] == 'B') {
                curPos->By = i;
                curPos->Bx = j;
                map[i][j] = '.';
                continue;
            }
            map[i][j] = mapVector[i][j];
        }
    }
    bfsQ.push(curPos);

    while (!bfsQ.empty()) {
        curPos = bfsQ.front();
        bfsQ.pop();
//        cout << curPos->y << curPos->x << ", " << curPos->By << curPos->Bx << ", " << curPos->count << endl;
//        cout << "Goal Visited?: " << isVisited[4][4][5][1] << endl;
        vector<Coord *> nextSteps = findNextSteps(curPos);
//        cout << nextSteps.size() << endl;
        for (auto nextStep : nextSteps) {
//            cout << nextStep->y << nextStep->x << ", " << nextStep->By << nextStep->Bx << ", " << nextStep->count << endl;
            if (nextStep->isSuccess) return nextStep->count;
            bfsQ.push(nextStep);
        }
//        cout << "==========" << endl;
    }

    return -1;
}