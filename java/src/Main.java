import kakao.recruitment2019.CandidateKey;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        String[][][] relations = {
                {
                        {"100", "ryan", "music", "2"},
                        {"200", "apeach", "math", "2"},
                        {"300", "tube", "computer", "3"},
                        {"400", "con", "computer", "4"},
                        {"500", "muzi", "music", "3"},
                        {"600", "apeach", "music", "2"}
                },
        };
        int[] answerList = {
                2,
        };

        int numTc = relations.length;
        for (int tc = 0; tc < numTc; tc++) {
            int result = (new CandidateKey()).getNumCandidateKeys(relations[tc]);
            boolean testResult = answerList[tc] == result;
            if (!testResult) {
                System.out.println(result);
            } else {
                System.out.println("pass");
            }
        }
    }
}