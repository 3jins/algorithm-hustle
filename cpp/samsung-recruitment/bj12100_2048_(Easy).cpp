// 07:40 ~ 08:16 + 디버깅(∞)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int boardSize = 0;

void printBoard(vector<vector<int>> board) {
    for (int i = 1; i <= boardSize; i++) {
        for (int j = 1; j <= boardSize; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

int getLargest(vector<vector<int>> board) {
    int max = 0;
    for (int i = 1; i <= boardSize; i++) {
        for (int j = 1; j <= boardSize; j++) {
            if (max < board[i][j]) max = board[i][j];
        }
    }
    return max;
}

vector<vector<int>> fillSpace(vector<vector<int>> board, int direction) {
    pair<int, int> zeroPoint;
    bool findingZero = true;
    switch (direction) {
        case 0: // right
            for (int i = 1; i <= boardSize; i++) {
                for (int j = boardSize; j >= 1; j--) {
                    if (!findingZero && board[i][j] != 0) {
                        board[zeroPoint.first][zeroPoint.second] = board[i][j];
                        board[i][j] = 0;
                        findingZero = true;
                        j = zeroPoint.second;
                    }
                    if (findingZero && board[i][j] == 0) {
                        zeroPoint = {i, j};
                        findingZero = false;
                    }
                }
                findingZero = true;
            }
            break;
        case 1: // down
            for (int j = 1; j <= boardSize; j++) {
                for (int i = boardSize; i >= 1; i--) {
                    if (!findingZero && board[i][j] != 0) {
                        board[zeroPoint.first][zeroPoint.second] = board[i][j];
                        board[i][j] = 0;
                        findingZero = true;
                        i = zeroPoint.first;
                    }
                    if (findingZero && board[i][j] == 0) {
                        zeroPoint = {i, j};
                        findingZero = false;
                    }
                }
                findingZero = true;
            }
            break;
        case 2: // left
            for (int i = 1; i <= boardSize; i++) {
                for (int j = 1; j <= boardSize; j++) {
                    if (!findingZero && board[i][j] != 0) {
                        board[zeroPoint.first][zeroPoint.second] = board[i][j];
                        board[i][j] = 0;
                        findingZero = true;
                        j = zeroPoint.second;
                    }
                    if (findingZero && board[i][j] == 0) {
                        zeroPoint = {i, j};
                        findingZero = false;
                    }
                }
                findingZero = true;
            }
            break;
        case 3: // up
            for (int j = 1; j <= boardSize; j++) {
                for (int i = 1; i <= boardSize; i++) {
                    if (!findingZero && board[i][j] != 0) {
                        board[zeroPoint.first][zeroPoint.second] = board[i][j];
                        board[i][j] = 0;
                        findingZero = true;
                        i = zeroPoint.first;
                    }
                    if (findingZero && board[i][j] == 0) {
                        zeroPoint = {i, j};
                        findingZero = false;
                    }
                }
                findingZero = true;
            }
            break;
        default:
            return board;
    }
    return board;
}

vector<vector<int>> move(vector<vector<int>> board, int direction) {
    int yStart[4] = {1, boardSize, 1, 1};
    int xStart[4] = {boardSize, 1, 1, 1};
    int yEnd[4] = {boardSize + 1, 0, boardSize + 1, boardSize + 1};
    int xEnd[4] = {0, boardSize + 1, boardSize + 1, boardSize + 1};
    int yIter[4] = {1, -1, 1, 1};
    int xIter[4] = {-1, 1, 1, 1};
    int yMove[4] = {0, -1, 0, 1};
    int xMove[4] = {-1, 0, 1, 0};

    board = fillSpace(board, direction);
    for (int i = yStart[direction]; i != yEnd[direction]; i += yIter[direction]) {
        for (int j = xStart[direction]; j != xEnd[direction]; j += xIter[direction]) {
            if (board[i][j] == board[i + yMove[direction]][j + xMove[direction]]) {
                board[i][j] *= 2;
                board[i + yMove[direction]][j + xMove[direction]] = 0;
            }
        }
    }

    return fillSpace(board, direction);
}

int recursiveMove(int count, vector<vector<int>> board) {
    if (count == 5) return getLargest(board);

    vector<int> maxCandidates;
    maxCandidates.push_back(getLargest(board));
    for (int i = 0; i < 4; i++) {
        vector<vector<int>> movedBoard = move(board, i);
        if (board == movedBoard) continue;
        maxCandidates.push_back(recursiveMove(count + 1, movedBoard));
    }
    return *max_element(maxCandidates.begin(), maxCandidates.end());
}

int solution(int _boardSize, vector<vector<int>> board) {
    boardSize = _boardSize;
//    return recursiveMove(0, board);

//    board = move(board, 0);
//    printBoard(board);
//    board = move(board, 3);
//    printBoard(board);
//    board = move(board, 1);
//    printBoard(board);
//    board = move(board, 0);
//    printBoard(board);
//    board = move(board, 1);
//    printBoard(board);
//    cout << getLargest(board) << endl;

    for (int i = 0; i < 4; i++) {
        vector<vector<int>> moved = move(board, i);
        printBoard(moved);
        for (int j = 0; j < 4; j++) {
            cout << j << endl;
            move(moved, j);
            printBoard(move(moved, j));
        }
        cout << "===================" << endl;
    }
    return 0;
}