package programmers.level3;

import java.util.Arrays;

// 이걸 어떻게 생각하냐...;;
public class Scale {
    public int solution(int[] weights) {
        int numWeights = weights.length;
        if (numWeights == 0) return 1;
        Arrays.sort(weights);
        int sum = 0;
        for (int i = 0; i < numWeights; i++) {
            if (weights[i] > sum + 1) break;
            sum += weights[i];
        }
        return sum + 1;
    }
}
