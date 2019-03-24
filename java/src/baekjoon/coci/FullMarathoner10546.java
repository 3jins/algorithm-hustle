package baekjoon.coci;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

// 20:41 ~ 21:04, 22:46 ~ 23:14, 23:14 ~ 23:56, 00:20 ~ 01:15, 01:15 ~ 01:20
//
// TIL
// 1. 런타임 에러 => 메인코드형식 문제 or 익셉션발생(주로 배열 범위 초과)
// 2. java.utils.Arrays.binarySearch, java.util.Collections.binarySearch
// 3. 중복데이터가 있을 때의 마킹 -> 처리한 데이터를 리스트에서 빼버리는 게 제일 쉽다
public class FullMarathoner10546 {
    private int mNumParticipants;
    private ArrayList<String> mParticipantsList;
    private String[] mCompletedParticipantsArr;

    public FullMarathoner10546() {
        init();
        for (int i = 0; i < mNumParticipants - 1; i++) {
            markCompleted(i);
        }
        System.out.println(mParticipantsList.get(0));
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mNumParticipants = Integer.parseInt(reader.readLine());
            mParticipantsList = new ArrayList<>(mNumParticipants);
            mCompletedParticipantsArr = new String[mNumParticipants - 1];
            for (int i = 0; i < mNumParticipants; i++) {
                mParticipantsList.add(reader.readLine());
            }
            for (int i = 0; i < mNumParticipants - 1; i++) {
                mCompletedParticipantsArr[i] = reader.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        Collections.sort(mParticipantsList);
    }

    public void markCompleted(int idx) {
        String completedParticipant = mCompletedParticipantsArr[idx];
        int completedParticipantIdx = Collections.binarySearch(mParticipantsList, completedParticipant);
        mParticipantsList.remove(completedParticipantIdx);
    }
}
