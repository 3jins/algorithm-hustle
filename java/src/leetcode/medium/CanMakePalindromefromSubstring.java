package leetcode.medium;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CanMakePalindromefromSubstring {
    public CanMakePalindromefromSubstring() {
        String[] tc1 = {
                "abcda",
                "zzzzz",
                "uuhnhu",
                "abcdec",
                "pqtadspgvinafefk",
        };
        int[][][] tc2 = {
                {{3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}},
                {{0, 2, 5}},
                {{0, 5, 1}},
                {{0, 5, 1}, {0, 5, 2}},
                {{1, 14, 5}},
        };
        boolean[][] expectations = {
                {true, false, false, true, true},
                {true},
                {true},
                {false, true},
                {true},
        };
        for (int i = 0; i < expectations.length; i++) {
            String result = canMakePaliQueries(tc1[i], tc2[i]).toString();
            boolean isPass = (result.equals(Arrays.toString(expectations[i])));
            System.out.println(isPass ? "pass" : result);
        }
    }

    private List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        List<Boolean> resultList = new ArrayList<>();
        int strLen = s.length();
        int[][] prefixSums = new int[strLen + 1][26];
        for (int i = 1; i <= strLen; i++) {
            for (int j = 0; j < 26; j++) {
                prefixSums[i][j] = prefixSums[i - 1][j];
            }
            prefixSums[i][s.charAt(i - 1) - 'a']++;
        }

        for (int[] query : queries) {
            int numOdds = 0;
            for (int i = 0; i < 26; i++) {
                int freq = prefixSums[query[1] + 1][i] - prefixSums[query[0]][i];
                numOdds += (freq % 2);
            }
            if ((query[1] - query[0] + 1) % 2 == 1) numOdds--;
            if (numOdds / 2 <= query[2]) {
                resultList.add(true);
            } else {
                resultList.add(false);
            }
        }
        return resultList;
    }
}
