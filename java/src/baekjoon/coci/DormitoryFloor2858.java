package baekjoon.coci;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 18:08 ~ 18:28
public class DormitoryFloor2858 {
    private int mRed;
    private int mBrown;

    public DormitoryFloor2858() {
        init();
        printDormSizes();
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String inputString = reader.readLine();
            StringTokenizer tokenizer = new StringTokenizer(inputString);
            mRed = Integer.parseInt(tokenizer.nextToken());
            mBrown = Integer.parseInt(tokenizer.nextToken());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void printDormSizes() {
        for (int i = 4; i <= mRed; i += 2) {
            int w = i / 2;
            int l = (mRed - i) / 2;

            if((w - 1) * (l - 1) == mBrown) {
                System.out.println((l + 1) + " " + (w + 1));
                return;
            }
        }
    }
}
