#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX_ROW 1000
#define MAX_COL 1000

using namespace std;

struct tomato {
    int row;
    int col;
    int day;
};

int width, height;
struct tomato map[MAX_ROW][MAX_COL];

/* for test */
void printMap() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << map[i][j].day << " ";
        }
        cout << endl;
    }
}

int getMax() {
    int result = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j].day > result) {
                result = map[i][j].day;
            }
        }
    }
    return result;
}

vector<queue<struct tomato>> findMaturedApples() {
    vector<queue<struct tomato>> maturedApples;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j].day >= 1) {
                queue<struct tomato> newQueue;
                newQueue.push(map[i][j]);
                maturedApples.emplace_back(newQueue);
            }
        }
    }

    return maturedApples;
}

vector<struct tomato> getNearTomatos(struct tomato currentTomato) {
    vector<struct tomato> nearTomatos;
    int diffRow[] = {-1, 1, 0, 0};
    int diffCol[] = {0, 0, -1, 1};
//    cout << currentTomato.first << " " << currentTomato.second << endl;
//    cout << map[currentTomato.first + 1][currentTomato.second] << endl;
    for(int i=0; i<4; i++) {
        if(currentTomato.row + diffRow[i] < 0 || currentTomato.row + diffRow[i] >= height || currentTomato.col + diffCol[i] < 0 || currentTomato.col + diffCol[i] >= width) continue;
        if (currentTomato.day > 0 && map[currentTomato.row + diffRow[i]][currentTomato.col + diffCol[i]].day >= 0) {
            struct tomato nearTomato = {
                currentTomato.row + diffRow[i],
                currentTomato.col + diffCol[i],
                map[currentTomato.row + diffRow[i]][currentTomato.col + diffCol[i]].day,
            };
            nearTomatos.emplace_back(nearTomato);
        }
    }

    return nearTomatos;
}

int isSuccess() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j].day == 0) {
                return false;
            }
        }
    }
    return true;
}

int getMatureTime() {
    vector<queue<struct tomato>> bfsQueues = findMaturedApples();

    for(auto queue : bfsQueues) {
        while(!queue.empty()) {
            printMap();
            cout << "---" << endl;
            struct tomato curTomato = queue.front();
            queue.pop();

            vector<struct tomato> nearTomatos = getNearTomatos(curTomato);
            for (auto nearTomato : nearTomatos) {
//                cout << nearTomato.day << " ";
                if (nearTomato.day < 0) continue;
                else if(nearTomato.day >= curTomato.day) continue;
                else {
//                    cout << "fuckin" << endl;
//                    cout << nearTomato.col << " " << nearTomato.row << endl;
                    nearTomato.day = curTomato.day + 1;
                    queue.push(nearTomato);
                    map[nearTomato.col][nearTomato.row] = nearTomato;
                }
            }
        }
    }

    if(isSuccess()) {
        return getMax();
    }
    return -1;
}

void getInputs() {
    int tmp;
    cin >> width >> height;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> tmp;
            struct tomato mato = {
                i,
                j,
                tmp,
            };
            map[i][j] = mato;
        }
    }
}

void printMatureTime() {
    getInputs();
    if (isSuccess()) {
        cout << 0 << endl;
    }
    cout << getMatureTime() << endl;
}