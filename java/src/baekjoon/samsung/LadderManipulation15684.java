package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 15:33 ~ 16:15 (포기)
// (블로그 보고 완전탐색 문제임을 알게 됨)
// 21:32 ~ 00:04 (틀린 이유 깨달음. 내 코드에서는 한 세로선 당 가로선이 둘 이상 나오지 못함.)
public class LadderManipulation15684 {
    private final int MAX_TRIALS = 3;
    private int minHorizontalLinesRequired = Integer.MAX_VALUE;
    private int numVerticalLines;
    private int numHorizontalLinePlaces;
    private boolean[][] ladder;

    public LadderManipulation15684() {
        init();
        dfs(0, 0);
        if (minHorizontalLinesRequired == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(minHorizontalLinesRequired);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs = reader.readLine().split(" ");
            numVerticalLines = Integer.parseInt(inputs[0]);
            int numHorizontalLinesPlaced = Integer.parseInt(inputs[1]);
            numHorizontalLinePlaces = Integer.parseInt(inputs[2]);
            ladder = new boolean[numHorizontalLinePlaces][numVerticalLines - 1];
            for (int i = 0; i < numHorizontalLinesPlaced; i++) {
                inputs = reader.readLine().split(" ");
                int y = Integer.parseInt(inputs[0]) - 1;
                int x = Integer.parseInt(inputs[1]) - 1;
                ladder[y][x] = true;
            }
        } catch (IOException e) {
        }
    }

    private boolean isLadderOkay() {
        for (int i = 0; i < numVerticalLines - 1; i++) {
            int y = 0;
            int x = i;
            while (y < numHorizontalLinePlaces) {
                if (x < numVerticalLines - 1 && ladder[y][x]) { // go right
                    x++;
                } else if (x > 0 && ladder[y][x - 1]) { // go left
                    x--;
                }
                y++;
            }
            if (x != i) return false;
        }
        return true;
    }

    private void dfs(int cnt, int yStart) {
        if (cnt > MAX_TRIALS) return;
        if (cnt < minHorizontalLinesRequired && isLadderOkay()) {
            minHorizontalLinesRequired = cnt;
            return;
        }
        for (int y = yStart; y < numHorizontalLinePlaces; y++) {
            for (int x = 0; x < numVerticalLines - 1; x++) {
                if (x > 0 && ladder[y][x - 1]) continue;
                if (ladder[y][x]) continue;
                if (x < numVerticalLines - 2 && ladder[y][x + 1]) continue;
                ladder[y][x] = true;
                dfs(cnt + 1, y);
                ladder[y][x] = false;
            }
        }
    }
}
