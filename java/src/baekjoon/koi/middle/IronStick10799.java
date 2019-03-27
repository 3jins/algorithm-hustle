package baekjoon.koi.middle;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 12:10 ~ 12:45
public class IronStick10799 {
    private String mPlacement;

    public IronStick10799() {
        init();
        System.out.println(getNumFragments());
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mPlacement = reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        mPlacement = mPlacement.replaceAll("\\(\\)", "L");
        mPlacement = mPlacement.substring(0, mPlacement.lastIndexOf("L") + 1);
    }

    public int getNumFragments() {
        int numFragments = 0;
        int localNumFragments = 0;
        int height = 0;
        int lenPlacement = mPlacement.length();
        for (int i = 0; i < lenPlacement; i++) {

            if (mPlacement.charAt(i) == '(') {
                height++;
                localNumFragments++;
            } else if (mPlacement.charAt(i) == ')') {
                height--;
            } else {
                numFragments += localNumFragments;
                localNumFragments = height;
            }
        }
        numFragments += height;
        return numFragments;
    }
}
