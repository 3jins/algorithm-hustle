#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<pair<int, int>, int>> bfsQ;
vector<vector<int>> isVisited;

bool isVisitable(vector<vector<int>> map, pair<int, int> pos) {
    if (pos.first < 0) return false;
    if (pos.second < 0) return false;
    if (pos.first >= map.size()) return false;
    if (pos.second >= map[0].size()) return false;
    if (map[pos.first][pos.second] != 1) return false;
    return true;
}

vector<pair<pair<int, int>, int>> findNeighbors(vector<vector<int>> map, pair<pair<int, int>, int> curPos) {
    vector<pair<pair<int, int>, int>> neighbors;
    int numDirections = 4;
    int coordsY[numDirections] = {-1, 0, 0, 1};
    int coordsX[numDirections] = {0, -1, 1, 0};
    for (int i = 0; i < numDirections; i++) {
        pair<pair<int, int>, int> neighborCandidate = {
                {
                        curPos.first.first + coordsY[i],
                        curPos.first.second + coordsX[i]
                },
                curPos.second + 1
        };
        if (isVisitable(map, neighborCandidate.first)) {
            neighbors.emplace_back(neighborCandidate);
        }
    }
    return neighbors;
}

int isEnd(pair<int, int> curPos, pair<int, int> finish) {
    if (curPos == finish) return 1;
    return 0;
}

int getShortestDistance(vector<vector<int>> map, pair<int, int> start, pair<int, int> finish) {
    isVisited = map;
    pair<pair<int, int>, int> curPos = {{start.first, start.second}, 0};
    bfsQ.push(curPos);

    while (!bfsQ.empty()) {
        curPos = bfsQ.front();
        bfsQ.pop();
//        cout << curPos.first.first << curPos.first.second << endl;
        if(isEnd(curPos.first, finish)) {
            return curPos.second;
        }
        isVisited[curPos.first.first][curPos.first.second] = 0;
        vector<pair<pair<int, int>, int>> neighbors = findNeighbors(map, curPos);
        vector<pair<pair<int, int>, int>>::iterator neighbor;
        for (neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++) {
            pair<int, int> neighborPos = neighbor->first;
            if (isVisited[neighborPos.first][neighborPos.second] == 0) continue;
            bfsQ.push(*neighbor);
        }
    }

    return -1;
}
