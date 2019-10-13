package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 19:51 ~ 20:48 (3번 TC 틀린 이유 찾는거 포기)
// 20:48 ~ 21:13 (이유 찾음: 문제 오독)
// 21:13 ~ 21:38
public class Gear14891 {
    private final int NUM_GEARS = 4;
    private final int NUM_TEETH = 8;
    private int[][] gears = new int[NUM_GEARS][8];
    private int numRotations;
    private int[][] rotations;

    public Gear14891() {
        init();
        rotateAll();
        System.out.println(calculateScore());
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs;
            for (int i = 0; i < NUM_GEARS; i++) {
                inputs = reader.readLine().split("");
                for (int j = 0; j < NUM_TEETH; j++) {
                    gears[i][j] = Integer.parseInt(inputs[j]);
                }
            }
            numRotations = Integer.parseInt(reader.readLine());
            rotations = new int[numRotations][2];
            for (int i = 0; i < numRotations; i++) {
                inputs = reader.readLine().split(" ");
                rotations[i][0] = Integer.parseInt(inputs[0]) - 1;
                rotations[i][1] = Integer.parseInt(inputs[1]);
            }
        } catch (IOException e) {
        }
    }

    private void rotate(int gearIdx, int direction) {
        int[] tmp = new int[NUM_TEETH];
        for (int i = 0; i < NUM_TEETH; i++) {
            tmp[(NUM_TEETH + i + direction) % NUM_TEETH] = gears[gearIdx][i];
        }
        for (int i = 0; i < NUM_TEETH; i++) {
            gears[gearIdx][i] = tmp[i];
        }
    }

    private void rotateAll() {
        for (int[] rotation : rotations) {
            int gearIdx = rotation[0];
            int direction = rotation[1];

            int[] rotationMap = new int[NUM_GEARS];
            rotationMap[gearIdx] = direction;
            int idx = 1;
            while (gearIdx - idx >= 0) { // 왼쪽 전파
                if (gears[gearIdx - idx][NUM_TEETH / 4] == gears[gearIdx - idx + 1][NUM_TEETH - NUM_TEETH / 4]) {
                    break;
                }
                rotationMap[gearIdx - idx] = (idx % 2 == 0) ? direction : -direction;
                idx++;
            }
            idx = 1;
            while (gearIdx + idx < NUM_GEARS) { // 오른쪽 전파
                if (gears[gearIdx + idx][NUM_TEETH - NUM_TEETH / 4] == gears[gearIdx + idx - 1][NUM_TEETH / 4]) {
                    break;
                }
                rotationMap[gearIdx + idx] = (idx % 2 == 0) ? direction : -direction;
                idx++;
            }
            for (int i = 0; i < NUM_GEARS; i++) {
                if (rotationMap[i] != 0) {
                    rotate(i, rotationMap[i]);
                }
            }
        }
    }

    private int calculateScore() {
        int score = 0;
        for (int i = 0; i < NUM_GEARS; i++) {
            if (gears[i][0] == 1) score += Math.pow(2, i);
        }
        return score;
    }
}
