package programmers.level2;

public class ContextExpectation {
    private int whenTheyMeet(int round, int a, int b) {
        if (Math.abs(a - b) == 1 && ((a - 1) / 2 == (b - 1) / 2)) {
            return round;
        }
        return whenTheyMeet(round + 1,(a + 1) / 2, (b + 1 ) / 2);
    }

    public int solution(int n, int a, int b) {
        return whenTheyMeet(1, a, b);
    }
}
