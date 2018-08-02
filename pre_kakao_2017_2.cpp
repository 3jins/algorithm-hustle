#include <vector>

#define MOD 20170805

using namespace std;

int solution(int m, int n, vector<vector<int>> cityMap) {
    int pascalMap[m + 1][n + 1][2];
    for (int i = 0; i <= m; i++) {
        pascalMap[i][0][0] = 0;
        pascalMap[i][0][1] = 0;
    }
    for (int i = 0; i <= n; i++) {
        pascalMap[0][i][0] = 0;
        pascalMap[0][i][1] = 0;
    }
    pascalMap[1][1][0] = 1;
    pascalMap[1][1][1] = 1;

    int limit = min(m, n);
    for (int i = 1; i <= limit; i++) {
        for (int j = i; j <= n; j++) {
//            cout << i << " " << j << endl;
            if (i == 1 && j == 1) continue;
            int fromLeft = pascalMap[i][j - 1][0];
            int fromUp = pascalMap[i - 1][j][1];
            switch (cityMap[i - 1][j - 1]) {
                case 0:
                    pascalMap[i][j][0] = (fromLeft + fromUp) % MOD;
                    pascalMap[i][j][1] = (fromLeft + fromUp) % MOD;
                    break;
                case 1:
                    pascalMap[i][j][0] = 0;
                    pascalMap[i][j][1] = 0;
                    break;
                case 2:
                    pascalMap[i][j][0] = fromLeft;
                    pascalMap[i][j][1] = fromUp;
                    break;
            }
//            cout << fromLeft << ", " << fromUp << " / " << pascalMap[i][j][0] << ", " << pascalMap[i][j][1] << endl;
        }
        for (int j = i; j <= m; j++) {
//            cout << j << " " << i << endl;
            if (i == 1 && j == 1) continue;
            int fromLeft = pascalMap[j][i - 1][0];
            int fromUp = pascalMap[j - 1][i][1];
            switch (cityMap[j - 1][i - 1]) {
                case 0:
                    pascalMap[j][i][0] = (fromLeft + fromUp) % MOD;
                    pascalMap[j][i][1] = (fromLeft + fromUp) % MOD;
                    break;
                case 1:
                    pascalMap[j][i][0] = 0;
                    pascalMap[j][i][1] = 0;
                    break;
                case 2:
                    pascalMap[j][i][0] = fromLeft;
                    pascalMap[j][i][1] = fromUp;
                    break;
            }
//            cout << fromLeft << ", " << fromUp << " / " << pascalMap[i][j][0] << ", " << pascalMap[i][j][1] << endl;
        }
    }

    return pascalMap[m][n][0] % MOD;
}