package baekjoon.koi.elementary;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class TreasureIsland {
    private class Point {
        int row, col;
        int distance;

        Point(int row, int col, int distance) {
            this.row = row;
            this.col = col;
            this.distance = distance;
        }

        String getTerrain() {
            return treasureMap.get(row).get(col);
        }
    }

    private int height, width;
    private List<List<String>> treasureMap;
    int[][] distanceMap;

    public TreasureIsland() {
        init();
        int mostFar = 0;

        for (int h = 1; h <= height; h++) {
            for (int w = 1; w <= width; w++) {
                if (treasureMap.get(h).get(w).equals("W")) continue;
                mostFar = Math.max(bfs(new Point(h, w, 0)), mostFar);
            }
        }
        System.out.println(mostFar);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] sizes = reader.readLine().split(" ");
            height = Integer.parseInt(sizes[0]);
            width = Integer.parseInt(sizes[1]);
            distanceMap = new int[height + 2][width + 2];

            String edgeMapRow = "";
            for (int w = 0; w <= width + 1; w++) {
                edgeMapRow += "W";
            }

            treasureMap = new ArrayList<>(height + 2);
            treasureMap.add(0, Arrays.asList(edgeMapRow.split("")));
            for (int h = 1; h <= height; h++) {
                String mapRow = "W" + reader.readLine() + "W";
                treasureMap.add(h, Arrays.asList(mapRow.split("")));
            }
            treasureMap.add(height + 1, Arrays.asList(edgeMapRow.split("")));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private List<Point> findNextPoints(Point curPoint) {
        List<Point> nextPoints = new ArrayList<>();
        int[] stepsY = {1, -1, 0, 0};
        int[] stepsX = {0, 0, 1, -1};
        int y = curPoint.row;
        int x = curPoint.col;
        int nextDistance = curPoint.distance + 1;

        for (int i = 0; i < 4; i++) {
            int curY = y + stepsY[i];
            int curX = x + stepsX[i];
            int recordedDistance = distanceMap[curY][curX];
            if (recordedDistance < 0 || nextDistance < recordedDistance) {
                Point nextPoint = new Point(curY, curX, nextDistance);
                if (nextPoint.getTerrain().equals("L")) {
                    nextPoints.add(nextPoint);
                    distanceMap[curY][curX] = nextDistance;
                }
            }
        }

        return nextPoints;
    }

    private int bfs(Point startPoint) {
        int mostFarShortcut = 0;
        Queue<Point> nextPointQueue = new LinkedList<>();

        // initiation
        for (int h = 0; h <= height + 1; h++) {
            for (int w = 0; w <= width + 1; w++) {
                distanceMap[h][w] = -1;
            }
        }
        distanceMap[startPoint.row][startPoint.col] = 0;

        List<Point> nextPoints = findNextPoints(startPoint);
        nextPointQueue.addAll(nextPoints);
        while (!nextPointQueue.isEmpty()) {
            Point curPoint = nextPointQueue.poll();
            mostFarShortcut = Math.max(mostFarShortcut, curPoint.distance);
            nextPoints = findNextPoints(curPoint);
            nextPointQueue.addAll(nextPoints);
        }

        return mostFarShortcut;
    }
}
