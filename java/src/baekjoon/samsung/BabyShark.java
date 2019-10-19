package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 16:22 ~ 17:48 (포기1 - 테케 4번 맞왜틀)
// 17:48 ~ 18:04 (포기2 - 질문게시판 보고 깨달은 다음 다시 4번 테케...)
// 18:04 ~ 18:10 (질문게시판 찾아보고 어디가 틀렸는지 확인함)
// 21:40 ~ 22:28
// 16:03 ~ 17:10
public class BabyShark {
    private class Pos implements Comparable<Pos> {
        int y;
        int x;
        int time;

        public Pos(int y, int x, int time) {
            this.y = y;
            this.x = x;
            this.time = time;
        }

        @Override
        public int compareTo(Pos pos) {
            if (this.time == pos.time) {
                if (this.y == pos.y) return this.x > pos.x ? 1 : -1;
                return this.y > pos.y ? 1 : -1;
            }
            return this.time > pos.time ? 1 : -1;
        }

        @Override
        public String toString() {
            return "{" +
                    "y=" + y +
                    ", x=" + x +
                    ", time=" + time +
                    '}';
        }
    }

    private final int[][] steps = {
            {-1, 0}, {0, -1}, {0, 1}, {1, 0},
    };
    private int mapSize;
    private int[][] map;
    boolean[][] isVisited;
    private Pos shark;
    private int eatCnt = 0;
    private PriorityQueue<Pos> feedQueue = new PriorityQueue<>();

    public BabyShark() {
        init();
        int sharkSize = 2;
        while (true) {
            findFeed(sharkSize);
            if (feedQueue.isEmpty()) break;
            sharkSize = feed(sharkSize);
            feedQueue.clear();
        }
        System.out.println(shark.time);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mapSize = Integer.parseInt(reader.readLine());
            map = new int[mapSize + 2][mapSize + 2];
            isVisited = new boolean[mapSize + 2][mapSize + 2];
            for (int c = 0; c <= mapSize + 1; c++) {
                map[0][c] = -1;
                map[mapSize + 1][c] = -1;
            }
            for (int r = 1; r <= mapSize; r++) {
                String[] inputs = reader.readLine().split(" ");
                map[r][0] = -1;
                map[r][mapSize + 1] = -1;
                for (int c = 1; c <= mapSize; c++) {
                    int fish = Integer.parseInt(inputs[c - 1]);
                    if (fish == 9) {
                        map[r][c] = 0;
                        shark = new Pos(r, c, 0);
                    } else if (fish > 0) {
                        map[r][c] = fish;
                    }
                }
            }
        } catch (IOException e) {
        }
    }

    private void initIsVisited() {
        for (int r = 1; r <= mapSize; r++) {
            for (int c = 1; c <= mapSize; c++) {
                isVisited[r][c] = false;
            }
        }
    }

    private List<Pos> getNextPosList(Pos curPos, int sharkSize) {
        List<Pos> nextPosList = new ArrayList<>();
        for (int[] step : steps) {
            int nextY = curPos.y + step[0];
            int nextX = curPos.x + step[1];
            int fish = map[nextY][nextX];
            if (isVisited[nextY][nextX]) continue;
            if (fish < 0) continue; // out of the map
            if (fish > sharkSize) continue; // cannot pass
            nextPosList.add(new Pos(nextY, nextX, curPos.time + 1));
        }
        return nextPosList;
    }

    private void findFeed(int sharkSize) {
        Queue<Pos> bfsq = new LinkedList<>();
        bfsq.add(shark);
        isVisited[shark.y][shark.x] = true;
        while (!bfsq.isEmpty()) {
            Pos curPos = bfsq.poll();
            if (map[curPos.y][curPos.x] > 0 && map[curPos.y][curPos.x] < sharkSize) {
                feedQueue.add(curPos);
            }
            List<Pos> nextPosList = getNextPosList(curPos, sharkSize);
            for (Pos nextPos : nextPosList) {
                bfsq.add(nextPos);
                isVisited[nextPos.y][nextPos.x] = true;
            }
        }
    }

    private int feed(int sharkSize) {
        Pos target = feedQueue.poll();
        shark.y = target.y;
        shark.x = target.x;
        shark.time = target.time;
        map[shark.y][shark.x] = 0;
        if (++eatCnt == sharkSize) {
            sharkSize++;
            eatCnt = 0;
        }
        initIsVisited();
        return sharkSize;
    }
}
