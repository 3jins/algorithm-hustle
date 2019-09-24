package programmers.level2;

import java.util.Arrays;

public class RescueBoat {
    public int solution(int[] people, int limit) {
        Arrays.sort(people);
        int light = 0;
        int heavy = people.length - 1;
        int cnt = 0;
        while (light < heavy) {
            if (people[heavy] + people[light] <= limit) {
                light++;
            }
            heavy--;
            cnt++;
        }
        return light == heavy ? cnt + 1 : cnt;
    }
}
