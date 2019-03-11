#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int width, height;
vector<vector<int>> map;
int numUnmatured = 0;

/* for test */
void printMap() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int getMax() {
    int result = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] > result) {
                result = map[i][j];
            }
        }
    }
    return result;
}

vector<pair<int, int>> findMaturedApples() {
    vector<pair<int, int>> maturedApples;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 1) {
                maturedApples.emplace_back(make_pair(i, j));
//                cout << i << " " << j << endl;
            }
        }
    }

    return maturedApples;
}

vector<pair<int, int>> getNearCoords(pair<int, int> currentCoord) {
    vector<pair<int, int>> nearCoords;
//    cout << currentCoord.first << " " << currentCoord.second << endl;
//    cout << map[currentCoord.first + 1][currentCoord.second] << endl;
    if (currentCoord.first > 0 && map[currentCoord.first - 1][currentCoord.second] >= 0) {
        nearCoords.emplace_back(make_pair(currentCoord.first - 1, currentCoord.second));
    }
    if (currentCoord.first < height - 1 && map[currentCoord.first + 1][currentCoord.second] >= 0) {
        nearCoords.emplace_back(make_pair(currentCoord.first + 1, currentCoord.second));
    }
    if (currentCoord.second > 0 && map[currentCoord.first][currentCoord.second - 1] >= 0) {
        nearCoords.emplace_back(make_pair(currentCoord.first, currentCoord.second - 1));
    }
    if (currentCoord.second < width - 1 && map[currentCoord.first][currentCoord.second + 1] >= 0) {
        nearCoords.emplace_back(make_pair(currentCoord.first, currentCoord.second + 1));
    }

    return nearCoords;
}

int isSuccess() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int getMatureTime() {
    vector<pair<int, int>> maturedApples = findMaturedApples();
    vector<queue<pair<int, int>>> bfsQueues;
    vector<int> counts;
    for (maturedApple : maturedApples) {
        queue<pair<int, int>> tmp;
        tmp.push(maturedApple);
        bfsQueues.emplace_back(tmp);

//        bfsQueues.emplace_back(new queue<pair<int, int>>());
//        bfsQueues[count++].push(maturedApple);
    }

    for (queue<pair<int, int>> bfs : bfsQueues) {
        int count = 0;
        int localNumUnmatured = numUnmatured;
        while (localNumUnmatured > 0) {
            vector<pair<int, int>> nearCoords;
            count++;
            int prevLocalNumUnmatured = localNumUnmatured;
//            printMap();
//            cout << "-------" << endl;
            while (!bfs.empty()) {
                pair<int, int> currentMaturedApple = bfs.front();
                bfs.pop();
                vector<pair<int, int>> newNearCoords = getNearCoords(currentMaturedApple);
                nearCoords.insert(nearCoords.end(), newNearCoords.begin(), newNearCoords.end());
            }
            for (nearCoord : nearCoords) {
//                cout << nearCoord.first << " " << nearCoord.second << endl;
//                cout << map[nearCoord.first][nearCoord.second] << endl;
                if (map[nearCoord.first][nearCoord.second] == 0) {
//                    cout << "you should come here" << endl;
//                    cout << nearCoord.first << " " << nearCoord.second << endl;
                    map[nearCoord.first][nearCoord.second] = count;
                    bfs.push(nearCoord);
                    localNumUnmatured--;
                } else if (map[nearCoord.first][nearCoord.second] > 0) {
                    if (count < map[nearCoord.first][nearCoord.second]) {
                        map[nearCoord.first][nearCoord.second] = count;
                        bfs.push(nearCoord);
                        localNumUnmatured--;
                    }
                }
            }
            if (prevLocalNumUnmatured == localNumUnmatured) {
                if (isSuccess()) {
                    break;
                } else {
                    return -1;
                }
            }
        }
    }
    return getMax();
}

void getInputs() {
    int tmp;
    cin >> width >> height;
    for (int i = 0; i < height; i++) {
        vector<int> newLine;
        for (int j = 0; j < width; j++) {
            cin >> tmp;
            if (tmp == 0) numUnmatured++;
            newLine.emplace_back(tmp);
        }
        map.emplace_back(newLine);
    }
}

void printMatureTime() {
    getInputs();
    if (numUnmatured == 0) {
        cout << 0 << endl;
    } else {
        cout << getMatureTime() << endl;
    }
}