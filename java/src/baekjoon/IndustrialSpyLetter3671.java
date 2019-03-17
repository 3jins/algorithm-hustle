package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

import static java.lang.System.gc;

// 13:33 ~ 15:33, 15:34 ~ 15:58, 15:58 ~ 16:11, 16:11 ~ 16:16 (재귀 포기)
// 16:23 ~ 16:33 (포기)
// 16:39 ~ 16:57 (리얼 포기)
// 17:12 ~ 17:44 (시발)
// 18:00 ~ 18:12
//
// 깨달은 점들
// 1. testcase가 나눠지는 문제는 생성자에서 testcase 나누고 init에서 각 케이스별 입력을 받는 게 편하다.
// 2. testcase가 나눠진 경우, gc가 제대로 호출되지 않으면 메모리가 터진다.
// 3. 해시맵크기 = (key크기 + value크기) * 길이 이다. 최댓값이 지정된 경우라면 가급적 배열을 쓰도록 하자.
// 4. 해시맵 초기화시 디폴트 설정은 길이 16, 75% 찰 경우 증가이다. 몇 배 증가하는지는 모르겠지만 아마 2배 아닐까.

public class IndustrialSpyLetter3671 {
    private final int MAX_VALUE = 9999999;
    private String mPaperFragments;
    private boolean[] mPossibleNumberMask;

    public IndustrialSpyLetter3671() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            int numCases = Integer.parseInt(reader.readLine());
            for (int i = 0; i < numCases; i++) {
                init(reader);
                mPossibleNumberMask = new boolean[MAX_VALUE + 1];
                makePossibleNumberMap("", mPaperFragments);
                System.out.println(getNumPrimes());
                gc();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void init(BufferedReader reader) {
        try {
            mPaperFragments = reader.readLine();
            char[] fragmentChars = mPaperFragments.toCharArray();
            Arrays.sort(fragmentChars);
            mPaperFragments = new String(fragmentChars);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public boolean isPrime(int number) {
        if (number <= 1) return false;
        int root = (int) Math.sqrt(number);
        for (int i = 2; i <= root; i++) {
            if (number % i == 0) return false;
        }
        return true;
    }

    public int getNumPrimes() {
        int count = 0;
        for (int i = 0; i <= MAX_VALUE; i++) {
            if (mPossibleNumberMask[i] && isPrime(i)) count++;
        }
        return count;
    }

    public void makePossibleNumberMap(String combination, String paperFragments) {
        if (!combination.equals("")) mPossibleNumberMask[Integer.parseInt(combination)] = true;
        int numFragments = paperFragments.length();
        for (int i = 0; i < numFragments; i++) {
            int key = paperFragments.charAt(i) - '0';
            String restFragments = (i == 0 ? "" : paperFragments.substring(0, i)) +
                    (i == numFragments - 1 ? "" : paperFragments.substring(i + 1));
            makePossibleNumberMap(combination + key, restFragments);
        }
    }
}
