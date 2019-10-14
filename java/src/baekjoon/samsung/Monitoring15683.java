package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

// 12:20 ~ 14:45
public class Monitoring15683 {
    private class CCTV {
        int y;
        int x;
        int type;
        int direction;

        public CCTV(int y, int x, int type, int direction) {
            this.y = y;
            this.x = x;
            this.type = type;
            this.direction = direction;
        }

        public void turnClockwise() {
            direction = (direction + 1) % 4;
        }
    }

    private int minKillPointArea = Integer.MAX_VALUE;
    private int height;
    private int width;
    private int[][] map;
    private List<CCTV> cctvList = new ArrayList<>();
    private int numCctv;

    public Monitoring15683() {
        init();
        findKillPointArea(0);
        System.out.println(minKillPointArea);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs = reader.readLine().split(" ");
            height = Integer.parseInt(inputs[0]);
            width = Integer.parseInt(inputs[1]);
            map = new int[height + 2][width + 2];
            for (int w = 0; w <= width + 1; w++) {
                map[0][w] = 6;
                map[height + 1][w] = 6;
            }
            for (int h = 1; h <= height; h++) {
                inputs = reader.readLine().split(" ");
                map[h][0] = 6;
                map[h][width + 1] = 6;
                for (int w = 1; w <= width; w++) {
                    int coord = Integer.parseInt(inputs[w - 1]);
                    if (coord >= 1 && coord <= 5) {
                        cctvList.add(new CCTV(h, w, coord, 0));
                    }
                    map[h][w] = coord;
                }
            }
            numCctv = cctvList.size();
        } catch (IOException e) {
        }
    }

    private int[][] copyArray(int[][] original) {
        int height = original.length;
        int width = original[0].length;
        int[][] copied = new int[height][width];
        for (int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                copied[h][w] = original[h][w];
            }
        }
        return copied;
    }

    private void fillVision(int[][] visionMap, int y, int x, int direction) {
        int[] visionY = {-1, 0, 1, 0};
        int[] visionX = {0, 1, 0, -1};
        int nextBlock;
        while (true) {
            y += visionY[direction];
            x += visionX[direction];
            nextBlock = map[y][x];
            if (nextBlock == 6) break;
            visionMap[y][x] = 9;
        }
    }

    private int getKillPointArea() {
        int[][] visionMap = copyArray(map);
        for (CCTV cctv : cctvList) {
            switch (cctv.type) {
                case 1:
                    fillVision(visionMap, cctv.y, cctv.x, cctv.direction);
                    break;
                case 2:
                    fillVision(visionMap, cctv.y, cctv.x, cctv.direction);
                    fillVision(visionMap, cctv.y, cctv.x, (cctv.direction + 2) % 4);
                    break;
                case 3:
                    fillVision(visionMap, cctv.y, cctv.x, cctv.direction);
                    fillVision(visionMap, cctv.y, cctv.x, (cctv.direction + 1) % 4);
                    break;
                case 4:
                    fillVision(visionMap, cctv.y, cctv.x, cctv.direction);
                    fillVision(visionMap, cctv.y, cctv.x, (cctv.direction + 1) % 4);
                    fillVision(visionMap, cctv.y, cctv.x, (cctv.direction + 3) % 4);
                    break;
                case 5:
                    fillVision(visionMap, cctv.y, cctv.x, cctv.direction);
                    fillVision(visionMap, cctv.y, cctv.x, (cctv.direction + 1) % 4);
                    fillVision(visionMap, cctv.y, cctv.x, (cctv.direction + 2) % 4);
                    fillVision(visionMap, cctv.y, cctv.x, (cctv.direction + 3) % 4);
                    break;
            }
        }
        int cnt = 0;
        for (int h = 1; h <= height; h++) {
            for (int w = 1; w <= width; w++) {
                if (visionMap[h][w] == 0) cnt++;
            }
        }
        return cnt;
    }

    private void findKillPointArea(int cctvIdx) {
        if (cctvIdx == numCctv) {
            minKillPointArea = Math.min(minKillPointArea, getKillPointArea());
            return;
        }
        CCTV cctv = cctvList.get(cctvIdx);
        for (int j = 0; j < 4; j ++) {
            findKillPointArea(cctvIdx + 1);
            cctv.turnClockwise();
        }
    }
}
