package baekjoon.koi.elementary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

// 14:31 ~ 15:48, 15:48 ~ 16:22
public class DrawingArrows15970 {
    private HashMap<Integer, Integer> mPointMap;    // key: position, value: color
    private int mNumPoints;
    private int mFirstPos = 100000;
    private int mLastPos = 0;

    public DrawingArrows15970() {
        init();
        System.out.println(getSumArrowLen());
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        mPointMap = new HashMap<>();
        try {
            mNumPoints = Integer.parseInt(reader.readLine());
            for (int i = 0; i < mNumPoints; i++) {
                String pointString = reader.readLine();
                StringTokenizer tokenizer = new StringTokenizer(pointString);
                int pos = Integer.parseInt(tokenizer.nextToken());
                int color = Integer.parseInt(tokenizer.nextToken());
                mPointMap.put(pos, color);
                if (pos < mFirstPos) mFirstPos = pos;
                if (pos > mLastPos) mLastPos = pos;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public int getSumArrowLen() {
        int sumArrowLen = 0;
        HashMap<Integer, Integer> lastPosMap = new HashMap<>();
        HashMap<Integer, Integer> lastDistanceMap = new HashMap<>();
        for (int pos = mFirstPos; pos <= mLastPos; pos++) {
            if (!mPointMap.containsKey(pos)) continue;
            int color = mPointMap.get(pos);

            if (!lastPosMap.containsKey(color)) {
                lastPosMap.put(color, pos);
                continue;
            }
            int lastPos = lastPosMap.get(color);
            int curDistance = pos - lastPos;
            if (!lastDistanceMap.containsKey(color)) {
                sumArrowLen += curDistance;
                lastDistanceMap.put(color, curDistance);
                lastPosMap.replace(color, pos);
                continue;
            }
            int lastDistance = lastDistanceMap.get(color);
            sumArrowLen += (curDistance > lastDistance) ? lastDistance : curDistance;
            lastPosMap.replace(color, pos);
            lastDistanceMap.replace(color, curDistance);
        }
        for (int distance : lastDistanceMap.values()) {
            sumArrowLen += distance;
        }

        return sumArrowLen;
    }
}
