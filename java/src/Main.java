import kakao.recruitment2019.FailureRate;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] numStageList = {
                5, 4, 3, 5
        };
        int[][] stagesList = {
                {2, 1, 2, 6, 2, 4, 3, 3},
                {4, 4, 4, 4, 4},
                {4, 4, 4, 4, 4},
                {4, 4, 4, 4, 4},
        };
        int[][] answerList = {
                {3, 4, 2, 1, 5},
                {4, 1, 2, 3},
                {1, 2, 3},
                {4, 1, 2, 3, 5},
        };

        int numTc = numStageList.length;
        for (int tc = 0; tc < numTc; tc++) {
            int[] result = (new FailureRate()).getStagesArrangedByFailureRate(numStageList[tc], stagesList[tc]);
            boolean testResult = Arrays.equals(answerList[tc], result);
            if (!testResult) {
                System.out.println(Arrays.toString(result));
            } else {
                System.out.println("pass");
            }
        }
    }
}