package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

// 21:14 ~ 22:22
public class Laboratory14502 {
    private class Point {
        int y;
        int x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    private int height;
    private int width;
    private int[][] map;
    private boolean[][] isVisited;
    private List<Point> virusList = new ArrayList<>();

    public Laboratory14502() {
        init();
        System.out.println(findMaxSafetyAreaSize());
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] input = reader.readLine().split(" ");
            height = Integer.parseInt(input[0]);
            width = Integer.parseInt(input[1]);
            map = new int[height + 2][width + 2];

            for (int w = 0; w <= width + 1; w++) {
                map[0][w] = -1;
                map[height + 1][w] = -1;
            }
            for (int h = 1; h <= height; h++) {
                input = reader.readLine().split(" ");
                map[h][0] = -1;
                map[h][width + 1] = -1;
                for (int w = 1; w <= width; w++) {
                    map[h][w] = Integer.parseInt(input[w - 1]);
                    if (map[h][w] == 2) virusList.add(new Point(h, w));
                }
            }
        } catch (IOException e) {
        }
    }

    private int getSafetyAreaSize() {
        int safetyAreaSize = 0;
        for (int h = 1; h <= height; h++) {
            for (int w = 1; w <= width; w++) {
                if (map[h][w] == 0 && !isVisited[h][w]) {
                    safetyAreaSize++;
                }
            }
        }
        return safetyAreaSize;
    }

    private List<Point> getNextPoints(Point curPoint) {
        List<Point> nextPoints = new ArrayList<>();
        int[] stepY = {1, 0, -1, 0};
        int[] stepX = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nextY = curPoint.y + stepY[i];
            int nextX = curPoint.x + stepX[i];
            if (map[nextY][nextX] != 0) continue;
            if (isVisited[nextY][nextX]) continue;
            nextPoints.add(new Point(nextY, nextX));
            isVisited[nextY][nextX] = true;
        }

        return nextPoints;
    }

    private int bfs(List<Point> walls) {
        for (Point wall : walls) {
            map[wall.y][wall.x] = 1;
        }

        isVisited = new boolean[height + 2][width + 2];
        Queue<Point> bfsq = new LinkedList<>();
        for (Point virus : virusList) {
            bfsq.add(new Point(virus.y, virus.x));
            isVisited[virus.y][virus.x] = true;
        }
        while (!bfsq.isEmpty()) {
            Point curPoint = bfsq.poll();
            List<Point> nextPoints = getNextPoints(curPoint);
            for (Point nextPoint : nextPoints) {
                bfsq.add(nextPoint);
            }
        }
        int safetyAreaSize = getSafetyAreaSize();

        for (Point wall : walls) {
            map[wall.y][wall.x] = 0;
        }
        return safetyAreaSize;
    }

    // 육중루프... 미쳤습니까 삼성휴먼?
    private int findMaxSafetyAreaSize() {
        int maxSafetyAreaSize = 0;
        for (int a = 1; a <= height; a++) {
            for (int b = 1; b <= width; b++) {
                for (int c = 1; c <= height; c++) {
                    for (int d = 1; d <= width; d++) {
                        for (int e = 1; e <= height; e++) {
                            for (int f = 1; f <= width; f++) {
                                if (a == c && b == d) continue;
                                if (a == e && b == f) continue;
                                if (c == e && d == f) continue;
                                if (map[a][b] > 0) continue;
                                if (map[c][d] > 0) continue;
                                if (map[e][f] > 0) continue;
                                List<Point> walls = new ArrayList<>();
                                walls.add(new Point(a, b));
                                walls.add(new Point(c, d));
                                walls.add(new Point(e, f));
                                maxSafetyAreaSize = Math.max(bfs(walls), maxSafetyAreaSize);
                            }
                        }
                    }
                }
            }
        }
        return maxSafetyAreaSize;
    }
}
