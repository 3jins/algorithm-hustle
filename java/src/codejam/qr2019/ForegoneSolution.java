package codejam.qr2019;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

import static java.lang.System.gc;

// 13:20 ~ 14:08
public class ForegoneSolution {
    private static final int LOST_DIGIT = 4;
    private int mNumCases;
    private int mNumDigits;
    private ArrayList<Integer> mAmountJamcoinDigitList; // Digit of 10^N will be in Nth element.
    private ArrayList<Integer> mDigitListA;
    private ArrayList<Integer> mDigitListB;

    public ForegoneSolution() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mNumCases = Integer.parseInt(reader.readLine());
            for (int i = 0; i < mNumCases; i++) {
                init(reader);
                gc();
                separateNumberWithoutDigit(LOST_DIGIT);

                System.out.print("Case #" + (i + 1) + ": ");
                printReversedDigitList(mDigitListA);
                System.out.print(" ");
                printReversedDigitList(mDigitListB);
                System.out.println();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void init(BufferedReader reader) {
        mNumDigits = 0;
        mAmountJamcoinDigitList = new ArrayList<>();
        mDigitListA = new ArrayList<>();
        mDigitListB = new ArrayList<>();
        try {
            int amountJamcoin = Integer.parseInt(reader.readLine());

            while (amountJamcoin > 0) {
                mAmountJamcoinDigitList.add(amountJamcoin % 10);
                amountJamcoin /= 10;
                mNumDigits++;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void subtractOne(int idx, int digit) {
        if (digit == 0) {
            mDigitListA.add(9);
            mDigitListB.add(1);
            subtractOne(idx + 1, mAmountJamcoinDigitList.get(idx + 1));
        } else {
            mDigitListA.add(digit - 1);
            mDigitListB.add(1);
        }
    }

    public void separateNumberWithoutDigit(int withoutDigit) {
        boolean isChanged = false;
        for (int i = 0; i < mNumDigits; i++) {
            int digit = mAmountJamcoinDigitList.get(i);
            if (digit != 4) {
                mDigitListA.add(digit);
                mDigitListB.add(0);
            } else {
                subtractOne(i, digit);
            }
        }
    }

    public void printReversedDigitList(ArrayList<Integer> reversedDigitList) {
        int numDigits = reversedDigitList.size();
        boolean isStillZero = true;
        for (int i = numDigits - 1; i >= 0; i--) {
            int digit = reversedDigitList.get(i);
            if (isStillZero && digit == 0) continue;
            isStillZero = false;
            System.out.print(digit);
        }
    }
}
