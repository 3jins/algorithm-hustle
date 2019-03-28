package baekjoon.acmicpc.regional;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.System.gc;

// 02:09 ~ 02:37
// 코드가 좀 난잡하긴 한데...
public class PrinterQueue1966 {
    private int mNumTests;
    private int mNumDocuments;
    private int mTargetIndex;
    private ArrayList<Integer> mPriorityList;

    public PrinterQueue1966() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mNumTests = Integer.parseInt(reader.readLine());
            for (int i = 0; i < mNumTests; i++) {
                init(reader);
                gc();
                System.out.println(getPrintSequence());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void init(BufferedReader reader) {
        StringTokenizer tokenizer;
        try {
            tokenizer = new StringTokenizer(reader.readLine());
            mNumDocuments = Integer.parseInt(tokenizer.nextToken());
            mTargetIndex = Integer.parseInt(tokenizer.nextToken());
            mPriorityList = new ArrayList<>(mTargetIndex + 1);
            tokenizer = new StringTokenizer(reader.readLine());
            for (int i = 0; i < mNumDocuments; i++) {
                mPriorityList.add(Integer.parseInt(tokenizer.nextToken()));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public int getPrintSequence() {
        int printSequence = 0;
        while (true) {
            boolean isSequenceChanged = false;
            int curPriority = mPriorityList.get(0);
            for (int i = 0; i < mNumDocuments; i++) {
                if (mPriorityList.get(i) > curPriority) {
                    mPriorityList.remove(0);
                    mPriorityList.add(curPriority);
                    if (mTargetIndex > 0) mTargetIndex--;
                    else mTargetIndex = mNumDocuments - 1;
                    isSequenceChanged = true;
                    break;
                }
            }
            if (!isSequenceChanged) {
                mPriorityList.remove(0);
                printSequence++;
                mNumDocuments--;
                mTargetIndex--;
                if(mTargetIndex < 0) break;
            }
        }

        return printSequence;
    }
}
