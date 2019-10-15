package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

// 13:03 ~ 13:20 (문제 이해)
// 13:20 ~ 15:05
public class DragonCurve15685 {
    private class Point {
        int y;
        int x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    private final int MAP_SIZE = 101;
    private final int[] stepY = {0, -1, 0, 1};
    private final int[] stepX = {1, 0, -1, 0};
    private boolean[][] map = new boolean[MAP_SIZE][MAP_SIZE];

    public DragonCurve15685() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            int numDragonCurves = Integer.parseInt(reader.readLine());
            for (int i = 0; i < numDragonCurves; i++) {
                String[] inputs = reader.readLine().split(" ");
                int startX = Integer.parseInt(inputs[0]);
                int startY = Integer.parseInt(inputs[1]);
                int direction = Integer.parseInt(inputs[2]);
                int generation = Integer.parseInt(inputs[3]);
                drawDragonCurve(null, startY, startX, direction, generation, 0);
            }
        } catch (IOException e) {
        }
        System.out.println(countDragonCurveSquares());
    }

    private int countDragonCurveSquares() {
        int cnt = 0;
        int[] checkStepY = {0, 0, 1, 1};
        int[] checkStepX = {0, 1, 1, 0};
        for (int y = 0; y < MAP_SIZE - 1; y++) {
            for (int x = 0; x < MAP_SIZE - 1; x++) {
                boolean cntUp = true;
                for (int i = 0; i < 4; i++) {
                    if (!map[y + checkStepY[i]][x + checkStepX[i]]) {
                        cntUp = false;
                        break;
                    }
                }
                if (cntUp) cnt++;
            }
        }
        return cnt;
    }

    private void drawDragonCurve(List<Integer> directionFootPrint, int y, int x, int initialDirection, int generation, int progress) {
        if (progress > generation) return;
        if (progress == 0) {
            map[y][x] = true;
            int lastY = y + stepY[initialDirection];
            int lastX = x + stepX[initialDirection];
            map[lastY][lastX] = true;
            directionFootPrint = new ArrayList<>();
            directionFootPrint.add(initialDirection);
            drawDragonCurve(directionFootPrint, lastY, lastX, initialDirection, generation, progress + 1);
        } else {
            int footPrintSize = directionFootPrint.size();
            int lastY = y;
            int lastX = x;
            for (int i = footPrintSize - 1; i >= 0; i--) {
                int direction = (directionFootPrint.get(i) + 1) % 4;
                directionFootPrint.add(direction);
                lastY += stepY[direction];
                lastX += stepX[direction];
                map[lastY][lastX] = true;
            }
            drawDragonCurve(directionFootPrint, lastY, lastX, initialDirection, generation, progress + 1);
        }
    }
}
