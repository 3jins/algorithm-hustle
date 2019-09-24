package programmers.level2;

import java.util.Arrays;

public class MakingBigNumber {
    public String solution(String number, int k) {
        StringBuilder biggest = new StringBuilder();
        int dataSize = number.length();
        int nextIdx = 0;
        int windowSize = k + 1; // dataSize - (dataSize - k - 1)
        while (biggest.length() < dataSize - k) {
            char[] sorted = number.substring(nextIdx, nextIdx + windowSize).toCharArray();
            Arrays.sort(sorted);
            biggest.append(sorted[windowSize - 1]);
            int idx = number.indexOf(sorted[windowSize - 1], nextIdx) - nextIdx;
            nextIdx += (idx + 1);
            windowSize = windowSize - idx;
        }
        return biggest.toString();
    }
}
