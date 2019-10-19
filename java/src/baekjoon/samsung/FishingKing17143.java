package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 21:03 ~ 23:27 (틀렸습니다)
// 23:27 ~ 24:03 (질문게시판 방황하다 포기..했는데 맞네? ㅅㅂ 뭐지)
public class FishingKing17143 {
    private class Shark {
        int y;
        int x;
        int velocity;
        int direction;
        int size;
        boolean isAlive;

        public Shark(int y, int x, int velocity, int direction, int size) {
            this.y = y;
            this.x = x;
            this.velocity = velocity;
            this.direction = direction;
            this.size = size;
            isAlive = true;
        }
    }

    private final int[][] steps = {
            null, {-1, 0}, {1, 0}, {0, 1}, {0, -1},
    };
    private int totalSize = 0;
    private int height;
    private int width;
    private int numSharks;
    private Shark[] sharks;
    private int[][] map;

    public FishingKing17143() {
        init();
        int col = 0;
        while (++col <= width) {
            catchShark(col);
            moveSharks();
        }
        System.out.println(totalSize);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs = reader.readLine().split(" ");
            height = Integer.parseInt(inputs[0]);
            width = Integer.parseInt(inputs[1]);
            numSharks = Integer.parseInt(inputs[2]);
            sharks = new Shark[numSharks + 1];
            map = new int[height + 1][width + 1];
            for (int sharkIdx = 1; sharkIdx <= numSharks; sharkIdx++) {
                inputs = reader.readLine().split(" ");
                int y = Integer.parseInt(inputs[0]);
                int x = Integer.parseInt(inputs[1]);
                map[y][x] = sharkIdx;
                sharks[sharkIdx] = new Shark(
                        y,
                        x,
                        Integer.parseInt(inputs[2]),
                        Integer.parseInt(inputs[3]),
                        Integer.parseInt(inputs[4])
                );
            }
        } catch (IOException e) {
        }
    }

    private void catchShark(int col) {
        for (int row = 1; row <= height; row++) {
            if (map[row][col] > 0) {
                int sharkIdx = map[row][col];
                sharks[sharkIdx].isAlive = false;
                totalSize += sharks[sharkIdx].size;
                map[row][col] = 0;
                return;
            }
        }
    }

    private void initMap() {
        for (Shark shark : sharks) {
            if (shark == null || !shark.isAlive) continue;
            map[shark.y][shark.x] = 0;
        }
    }

    private void moveSharks() {
        initMap();
        for (int sharkIdx = 1; sharkIdx <= numSharks; sharkIdx++) {
            Shark shark = sharks[sharkIdx];
            if (!shark.isAlive) continue;

            // move
            int nextY = shark.y;
            int nextX = shark.x;
            if (shark.direction <= 2) {
                int moveVertical = shark.velocity % ((height - 1) * 2);
                for (int i = 0; i < moveVertical; i++) {
                    if (nextY == height) shark.direction = 1;
                    if (nextY == 1) shark.direction = 2;
                    nextY += steps[shark.direction][0];
                }
            } else {
                int moveHorizontal = shark.velocity % ((width - 1) * 2);
                for (int i = 0; i < moveHorizontal; i++) {
                    if (nextX == width) shark.direction = 4;
                    if (nextX == 1) shark.direction = 3;
                    nextX += steps[shark.direction][1];
                }
            }

            // eat or be eaten
            if (map[nextY][nextX] > 0) {
                if (sharks[map[nextY][nextX]].size > shark.size) {
                    shark.isAlive = false;
                } else {
                    sharks[map[nextY][nextX]].isAlive = false;
                    map[nextY][nextX] = sharkIdx;
                    shark.y = nextY;
                    shark.x = nextX;
                }
            } else {
                map[nextY][nextX] = sharkIdx;
                shark.y = nextY;
                shark.x = nextX;
            }
        }
    }
}
