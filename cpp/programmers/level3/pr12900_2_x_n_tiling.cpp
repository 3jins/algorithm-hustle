#include <vector>

#define DIVIDER 1000000007
using namespace std;

int solution(int n) {
    vector<int> dp = {1, 2};
    for(int i=2; i<n; i++) {
        dp.emplace_back((dp[i - 1] + dp[i - 2]) % DIVIDER);
    }
    return dp[n - 1];
}