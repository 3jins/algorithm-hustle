package baekjoon.koi.elmentary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

// 13:12 ~ 14:10, 14:10 ~ 14:31
//
// TIL
// 1. 입력형식이 복잡해도 극단적인 입력은 있다. (0 strikes, 0 balls / 3 strikes / 3 balls)
// 2. 예외를 수작업으로 걸러낼 때는 꼼꼼함이 더 요구된다. 자신없으면 저런 부분 테스트함수 만들어서 진행하자.
public class NumberBaseball2503 {
    private final int MAX_NUMBER = 987;
    private final int NUM_DIGITS = 3;

    private class Number {
        ArrayList<Integer> digits;

        Number(int number) {
            digits = new ArrayList<>();
            for (int i = 0; i < NUM_DIGITS; i++) {
                digits.add(number / (int) Math.pow(10, NUM_DIGITS - 1 - i) % 10);
            }
        }
    }

    private class QueryResult {
        Number number;
        int numStrikes;
        int numBalls;

        QueryResult(int number, int numStrikes, int numBalls) {
            this.number = new Number(number);
            this.numStrikes = numStrikes;
            this.numBalls = numBalls;
        }

        boolean test(int _testNumber) {
            Number testNumber = new Number(_testNumber);
            int strikeCnt = 0;
            int ballCnt = 0;
            for (int i = 0; i < NUM_DIGITS; i++) {
                if (testNumber.digits.get(i) == this.number.digits.get(i)) strikeCnt++;
                for (int j = 0; j < NUM_DIGITS; j++) {
                    if (i == j) continue;
                    if (testNumber.digits.get(i) == this.number.digits.get(j)) {
                        ballCnt++;
                        break;
                    }
                }
            }
            return strikeCnt == this.numStrikes && ballCnt == this.numBalls;
        }
    }

    private int mNumQuestions;
    private ArrayList<QueryResult> mQueryResultList;

    public NumberBaseball2503() {
        init();
        System.out.println(getNumPossibleAnswers());
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        mQueryResultList = new ArrayList<>();
        try {
            mNumQuestions = Integer.parseInt(reader.readLine());
            for (int i = 0; i < mNumQuestions; i++) {
                String queryResultString = reader.readLine();
                StringTokenizer tokenizer = new StringTokenizer(queryResultString);
                mQueryResultList.add(new QueryResult(
                        Integer.parseInt(tokenizer.nextToken()),
                        Integer.parseInt(tokenizer.nextToken()),
                        Integer.parseInt(tokenizer.nextToken())
                ));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public int getNumPossibleAnswers() {
        int numPossibleAnswers = 0;
        for (int i = 123; i <= MAX_NUMBER; i++) {
            if (i % 10 == 0 || i / 10 % 10 == 0) continue; // Digits are allowed only 1 ~ 9
            if (i % 100 % 11 == 0 || i / 10 % 11 == 0 || (i - i % 100 / 10 * 10) % 101 == 0) continue; // All digits must be different one another
            boolean isItPossible = true;
            for (int j = 0; j < mNumQuestions; j++) {
                QueryResult queryResult = mQueryResultList.get(j);
                if (!queryResult.test(i)) {
                    isItPossible = false;
                    break;
                }
            }
            if (isItPossible) numPossibleAnswers++;
        }
        return numPossibleAnswers;
    }
}
