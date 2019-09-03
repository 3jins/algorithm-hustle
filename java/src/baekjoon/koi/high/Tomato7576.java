package baekjoon.koi.high;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Tomato7576 {
    private class Point {
        int row, col;
        int distance;

        Point(int row, int col, int distance) {
            this.row = row;
            this.col = col;
            this.distance = distance;
        }
    }

    private int row;
    private int col;
    private int[][] tomatoBox;
    private int[][] distanceMap;

    public Tomato7576() {
        init();
        int daysForMature = calcDaysForMature();
        System.out.println(daysForMature);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String colAndRow = reader.readLine();
            col = Integer.parseInt(colAndRow.split(" ")[0]);
            row = Integer.parseInt(colAndRow.split(" ")[1]);
            tomatoBox = new int[row + 2][col + 2];

            String tomatoRowStr;
            String[] tomatoRow = new String[row];
            for (int h = 0; h <= row + 1; h++) {
                if (h > 0 && h <= row) {
                    tomatoRowStr = reader.readLine();
                    tomatoRow = tomatoRowStr.split(" ");
                }
                for (int w = 0; w <= col + 1; w++) {
                    if (h == 0 || w == 0 || h == row + 1 || w == col + 1) {
                        tomatoBox[h][w] = -1;
                    } else {
                        tomatoBox[h][w] = Integer.parseInt(tomatoRow[w - 1]);
                    }
                }
            }

            distanceMap = new int[row + 2][col + 2];
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private List<Point> getNextPoints(Point curPoint) {
        List<Point> nextPoints = new ArrayList<>();
        int[] stepsY = {1, -1, 0, 0};
        int[] stepsX = {0, 0, 1, -1};
        int nextDistance = curPoint.distance + 1;

        for (int i = 0; i < 4; i++) {
            int nextY = curPoint.row + stepsY[i];
            int nextX = curPoint.col + stepsX[i];
            int recordedDistance = distanceMap[nextY][nextX];
            if (tomatoBox[nextY][nextX] < 0) continue; // cannot go there
            if (recordedDistance < 0 || recordedDistance > nextDistance) {
                distanceMap[nextY][nextX] = nextDistance;
                nextPoints.add(new Point(nextY, nextX, nextDistance));
            }
        }

        return nextPoints;
    }

    private int calcDaysForMature() {
        int daysForMatrue = -1;

        for (int h = 0; h <= row + 1; h++) {
            for (int w = 0; w <= col + 1; w++) {
                distanceMap[h][w] = -1;
            }
        }

        Queue<Point> bfsQ = new LinkedList<>();
        for (int h = 1; h <= row; h++) {
            for (int w = 1; w <= col; w++) {
                if (tomatoBox[h][w] == 1) {
                    bfsQ.add(new Point(h, w, 0));
                }
            }
        }

        while (!bfsQ.isEmpty()) {
            Point curPoint = bfsQ.poll();
            daysForMatrue = Math.max(curPoint.distance, daysForMatrue);
            List<Point> nextPoints = getNextPoints(curPoint);
            bfsQ.addAll(nextPoints);
        }

        for (int h = 1; h <= row; h++) {
            for (int w = 1; w <= col; w++) {
                if (tomatoBox[h][w] == 0 && distanceMap[h][w] < 0) return -1;
            }
        }

        return daysForMatrue;
    }
}
