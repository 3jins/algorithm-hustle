package baekjoon.koi.middle;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 17:40 ~ 19:30 (포기)
// 20:18 ~ 21:30
public class CardGame10835 {
    private int mNumCardsPerDeck;
    private int[] mLeftDeck;
    private int[] mRightDeck;
    private int[][] mOptimized;

    public CardGame10835() {
        init();
        System.out.println(getMaxScore(0, 0));
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer;
        try {
            mNumCardsPerDeck = Integer.parseInt(reader.readLine());
            mLeftDeck = new int[mNumCardsPerDeck];
            mRightDeck = new int[mNumCardsPerDeck];
            tokenizer = new StringTokenizer(reader.readLine());
            for (int i = 0; i < mNumCardsPerDeck; i++) {
                mLeftDeck[i] = Integer.parseInt(tokenizer.nextToken());
            }
            tokenizer = new StringTokenizer(reader.readLine());
            for (int i = 0; i < mNumCardsPerDeck; i++) {
                mRightDeck[i] = Integer.parseInt(tokenizer.nextToken());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        mOptimized = new int[mNumCardsPerDeck][mNumCardsPerDeck];
        for (int i = 0; i < mNumCardsPerDeck; i++) {
            for (int j = 0; j < mNumCardsPerDeck; j++) {
                mOptimized[i][j] = -1;
            }
        }
    }

    public boolean isEnd(int leftIdx, int rightIdx) {
        return (leftIdx == mNumCardsPerDeck) || (rightIdx == mNumCardsPerDeck);
    }

    public int getMaxScore(int leftIdx, int rightIdx) {
        if (isEnd(leftIdx, rightIdx)) return 0;
        if (mOptimized[leftIdx][rightIdx] >= 0) return mOptimized[leftIdx][rightIdx];
        int left = mLeftDeck[leftIdx];
        int right = mRightDeck[rightIdx];
        if (left > right) {
            mOptimized[leftIdx][rightIdx] = right + getMaxScore(leftIdx, rightIdx + 1);
        } else {
            mOptimized[leftIdx][rightIdx] = Math.max(getMaxScore(leftIdx + 1, rightIdx), getMaxScore(leftIdx + 1, rightIdx + 1));
        }

        return mOptimized[leftIdx][rightIdx];
    }
}
