import programmers.level2.RescueBoat;

public class Main {
    public static void main(String[] args) {
        int[][] param1List = {
                {70, 50, 80, 50},
                {70, 50, 80, 50},
                {70, 80, 50},
                {100, 100, 100, 110, 100, 100, 100, 120},
                {100, 100, 100, 110, 100, 100, 120},
                {100, 100, 100, 110, 100, 100, 100, 120},
                {100, 100, 100, 110, 100, 100, 100, 120},
        };
        int[] param2List = {
                150,
                100,
                100,
                210,
                210,
                220,
                230,
        };
        int[] expectations = {
                2,
                3,
                3,
                5,
                4,
                4,
                4,
        };

        RescueBoat rescueBoat = new RescueBoat();
        int tc = 0;
        while (tc < expectations.length) {
            int result = rescueBoat.solution(param1List[tc], param2List[tc]);
            if (result == expectations[tc]) System.out.println("pass");
            else System.out.println(result);
            tc++;
        }
    }
}
