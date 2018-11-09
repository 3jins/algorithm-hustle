#include <iostream>
#include <vector>

int getFibonacci(int n) {
    /* exception handling */
    if (n < 1) {
        cout << "삐빅! 관종입니다!" << endl;
        return -1;
    }

    /* DP */
    vector<int> dp = {1, 1};
    for (int i = 2; i < n; i++) {
        dp.push_back(dp[i - 1] + dp[i - 2]);
    }
    return dp[n - 1];   // 예외처리는 생략한다!
}