package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 20:25 ~ 20:48, 20:58 ~ 21:33
public class RobotCleaner14503 {
    private final int[] STEP_Y = {-1, 0, 1, 0};
    private final int[] STEP_X = {0, 1, 0, -1};

    private class Cleaner {
        int y;
        int x;
        int d;
        int cnt;

        public Cleaner(int y, int x, int d) {
            this.y = y;
            this.x = x;
            this.d = d;
        }

        public void clean() {
            cnt++;
            isVisited[y][x] = true;
            // System.out.println(y + ", " + x);
        }

        public void turnLeft() {
            d = (d + 4 - 1) % 4;
        }

        public boolean checkFront() {
            int nextY = y + STEP_Y[d];
            int nextX = x + STEP_X[d];
            return !isVisited[nextY][nextX] && map[nextY][nextX] == 0;
        }

        public boolean checkBack() {
            int nextY = y - STEP_Y[d];
            int nextX = x - STEP_X[d];
            return map[nextY][nextX] == 0;
        }

        public void go() {
            y += STEP_Y[d];
            x += STEP_X[d];
        }

        public void goBack() {
            y -= STEP_Y[d];
            x -= STEP_X[d];
        }
    }

    private int height;
    private int width;
    private Cleaner cleaner;
    private int[][] map;
    boolean[][] isVisited;

    public RobotCleaner14503() {
        init();
        operateCleaner();
        System.out.println(cleaner.cnt);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs = reader.readLine().split(" ");
            height = Integer.parseInt(inputs[0]);
            width = Integer.parseInt(inputs[1]);
            map = new int[height][width];
            isVisited = new boolean[height][width];
            inputs = reader.readLine().split(" ");
            cleaner = new Cleaner(Integer.parseInt(inputs[0]), Integer.parseInt(inputs[1]), Integer.parseInt(inputs[2]));
            for (int h = 0; h < height; h++) {
                inputs = reader.readLine().split(" ");
                for (int w = 0; w < width; w++) {
                    map[h][w] = Integer.parseInt(inputs[w]);
                }
            }
        } catch (IOException e) {
        }
    }

    private void operateCleaner() {
        cleaner.clean();
        while (true) {
            int turnCnt = 0;
            while (true) {
                cleaner.turnLeft();
                turnCnt++;
                if (cleaner.checkFront()) {
                    cleaner.go();
                    cleaner.clean();
                    break;
                }
                if (turnCnt < 4) continue;
                if (cleaner.checkBack()) {
                    cleaner.goBack();
                    break;
                } else {
                    return;
                }
            }
        }
    }
}
