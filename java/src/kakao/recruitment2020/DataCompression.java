package kakao.recruitment2020;

import java.util.Arrays;

// 14:00 ~ 15:59
public class DataCompression {
    public int solution(String s) {
        return getShortestCompressed(s).length();
    }

    private String[] splitByUnit(String s, int unit) {
        int strLen = s.length();
        // int numFrags = strLen / unit;
        int numFrags = strLen / unit + (strLen % unit == 0 ? 0 : 1);
        String[] frags = new String[numFrags];
        for (int i = 0; i < numFrags; i++) {
            if ( i == numFrags - 1) {
                frags[i] = s.substring(i * unit);
            } else {
                frags[i] = s.substring(i * unit, (i + 1) * unit);
            }
        }
        return frags;
    }

    private String getShortestCompressed(String raw) {
        int strLen = raw.length();
        String shortestCompressed = raw;
        for (int unit = 1; unit < strLen; unit++) {
            // boolean isCompressed = false;
            String compressed = "";
            int lastIdx = 0;
            while (lastIdx < raw.length() - unit) {
                String restOfRaw = raw.substring(lastIdx, strLen);
                String[] frags = splitByUnit(restOfRaw, unit);
                // System.out.println(Arrays.deepToString(frags));
                int numFrags = frags.length;
                if (numFrags <= 1) {
                    compressed += restOfRaw;
                    break;
                }
                String unitStr = frags[0];
                // System.out.println("unitStr: " + unitStr);
                int cnt = 1;
                for (int j = 1; j < numFrags; j++) {
                    lastIdx += unit;
                    if (frags[j].equals(unitStr)) {
                        // isCompressed = true;
                        cnt++;
                        // System.out.println(cnt + " " + unitStr);
                        // System.out.println(lastIdx);
                    } else {
                        if (cnt > 1) {
                            compressed += cnt;
                            cnt = 1;
                        }
                        compressed += unitStr;
                        // System.out.println("[else] " + compressed);
                        unitStr = frags[j];
                    }
                }
                if (cnt > 1) compressed += cnt;
                compressed += unitStr;
                lastIdx += unit;
                // System.out.println("[마무리] " + compressed);
                // System.out.println(lastIdx + "/" + (raw.length() - unit));
                // System.out.println(raw.substring((numFrags - 1) * unit));
            }
            // System.out.println(compressed);
            if (shortestCompressed.length() > compressed.length()) {
                shortestCompressed = compressed;
            }
        }
        // System.out.println("feijfewoihefoihefoiehfo  " + shortestCompressed);
        return shortestCompressed;
    }
}