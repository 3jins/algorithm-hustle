package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 20:48 ~ 21:52 (시간 초과)
// 21:52 ~ 22:08
public class Migration16234 {
    private class Point {
        int y;
        int x;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    private int mapSize;
    private int lowerLimit;
    private int upperLimit;
    private int[][] map;
    private boolean[][] isVisited;

    public Migration16234() {
        init();
        int cnt = 0;
        boolean isMigrated = true;
        while (isMigrated) {
            isMigrated = false;
            for (int r = 1; r <= mapSize; r++) {
                for (int c = 1; c <= mapSize; c++) {
                    if (isVisited[r][c]) continue;
                    if (migrate(new Point(r, c))) isMigrated = true;
                }
            }
            if (isMigrated) {
                isVisited = new boolean[mapSize + 2][mapSize + 2];
                cnt++;
            }
        }
        System.out.println(cnt);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs = reader.readLine().split(" ");
            mapSize = Integer.parseInt(inputs[0]);
            lowerLimit = Integer.parseInt(inputs[1]);
            upperLimit = Integer.parseInt(inputs[2]);
            map = new int[mapSize + 2][mapSize + 2];
            isVisited = new boolean[mapSize + 2][mapSize + 2];
            for (int c = 0; c <= mapSize + 1; c++) {
                map[0][c] = -1;
                map[mapSize + 1][c] = -1;
            }
            for (int r = 1; r <= mapSize; r++) {
                map[r][0] = -1;
                map[r][mapSize + 1] = -1;
                inputs = reader.readLine().split(" ");
                for (int c = 1; c <= mapSize; c++) {
                    map[r][c] = Integer.parseInt(inputs[c - 1]);
                }
            }
        } catch (IOException e) {
        }
    }

    private List<Point> getNextPoints(Point curPoint) {
        int[] stepY = {0, 1, 0, -1};
        int[] stepX = {1, 0, -1, 0};

        List<Point> nextPoints = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            int nextY = curPoint.y + stepY[i];
            int nextX = curPoint.x + stepX[i];
            if (isVisited[nextY][nextX]) continue;
            if (map[nextY][nextX] < 0) continue;
            int populationDiff = Math.abs(map[nextY][nextX] - map[curPoint.y][curPoint.x]);
            if (populationDiff < lowerLimit) continue;
            if (populationDiff > upperLimit) continue;
            nextPoints.add(new Point(nextY, nextX));
        }
        return nextPoints;
    }

    private boolean migrate(Point startPoint) {
        int cnt = 1;
        int sum = map[startPoint.y][startPoint.x];
        List<Point> aliance = new ArrayList<>();
        boolean[][] isCombined = new boolean[mapSize + 2][mapSize + 2];

        Queue<Point> bfsq = new LinkedList<>();
        bfsq.add(startPoint);
        isVisited[startPoint.y][startPoint.x] = true;
        isCombined[startPoint.y][startPoint.x] = true;
        while (!bfsq.isEmpty()) {
            Point curPoint = bfsq.poll();
            List<Point> nextPoints = getNextPoints(curPoint);
            for (Point nextPoint : nextPoints) {
                aliance.add(nextPoint);
                bfsq.add(nextPoint);
                isVisited[nextPoint.y][nextPoint.x] = true;
                isCombined[nextPoint.y][nextPoint.x] = true;
                cnt++;
                sum += map[nextPoint.y][nextPoint.x];
            }
        }

        int population = sum / cnt;
        map[startPoint.y][startPoint.x] = population;
        for (Point nation : aliance) {
            map[nation.y][nation.x] = population;
        }

        return !aliance.isEmpty();
    }
}
