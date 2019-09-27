import programmers.level3.Rank;

public class Main {
    public static void main(String[] args) {
        int[] param1List = {
                5,
                // 5,
                // 5,
        };
        int[][][] param2List = {
                {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}},
                // {{1, 2}, {1, 5}, {2, 3}, {3, 4}},
                // {{1, 2}, {4, 5}, {2, 3}, {3, 4}},
        };
        int[] expectations = {
                2,
                // 1,
                // 5,
        };

        Rank rank = new Rank();
        int tc = 0;
        while (tc < expectations.length) {
            int result = rank.solution(param1List[tc], param2List[tc]);
            if (result == expectations[tc]) System.out.println("pass");
            else System.out.println(result);
            tc++;
        }
    }
}
