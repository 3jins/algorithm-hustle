package baekjoon.acmicpc.regional;

import java.util.Collections;
import java.util.Scanner;

public class SumOfSqareNumbers1699 {
    private final int MAX_N = 100000;
    public SumOfSqareNumbers1699() {
        int n = (new Scanner(System.in)).nextInt();
        System.out.println(getAnswer(n));
    }

    private int getAnswer(int n) {
        int[] dp = new int[MAX_N + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = MAX_N;
            int maxSqrt = (int) Math.sqrt(i);
            for (int j = 1; j <= maxSqrt; j++) {
                int square = j * j;
                dp[i] = Math.min(dp[i], dp[i - square] + 1);
            }
        }

        return dp[n];
    }
}
