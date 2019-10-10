package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Resign14501 {
    private int numDays;
    private int[] durations;
    private int[] prices;

    public Resign14501() {
        init();
        System.out.println(findMaxBenefit(1, 0));
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            numDays = Integer.parseInt(reader.readLine());
            durations = new int[numDays + 1];
            prices = new int[numDays + 1];
            for (int day = 1; day <= numDays; day++) {
                String[] inputs = reader.readLine().split(" ");
                durations[day] = Integer.parseInt(inputs[0]);
                prices[day] = Integer.parseInt(inputs[1]);
            }
        } catch (IOException e) {
        }
    }

    private int findMaxBenefit(int startDay, int maxBenefit) {
        List<Integer> benefits = new ArrayList<>();
        for (int day = startDay; day <= numDays; day++) {
            int benefit = prices[day];
            int duration = durations[day];
            if (day + duration - 1 > numDays) continue;
            benefits.add(findMaxBenefit(day + duration, maxBenefit + benefit));
        }
        if (benefits.isEmpty()) return maxBenefit;
        return Collections.max(benefits);
    }
}
