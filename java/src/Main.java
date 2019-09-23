import programmers.level1.GymUniform;

public class Main {

    public static void main(String[] args) {
        int[] param1List = { // n
                5,
                5,
                3,
                2,
                9,
                2,
                2,
                3,
                3,
                9,
                3,
                7,
        };
        int[][] param2List = { // lost
                {2, 4},
                {2, 4},
                {3},
                {1, 2},
                {1, 3, 9},
                {1},
                {1, 2},
                {2},
                {1, 3},
                {2, 4, 7, 8},
                {1, 2},
                {2, 3, 4},
        };
        int[][] param3List = { // reserve
                {1, 3, 5},
                {3},
                {1},
                {1},
                {4, 5, 6},
                {1},
                {},
                {1, 3},
                {2},
                {3, 6, 9},
                {2, 3},
                {1, 2, 3, 6},
        };
        int[] expectations = {
                5,
                4,
                2,
                1,
                7,
                2,
                0,
                3,
                2,
                8,
                2,
                6,
        };
        GymUniform gymUniform = new GymUniform();

        int tc = 0;
        while (tc < expectations.length) {
            int result = gymUniform.solution(param1List[tc], param2List[tc], param3List[tc]);
            System.out.println(result);
            tc++;
        }
    }
}
