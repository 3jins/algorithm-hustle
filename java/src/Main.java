import programmers.level3.Budget;

public class Main {
    public static void main(String[] args) {
        int[][] params1 = {
                {120, 110, 140, 150},
        };
        int[] params2 = {
                485,
        };
        int[] expectations = {
                127,
        };
        int numTc = expectations.length;
        for (int tc = 0; tc < numTc; tc++) {
            int result = (new Budget()).solution(params1[tc], params2[tc]);
            if (result == expectations[tc]) {
                System.out.println("pass");
            } else {
                System.out.println(result);
            }
        }
    }
}
