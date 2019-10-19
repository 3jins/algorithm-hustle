package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

// 17:17 ~ 18:01
// 18:15 ~ 18:43 (TC 7)
// 19:27 ~ 19:33 (시간초과)
// 19:33 ~ 19:46
public class LabratoryThree17142 {
    private class Pos {
        int y;
        int x;
        int time;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }

        public Pos(int y, int x, int time) {
            this.y = y;
            this.x = x;
            this.time = time;
        }
    }

    private class Virus extends Pos {
        boolean isActive;

        public Virus(int y, int x, boolean isActive) {
            super(y, x);
            this.isActive = isActive;
        }
    }

    private final int[][] steps = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1},
    };
    private int minTimeForSpread = Integer.MAX_VALUE;
    private int labSize;
    private int numActive;
    private int[][] lab;
    private int[][] timeTable;
    private List<Virus> viruses = new ArrayList<>();
    private int numViruses;

    public LabratoryThree17142() {
        init();
        findMinTimeForSpread(0, 0);
        if (minTimeForSpread == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(minTimeForSpread);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs = reader.readLine().split(" ");
            labSize = Integer.parseInt(inputs[0]);
            numActive = Integer.parseInt(inputs[1]);
            lab = new int[labSize + 2][labSize + 2];
            timeTable  = new int[labSize + 2][labSize + 2];
            for (int c = 0; c <= labSize + 1; c++) {
                lab[0][c] = -1;
                lab[labSize + 1][c] = -1;
            }
            for (int r = 1; r <= labSize; r++) {
                lab[r][0] = -1;
                lab[r][labSize + 1] = -1;
                inputs = reader.readLine().split(" ");
                for (int c = 1; c <= labSize; c++) {
                    int cell = Integer.parseInt(inputs[c - 1]);
                    if (cell == 2) {
                        numViruses++;
                        viruses.add(new Virus(r, c, false));
                    }
                    lab[r][c] = cell;
                    timeTable[r][c] = -1;
                }
            }
        } catch (IOException e) {
        }
    }

    private void findMinTimeForSpread(int cnt, int startIdx) {
        if (cnt == numActive) {
            minTimeForSpread = Math.min(minTimeForSpread, bfs());
            return;
        }
        for (int i = startIdx; i < numViruses; i++) {
            Virus virus = viruses.get(i);
            if (virus.isActive) continue;
            virus.isActive = true;
            findMinTimeForSpread(cnt + 1, i + 1);
            virus.isActive = false;
        }
    }

    private List<Pos> getNextPosList(Pos curPos) {
        List<Pos> nextPosList = new ArrayList<>();
        for (int[] step : steps) {
            int nextY = curPos.y + step[0];
            int nextX = curPos.x + step[1];
            int nextTime = curPos.time + 1;
            if (lab[nextY][nextX] < 0) continue;
            if (lab[nextY][nextX] == 1) continue;
            if (timeTable[nextY][nextX] >= 0 && timeTable[nextY][nextX] <= nextTime) continue;
            nextPosList.add(new Pos(nextY, nextX, nextTime));
        }
        return nextPosList;
    }

    private int bfs() {
        Queue<Pos> bfsq = new LinkedList<>();
        for (Virus virus : viruses) {
            if (virus.isActive) {
                bfsq.add(virus);
                timeTable[virus.y][virus.x] = 0;
            }
        }
        while (!bfsq.isEmpty()) {
            Pos curPos = bfsq.poll();
            List<Pos> nextPosList = getNextPosList(curPos);
            for (Pos nextPos : nextPosList) {
                bfsq.add(nextPos);
                timeTable[nextPos.y][nextPos.x] = nextPos.time;
            }
        }

        int timeForSpread = 0;
        for (int r = 1; r <= labSize; r++) {
            for (int c = 1; c <= labSize; c++) {
                if (lab[r][c] == 0) {
                    if (timeTable[r][c] < 0) {
                        timeForSpread = Integer.MAX_VALUE;
                    } else {
                        timeForSpread = Math.max(timeForSpread, timeTable[r][c]);
                    }
                }
                timeTable[r][c] = -1;
            }
        }

        return timeForSpread;
    }
}
