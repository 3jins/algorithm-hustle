#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int v, e;
int isVisited[101];
vector<pair<int, int>> edges;
queue<int> bfsQ;

/* test */
void printIsVisited() {
    for(int i=1; i<= v; i++) {
        cout << isVisited[i] << " ";
    }
    cout << endl;
}

void getInputs() {
    cin >> v;
    cin >> e;

    for (int i = 0; i < e; i++) {
        pair<int, int> edge;
        cin >> edge.first >> edge.second;
        edges.emplace_back(edge);
    }
    for (int i = 1; i <= v; i++) {
        isVisited[i] = 0;
    }
}

vector<int> getNearNodes(int v) {
    vector<int> nearNodes;
    for (auto edge : edges) {
        if (edge.first == v) {
            nearNodes.emplace_back(edge.second);
        } else if (edge.second == v) {
            nearNodes.emplace_back(edge.first);
        }
    }
    return nearNodes;
}

int bfs() {
    getInputs();

    bfsQ.push(1);
    isVisited[1] = 1;
    int count = 0;

    while (!bfsQ.empty()) {
        int curCom = bfsQ.front();
        bfsQ.pop();
        vector<int> nearNodes = getNearNodes(curCom);
        for (auto node : nearNodes) {
            if (isVisited[node] == 0) {
                bfsQ.push(node);
                isVisited[node] = 1;
                count++;
            }
        }
    }

    return count;
}

void printNumInfected() {
    cout << bfs() << endl;
}