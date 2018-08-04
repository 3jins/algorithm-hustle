#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> data) {
    int minX = 0;
    int minY = 0;
    int maxX = 0;
    int maxY = 0;
    vector<vector<int>>::iterator iter1;
    vector<vector<int>>::iterator iter2;

    for (iter1 = data.begin(); iter1 != data.end(); iter1++) {
        int x = iter1->back();
        int y = iter1->front();
        if (minX > x) minX = x;
        if (maxX < x) maxX = x;
        if (minY > y) minY = y;
        if (maxY < y) maxY = y;
    }

    int map[maxY + 1][maxX + 1];
    for (int i = 0; i <= maxY; i++) {
        for (int j = 0; j <= maxX; j++) {
            map[i][j] = 0;
        }
    }
    for (iter1 = data.begin(); iter1 != data.end(); iter1++) {
        int x = iter1->back();
        int y = iter1->front();
        map[y][x] = 1;
    }

    int partialSum[maxY + 1][maxX + 1];
    partialSum[0][0] = map[0][0];
    for (int i = 1; i <= maxX; i++) {
        partialSum[0][i] = partialSum[0][i - 1] + map[0][i];
    }
    for (int i = 1; i <= maxY; i++) {
        for (int j = 0; j <= maxX; j++) {
            if (j == 0) {
                partialSum[i][j] = partialSum[i - 1][j] + map[i][j];
                continue;
            }
            // It's not unreachable. Fuck you, Jetbrain.
            partialSum[i][j] = (partialSum[i - 1][j] + partialSum[i][j - 1] - partialSum[i - 1][j - 1]) + map[i][j];
        }
    }

    int count = 0;
    vector<vector<int>> alreadyPassed;
    for (iter1 = data.begin(); iter1 != data.end(); iter1++) {
        int x1 = iter1->back();
        int y1 = iter1->front();
        for (iter2 = iter1 + 1; iter2 != data.end(); iter2++) {
            int x2 = iter2->back();
            int y2 = iter2->front();

            int bigY = max(y1, y2);
            int smallY = min(y1, y2);
            int bigX = max(x1, x2);
            int smallX = min(x1, x2);

            /* duplication check */
            bool isDuplicated = false;
            vector<vector<int>>::iterator iter3;
            for (iter3 = alreadyPassed.begin(); iter3 != alreadyPassed.end(); iter3++) {
                vector<int> v = *iter3;
                if (v[0] != bigY) continue;
                if (v[1] != smallY) continue;
                if (v[2] != bigX) continue;
                if (v[3] != smallX) continue;
                isDuplicated = true;
                break;
            }
            if (isDuplicated) continue;

            if (y1 == y2 || x1 == x2) continue;
            if (bigY - smallY == 1 || bigX - smallX == 1) {
                count++;
                alreadyPassed.emplace_back(vector<int>({bigY, smallY, bigX, smallX}));
                continue;
            }
            int start = partialSum[smallY + 1][smallX + 1] - max(partialSum[smallY][smallX + 1], partialSum[smallY + 1][smallX]);
            if(start > 0) continue;
            int end = partialSum[bigY - 1][bigX - 1] - max(partialSum[smallY][bigX - 1], partialSum[bigY - 1][smallX]);
            if(start != end) continue;
            count++;
            alreadyPassed.emplace_back(vector<int>({bigY, smallX, smallY, bigX}));
        }
    }

    return count;
}