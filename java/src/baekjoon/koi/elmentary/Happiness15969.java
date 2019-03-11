package baekjoon.koi.elmentary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Happiness15969 {
    private static int mNumStudents = 0;
    private static ArrayList<Integer> mScoreList;

    // 점수만 계산하는데 어디가 행복이야...
    public Happiness15969() {
        init();
        System.out.println(getMaxDiff());
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        mScoreList = new ArrayList<>();

        try {
            mNumStudents = Integer.parseInt(reader.readLine());
            String scoreString = reader.readLine();
            StringTokenizer tokenizer = new StringTokenizer(scoreString);
            for (int i = 0; i < mNumStudents; i++) {
                mScoreList.add(Integer.parseInt(tokenizer.nextToken()));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public int getMax(ArrayList<Integer> list, int listSize) {
        if (list.size() == 0) return -1;
        int max = list.get(0);
        for (int i = 1; i < listSize; i++) {
            if (max < list.get(i)) max = list.get(i);
        }
        return max;
    }

    public int getMin(ArrayList<Integer> list, int listSize) {
        if (list.size() == 0) return -1;
        int min = list.get(0);
        for (int i = 1; i < listSize; i++) {
            if (min > list.get(i)) min = list.get(i);
        }
        return min;
    }

    public int getMaxDiff() {
        return getMax(mScoreList, mNumStudents) - getMin(mScoreList, mNumStudents);
    }
}
