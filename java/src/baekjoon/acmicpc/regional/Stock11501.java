package baekjoon.acmicpc.regional;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

// 20:41 ~
public class Stock11501 {
    private int mNumTestCases;
    private ArrayList<Integer>[] mStockValueList;
    private int[] mDays;

    public Stock11501() {
        init();
        for (int i = 0; i < mNumTestCases; i++) {
            System.out.println(getMaxBenefit(i));
        }
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mNumTestCases = Integer.parseInt(reader.readLine());
            mStockValueList = new ArrayList[mNumTestCases];
            mDays = new int[mNumTestCases];
            for (int i = 0; i < mNumTestCases; i++) {
                mStockValueList[i] = new ArrayList<>();
                mDays[i] = Integer.parseInt(reader.readLine());
                String stockValueString = reader.readLine();
                StringTokenizer tokenizer = new StringTokenizer(stockValueString);
                for (int j = 0; j < mDays[i]; j++) {
                    mStockValueList[i].add(Integer.parseInt(tokenizer.nextToken()));
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public long getMaxBenefit(int testCase) {
        long maxBenefit = 0;
        int localMaxValue = mStockValueList[testCase].get(mDays[testCase] - 1);
        for (int i = mDays[testCase] - 2; i >= 0; i--) {
            if (mStockValueList[testCase].get(i) < localMaxValue) {
                maxBenefit += (localMaxValue - mStockValueList[testCase].get(i));
            } else {
                localMaxValue = mStockValueList[testCase].get(i);
            }
        }

        return maxBenefit;
    }
}
