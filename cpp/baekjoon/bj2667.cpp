#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 17:54 ~ 18:30

int map[25][25];
int size;
int isVisited[25][25];
queue<pair<int, int>> bfsQ;

/* test */
void printIsVisited() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << isVisited[i][j] << " ";
        }
        cout << endl;
    }
}

void getInputs() {
    cin >> size;
    for (int i = 0; i < size; i++) {
        char tmp[size];
        cin >> tmp;
        for (int j = 0; j < size; j++) {
            map[i][j] = tmp[j] - 48;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            isVisited[i][j] = 0;
        }
    }
}

int isValidCoord(int y, int x) {
    if (y < 0 || x < 0 || y >= size || x >= size) return false;
    if (map[y][x] == 0) return false;
    return true;
}

vector<pair<int, int>> getNearAPTs(pair<int, int> curAPT) {
    vector<pair<int, int>> nearAPTs;
    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        pair<int, int> nearAPT = make_pair(curAPT.first + dy[i], curAPT.second + dx[i]);
        if (isValidCoord(nearAPT.first, nearAPT.second)) {
            nearAPTs.emplace_back(nearAPT);
        }
    }

    return nearAPTs;
};

pair<int, int> findAPT() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (isVisited[i][j] == 1) continue;
            isVisited[i][j] = 1;
            if (map[i][j] == 1) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
};

void bfs() {
    getInputs();

    pair<int, int> startAPT = findAPT();
    int numGroups = 0;
    vector<int> counts;
    while (startAPT.first > -1) {
        numGroups++;
        counts.emplace_back(1);
        bfsQ.push(startAPT);
        while (!bfsQ.empty()) {
//            printIsVisited();
//            cout << "------" << endl;
            pair<int, int> curAPT = bfsQ.front();
            bfsQ.pop();
            vector<pair<int, int>> nearAPTs = getNearAPTs(curAPT);
            for (auto nearAPT : nearAPTs) {
                if (!isVisited[nearAPT.first][nearAPT.second]) {
                    bfsQ.push(nearAPT);
                    isVisited[nearAPT.first][nearAPT.second] = 1;
                    counts[numGroups - 1]++;
                }
            }
        }
        startAPT = findAPT();
    }

    cout << numGroups << endl;
    sort(counts.begin(), counts.end());
    for (auto count : counts) {
        cout << count << endl;
    }
}