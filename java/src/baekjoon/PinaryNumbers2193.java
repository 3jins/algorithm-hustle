package baekjoon;

import java.util.Scanner;

// It seems like a term 'pinary number' is used only in this problem...
public class PinaryNumbers2193 {
    private class PinaryNumberInfo {
        long endsWithOne;
        long endsWithZero;

        PinaryNumberInfo(long endsWithOne, long endsWithZero) {
            this.endsWithOne = endsWithOne;
            this.endsWithZero = endsWithZero;
        }
    }

    public PinaryNumbers2193() {
        Scanner scanner = new Scanner(System.in);
        int numDecimal = scanner.nextInt();
        PinaryNumberInfo pinaryNumberInfo = calcNumPinaries(numDecimal);
        System.out.println(pinaryNumberInfo.endsWithOne + pinaryNumberInfo.endsWithZero);
    }

    private PinaryNumberInfo calcNumPinaries(int numDecimal) {
        if (numDecimal == 1) return new PinaryNumberInfo(0, 1);
        if (numDecimal == 2) return new PinaryNumberInfo(0, 1);

        PinaryNumberInfo prePinaryNumberInfo = calcNumPinaries(numDecimal - 1);
        return new PinaryNumberInfo(
                prePinaryNumberInfo.endsWithZero,
                prePinaryNumberInfo.endsWithZero + prePinaryNumberInfo.endsWithOne
        );
    }
}
