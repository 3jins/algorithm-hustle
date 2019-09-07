import kakao.recruitment2020.OddLock;

import java.util.Arrays;

public class Main {
    // 1. DataCompression
    // public static void main(String[] args) {
    //     String[] param1List = {
    //             "aabbaccc",
    //             "ababcdcdababcdcd",
    //             "xababcdcdababcdcd",
    //             "abcabcabcabcdededededede",
    //             "abcabcdede",
    //     };
    //     int[] answerList = {
    //             7,
    //             9,
    //             17,
    //             14,
    //             8,
    //     };
    //
    //     int numTc = answerList.length;
    //     for (int tc = 0; tc < numTc; tc++) {
    //         System.out.println("------------------------");
    //         System.out.println(param1List[tc]);
    //         System.out.println("------------------------");
    //         int result = (new DataCompression()).solution(param1List[tc]);
    //         boolean testResult = answerList[tc] == result;
    //         if (!testResult) {
    //             System.out.println(result);
    //         } else {
    //             System.out.println("pass");
    //         }
    //     }
    // }

    // 2. ParenthesisCorrection
    // public static void main(String[] args) {
    //     String[] param1List = {
    //             "(()())()",
    //             ")(",
    //             "()))((()",
    //     };
    //     String[] answerList = {
    //             "(()())()",
    //             "()",
    //             "()(())()",
    //     };
    //
    //     int numTc = answerList.length;
    //     for (int tc = 0; tc < numTc; tc++) {
    //         System.out.println("------------------------");
    //         System.out.println(param1List[tc]);
    //         System.out.println("------------------------");
    //         String result = (new ParenthesisCorrection()).solution(param1List[tc]);
    //         boolean testResult = answerList[tc].equals(result);
    //         if (!testResult) {
    //             System.out.println(result);
    //         } else {
    //             System.out.println("pass");
    //         }
    //     }
    // }

    // 3. OddLock
    public static void main(String[] args) {
        int[][][] param1List = { // key
                {
                        {0, 0, 0},
                        {1, 0, 0},
                        {0, 1, 1},
                },
                // {
                //         {0, 1, 0},
                //         {1, 0, 1},
                //         {0, 1, 0},
                // },
                // {
                //         {0, 1, 0},
                //         {1, 0, 1},
                //         {0, 1, 0},
                // },
                // {
                //         {0, 0, 0},
                //         {0, 0, 0},
                //         {0, 0, 1},
                // },
                // {
                //         {0, 0, 0},
                //         {0, 0, 0},
                //         {1, 1, 1},
                // },
        };
        int[][][] param2List = { // lock
                {
                        {1, 1, 1},
                        {1, 1, 0},
                        {1, 0, 1},
                },
                // {
                //         {1, 0, 1},
                //         {0, 1, 0},
                //         {1, 0, 1},
                // },
                // {
                //         {1, 0, 1},
                //         {0, 1, 1},
                //         {1, 0, 1},
                // },
                // {
                //         {1, 1, 1},
                //         {1, 1, 1},
                //         {1, 1, 1},
                // },
                // {
                //         {1, 1, 1},
                //         {1, 0, 1},
                //         {1, 1, 1},
                // },
        };
        boolean[] answerList = { // lock
                true,
                // true,
                // false,
                // false,
                // false,
        };

        int numTc = answerList.length;
        for (int tc = 0; tc < numTc; tc++) {
            // System.out.println("------------------------");
            // System.out.println(Arrays.deepToString(param1List[tc]));
            // System.out.println("------------------------");
            boolean result = (new OddLock()).solution(param1List[tc], param2List[tc]);
            boolean testResult = answerList[tc] == result;
            if (!testResult) {
                System.out.println(result);
            } else {
                System.out.println("pass");
            }
        }
    }
}
