// 08:42 ~ 10:59, fail - 틀렸다는데 이거 예외 뭐 어떻게 찾겠냐
#include <iostream>
#include <vector>
#include <queue>

#define MAX_BOARD_SIZE 20

using namespace std;

//int board[MAX_BOARD_SIZE + 2][MAX_BOARD_SIZE + 2];
int boardSize;

//void initBoard(vector<vector<int>> boardVec) {
//    for (int i = 0; i < boardSize + 2; i++) {
//        for (int j = 0; j < boardSize + 2; j++) {
//            if (i == 0 || j == 0 || i == boardSize + 1 || j == boardSize + 1)
//                board[i][j] = 0;
//            else
//                board[i][j] = boardVec[i - 1][j - 1];
//        }
//    }
//}

int getMaxBlock(vector<vector<int>> board) {
    int max = 0;
    for (int i = 1; i < boardSize + 1; i++) {
        for (int j = 1; j < boardSize + 1; j++) {
            if(max < board[i][j]) max = board[i][j];
        }
    }
    return max;
}

bool isSameBoard(vector<vector<int>> board1, vector<vector<int>> board2) {
    for (int i = 1; i < boardSize + 1; i++) {
        for (int j = 1; j < boardSize + 1; j++) {
            if(board1[i][j] != board2[i][j]) return false;
        }
    }
    return true;
}

vector<vector<int>> fillSpace(vector<vector<int>> board, int direction) {
    // 0: right, 1: down, 2: left, 3: up
    int yStarts[4] = {1, 1, 1, boardSize};
    int xStarts[4] = {boardSize, 1, 1, 1};
    int yIterSteps[4] = {1, 1, 1, -1};
    int xIterSteps[4] = {-1, 1, 1, 1};

    int zeroCoordY, zeroCoordX;
    int findingZero = true;
    if(direction % 2 == 0) {
        for (int i = yStarts[direction];
             i != boardSize + yStarts[direction] * yIterSteps[direction]; i += yIterSteps[direction]) {
            findingZero = true;
            for (int j = xStarts[direction];
                 j != boardSize + xStarts[direction] * xIterSteps[direction]; j += xIterSteps[direction]) {
//            cout << i << j;
                if (!findingZero && board[i][j] != 0) {
                    findingZero = true;
//                cout << i << j << board[i][j] << board[zeroCoordY][zeroCoordX] << endl;
                    board[zeroCoordY][zeroCoordX] = board[i][j];
                    board[i][j] = 0;
                }
                if (findingZero && board[i][j] == 0) {
                    findingZero = false;
                    zeroCoordY = i;
                    zeroCoordX = j;
//                cout << zeroCoordY << zeroCoordX << board[zeroCoordY][zeroCoordX] << endl;
                }
            }
//        cout << endl;
        }
//    cout << endl;
    } else {
        for (int j = xStarts[direction]; j != boardSize + xStarts[direction] * xIterSteps[direction]; j += xIterSteps[direction]) {
            findingZero = true;
            for (int i = yStarts[direction]; i != boardSize + yStarts[direction] * yIterSteps[direction]; i += yIterSteps[direction]) {
//            cout << i << j;
                if (!findingZero && board[i][j] != 0) {
                    findingZero = true;
//                cout << i << j << board[i][j] << board[zeroCoordY][zeroCoordX] << endl;
                    board[zeroCoordY][zeroCoordX] = board[i][j];
                    board[i][j] = 0;
                }
                if (findingZero && board[i][j] == 0) {
                    findingZero = false;
                    zeroCoordY = i;
                    zeroCoordX = j;
//                cout << zeroCoordY << zeroCoordX << board[zeroCoordY][zeroCoordX] << endl;
                }
            }
//        cout << endl;
        }
    }
    return board;
}

vector<vector<int>> move(vector<vector<int>> board, int direction) {
    // 0: right, 1: down, 2: left, 3: up
    int yStarts[4] = {1, 1, 1, boardSize};
    int xStarts[4] = {boardSize, 1, 1, 1};
    int yIterSteps[4] = {1, 1, 1, -1};
    int xIterSteps[4] = {-1, 1, 1, 1};
    int ySteps[4] = {0, 1, 0, -1};
    int xSteps[4] = {-1, 0, 1, 0};
//    for (int i = 0; i < boardSize + 2; i++) {
//        for (int j = 0; j < boardSize + 2; j++) {
//            cout << board[i][j];
//        }
//        cout << endl;
//    }

//    cout << direction << ", " << xStarts[direction] << endl;
    for (int i = yStarts[direction]; i != boardSize + yStarts[direction] * yIterSteps[direction]; i += yIterSteps[direction]) {
        for (int j = xStarts[direction]; j != boardSize + xStarts[direction] * xIterSteps[direction]; j += xIterSteps[direction]) {
            if (board[i][j] == board[i + ySteps[direction]][j + xSteps[direction]]) {
                board[i + ySteps[direction]][j + xSteps[direction]] = 0;
                board[i][j] *= 2;
            }
        }
//        cout << endl;
    }
//    cout << endl;

//    for(int i=0; i<boardSize + 2; i++) {
//        for(int j=0; j<boardSize + 2; j++) {
//            cout << board[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;

    board = fillSpace(board, direction);
    return board;
}

int solution(int _boardSize, vector<vector<int>> board) {
    int globalMax = 0;
    boardSize = _boardSize;

//    board = move(board, 0);
//    /////
//    for (int i = 0; i < boardSize + 2; i++) {
//        for (int j = 0; j < boardSize + 2; j++) {
//            cout << board[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
//    /////
//
//    board = move(board, 2);
//    /////
//    for (int i = 0; i < boardSize + 2; i++) {
//        for (int j = 0; j < boardSize + 2; j++) {
//            cout << board[i][j];
//        }
//        cout << endl;
//    }
//    cout << endl;
//    /////

    queue<pair<vector<vector<int>>, int>> bfsQ;
    bfsQ.push({board, 0});
    while(!bfsQ.empty()) {
        vector<vector<int>> curBoard = bfsQ.front().first;
        int count = bfsQ.front().second;
        bfsQ.pop();
        if(count > 5) continue;

//        /////
//        cout << count << endl;
//        for (int i = 0; i < boardSize + 2; i++) {
//            for (int j = 0; j < boardSize + 2; j++) {
//                cout << curBoard[i][j];
//            }
//            cout << endl;
//        }
//        cout << endl;
//        /////

        int localMax = getMaxBlock(curBoard);
        if(localMax > globalMax) globalMax = localMax;
        for(int i=0; i<4; i++) {
            vector<vector<int>> convertedBoard = move(curBoard, i);
            if(!isSameBoard(curBoard, convertedBoard)) {
                bfsQ.push({convertedBoard, count + 1});
            }
        }
    }

    return globalMax;
}