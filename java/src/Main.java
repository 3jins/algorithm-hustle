import kakao.recruitment2020.LockAndKey;

public class Main {
    public static void main(String[] args) {
        int[][][] param1List = {
                {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}},
        };
        int[][][] param2List = {
                {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}},
        };
        boolean[] expectations = {
               true,
        };

        LockAndKey lockAndKey = new LockAndKey();
        int tc = 0;
        while (tc < expectations.length) {
            boolean result = lockAndKey.solution(param1List[tc], param2List[tc]);
            if (result == expectations[tc]) System.out.println("pass");
            else System.out.println(result);
            tc++;
        }
    }
}
