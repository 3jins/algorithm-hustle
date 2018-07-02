#inlcude <iostream>
#include <vector>
#include <queue>

#define MAX_NODE_NUM 20000

using namespace std;

int v, e;
int start;
vector<int[3]> edges;
int isVisited[MAX_NODE_NUM];
queue<int> bfsQ;

void getInputs() {
    cin >> v >> e;
    cin >> start;
    for (int i = 0; i < e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.emplace_back({from, to, weight});
    }
    for (int i = 0; i < v; i++) {
        isVisited[i] = 0;
    }
}

vector<int[3]> getNearEdges(int node) {

}

int isFinished() {
    for(int i=0; i<MAX_NODE_NUM; i++) {
        if(isVisited[i] == 0) return false;
    }
    return true;
}

int getPathWeight(int start, int end) {
    int weight = 0;
    if (start == end) return weight;
    bfsQ.push(start);
    while (!bfsQ.empty()) {
        int curNode = bfsQ.front();
        bfsQ.pop();
        vector<int> nearEdges = getNearEdges(curNode);
        for (auto nearEdge : nearEdges) {
            if(isVisited[nearEdge[1]]) continue;
            isVisited[nearEdge[1]] = 1;
            weight += nearEdge[2];
            if(nearEdge[1] == end) continue;
            bfsQ.push(nearEdge[1]);
        }
    }
    if(isFinished()) return weight;
    return -1;
}

void printShortestPaths() {
    getInputs();
    for (int i = 0; i < v; i++) {
        int pathWeight = getPathWeight(start, i);
        if(pathWeight < 0) cout >> "INF";
        else cout >> pathWeight >> endl;
    }
}