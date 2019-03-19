package lg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Mission5Recursive {
    private int mNumWorks;
    private int[][] mWorkTimeTable;

    public Mission5Recursive() {
        init(); // 입력받기
        boolean[] workAllocationArr = new boolean[mNumWorks]; // 각 일감의 할당 여부
        System.out.println(getBestWorkTime(0, workAllocationArr, 0));
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mNumWorks = Integer.parseInt(reader.readLine());
            mWorkTimeTable = new int[mNumWorks][mNumWorks];
            for (int i = 0; i < mNumWorks; i++) {
                String inputString = reader.readLine();
                StringTokenizer tokenizer = new StringTokenizer(inputString);
                for (int j = 0; j < mNumWorks; j++) {
                    mWorkTimeTable[i][j] = Integer.parseInt(tokenizer.nextToken());
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public boolean[] deepCopy(boolean[] arr) {
        int arrSize = arr.length;
        boolean[] newArr = new boolean[arrSize];
        for (int i = 0; i < arrSize; i++) {
            newArr[i] = arr[i];
        }
        return newArr;
    }

    public int getBestWorkTime(int workTime, boolean[] workAllocationArr, int rowIdx) {
        if (rowIdx >= mNumWorks) return workTime;
        int bestWorkTime = Integer.MAX_VALUE;

        for (int i = 0; i < mNumWorks; i++) {
            if (workAllocationArr[i]) continue;
            boolean[] copiedWorkAllocationArr = deepCopy(workAllocationArr);
            copiedWorkAllocationArr[i] = true;
            int curWorkTime = getBestWorkTime(workTime + mWorkTimeTable[rowIdx][i], copiedWorkAllocationArr, rowIdx + 1);
            if (curWorkTime < bestWorkTime) bestWorkTime = curWorkTime;
        }
        return bestWorkTime;
    }
}
