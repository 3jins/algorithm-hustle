package baekjoon.koi.high;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

// 01:45 ~ 02:21
public class Tower2493 {
    private int mNumTowers;
    private int[] mTowersArr;

    public Tower2493() {
        init();
        int[] receptionStatus = getReceptionStatus();
        for (int i = 1; i <= mNumTowers; i++) {
            System.out.print(receptionStatus[i] + " ");
        }
        System.out.println();
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mNumTowers = Integer.parseInt(reader.readLine());
            mTowersArr = new int[mNumTowers + 1];
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
            for (int i = 1; i <= mNumTowers; i++) {
                mTowersArr[i] = Integer.parseInt(tokenizer.nextToken());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public int[] getReceptionStatus() {
        int[] receptionStatus = new int[mNumTowers + 1];
        ArrayList<Integer> receivedTowerList = new ArrayList<>();
        for (int i = 2; i <= mNumTowers; i++) {
            if (mTowersArr[i] < mTowersArr[i - 1]) {
                receptionStatus[i] = i - 1;
                receivedTowerList.add(i - 1);
                continue;
            }
            int numReceivedTowers = receivedTowerList.size();
            for (int j = numReceivedTowers - 1; j >= 0; j--) {
                int receivedTowerIdx = receivedTowerList.get(j);
                if (mTowersArr[i] < mTowersArr[receivedTowerIdx]) {
                    receptionStatus[i] = receivedTowerIdx;
                    break;
                }
            }
        }

        return receptionStatus;
    }
}
