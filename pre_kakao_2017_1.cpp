#include <vector>
#include <queue>

#define NUM_DIRECTIONS 4

using namespace std;

class Node {
public:
    int x;
    int y;

    Node(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

vector<vector<int>> map;
vector<vector<int>> isUnvisited;
int mapSizeX, mapSizeY;
queue<Node *> bfsQ;
int curArea = 1;

bool isSameColor(Node *candidate, int color) {
    if (candidate->x < 0 || candidate->y < 0) return false;
    if (candidate->x >= mapSizeX || candidate->y >= mapSizeY) return false;
    if (map[candidate->y][candidate->x] != color) return false;
    return true;
}

vector<Node *> findNeighbors(Node *node) {
    vector<Node *> neighbors;
    int stepX[NUM_DIRECTIONS] = {1, 0, -1, 0};
    int stepY[NUM_DIRECTIONS] = {0, 1, 0, -1};

    int color = map[node->y][node->x];
    for (int i = 0; i < NUM_DIRECTIONS; i++) {
        Node *candidate = new Node(
                node->x + stepX[i],
                node->y + stepY[i]
        );
        if (isSameColor(candidate, color)) {
            neighbors.emplace_back(candidate);
        }
    }

    return neighbors;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int numArea = 0;
    int maxArea = 0;

    map = picture;
    isUnvisited = picture;
    mapSizeY = m;
    mapSizeX = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isUnvisited[i][j]) {
                Node *curNode = new Node(j, i);
                isUnvisited[curNode->y][curNode->x] = 0;
//                cout << "[" << i << ", " << j << "]" << endl;
                while (true) {
//                    cout << curNode->y << " " << curNode->x << " " << map[curNode->y][curNode->x] << " " << isUnvisited[curNode->y][curNode->x] << endl;
                    vector<Node *> neighbors = findNeighbors(curNode);
                    for (auto neighbor : neighbors) {
                        if (isUnvisited[neighbor->y][neighbor->x]) {
//                            cout << neighbor->y << ", " << neighbor->x << endl;
                            bfsQ.push(neighbor);
                            isUnvisited[neighbor->y][neighbor->x] = 0;
                            curArea++;
                        }
                    }
                    if (bfsQ.empty()) break;
                    curNode = bfsQ.front();
                    bfsQ.pop();
                }
//                cout << "===" << endl;
                if (maxArea < curArea) {
                    maxArea = curArea;
                }
                curArea = 1;
                numArea++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = numArea;
    answer[1] = maxArea;
    return answer;
}