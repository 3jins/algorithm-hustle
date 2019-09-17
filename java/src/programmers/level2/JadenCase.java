package programmers.level2;

public class JadenCase {
    public String solution(String s) {
        String jaden = "";
        int strLen = s.length();
        boolean flag = true;
        for (int idx = 0; idx < strLen; idx++) {
            char c = s.charAt(idx);
            if (c == ' ') {
                flag = true;
                jaden += c;
                continue;
            }
            if (flag) {
                jaden += Character.toUpperCase(c);
                flag = false;
            } else {
                jaden += Character.toLowerCase(c);
            }
        }
        return jaden;
    }
}
