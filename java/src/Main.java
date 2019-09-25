import programmers.level3.MostFarNode;

public class Main {
    public static void main(String[] args) {
        int[] param1List = {
                6,
        };
        int[][][] param2List = {
                {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}},
        };
        int[] expectations = {
                3,
        };

        MostFarNode mostFarNode = new MostFarNode();
        int tc = 0;
        while (tc < expectations.length) {
            int result = mostFarNode.solution(param1List[tc], param2List[tc]);
            if (result == expectations[tc]) System.out.println("pass");
            else System.out.println(result);
            tc++;
        }
    }
}
