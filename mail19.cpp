#include <iostream>
#include <vector>
#include "vector_util.h"

using namespace std;

vector<vector<int>> isVisited;
vector<int> result;

bool canGo(int x, int y, int w, int h) {
    if(x < 0 || x >= w) return false;
    if(y < 0 || y >= h) return false;
    if(isVisited[y][x]) return false;
    return true;
}

void visit(int x, int y, vector<vector<int>> v) {
    isVisited[y][x] = 1;
    result.emplace_back(v[y][x]);
}

void printClockwiseCenterward(vector<vector<int>> v) {
    int h = v.size();
    int w = v[0].size();
    int size = h * w;
    int x = 0;
    int y = 0;
    int stepsX[4] = {1, 0, -1, 0};
    int stepsY[4] = {0, 1, 0, -1};

    isVisited = init2WdVector(isVisited, w, h);

    visit(0, 0, v);
    for(int i=1; i<size; i++) {
        for(int j=0; j<4; j++) {
            if(canGo(x + stepsX[j], y + stepsY[j], w, h)) {
                visit(x + stepsX[j], y + stepsY[j], v);
                x += stepsX[j];
                y += stepsY[j];
                break;
            }
        }
    }

    printVector(result, " ");
}

/* 17:45~ 18:14
 *
 * [실수들]
 * 1. 이차원벡터 초기화가 익숙하지 않았다. tmp vector를 만들어서 초기화해야 한다.
 *  -> 그래서 vector_util.h 안에 유틸함수로 만들어버렸다.
 * 2. 여러 선택지를 순서대로 보다가 조건 맞으면 그리로 쌩 가버리는 경우는 break. BFS는 유사하지만 다시 돌아올 것이라 break 아님.
 *  -> ex) 우하좌상을 순서대로 살피다가 조건 맞을 때 그리로 한 칸 옮기는 경우.
 */
