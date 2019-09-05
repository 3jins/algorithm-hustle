import kakao.recruitment2019.OpenChattingRoom;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        String[][] recordList = {
                {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"},
        };
        String[][] answerList = {
                {"Prodo님이 들어왔습니다.", "Ryan님이 들어왔습니다.", "Prodo님이 나갔습니다.", "Prodo님이 들어왔습니다."},
        };

        int tc = 0;
        for (String[] record : recordList) {
            String[] result = (new OpenChattingRoom()).getFinalMessages(record);
            boolean testResult = Arrays.deepEquals(answerList[tc], result);
            if (!testResult) {
                System.out.println(Arrays.deepToString(result));
            } else {
                System.out.println("pass");
            }
        }
    }
}