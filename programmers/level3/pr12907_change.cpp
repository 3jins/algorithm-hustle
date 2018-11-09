#include <string>
#include <vector>
#include <algorithm>

#define DIVISOR 1000000007

using namespace std;

int solution(int n, vector<int> money) {
    int numMoneyUnit = money.size();
    int cases[numMoneyUnit][n + 1];

    for (int i = 0; i <= n; i++) {
        cases[0][i] = i % money[0] == 0;
    }
    for (int i = 1; i < numMoneyUnit; i++) {
        for (int j = 0; j <= n; j++) {
            cases[i][j] = cases[i - 1][j];
            if(money[i] <= j) {
                cases[i][j] += cases[i][j - money[i]];
            }
        }
    }

    return cases[numMoneyUnit - 1][n] % DIVISOR;
}