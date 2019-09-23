import programmers.level2.JoyStick;

public class Main {

    public static void main(String[] args) {
        String[] param1List = {
                "JEROEN",
                "JAN",
                "A",
                "AZA",
                "AAZAZA",
                "AAAA",
                "AAAB",
                "AABAB",
                "AAAABABA",
                "BB",
                "BAAAB",
                "BABAB",
                "BBBBAAAABA",
        };
        int[] expectations = {
                56,
                23,
                0,
                2,
                6,
                0,
                2,
                5,
                6,
                3,
                3,
                6,
                12,
        };
        JoyStick joyStick = new JoyStick();

        int tc = 0;
        while (tc < expectations.length) {
            int result = joyStick.solution(param1List[tc]);
            if (result == expectations[tc]) System.out.println("pass");
            else System.out.println(result);
            tc++;
        }
    }
}
