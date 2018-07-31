#include <string>
#include <vector>

#define DIVISOR 1234567
#define MAXN 2000

using namespace std;

int solution(int n) {
    if (n <= 2) return n;
    int dp[MAXN] = {1, 2};
    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIVISOR;
    }
    return dp[n - 1];
}