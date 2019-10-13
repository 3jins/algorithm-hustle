package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 19:00 ~ 19:48
public class Slope14890 {
    private int mapSize;
    private int[][] map;
    private int slopeSize;

    public Slope14890() {
        init();
        int numPassables = 0;
        for (int i = 0; i < mapSize; i++) {
            int[] path = map[i];
            numPassables += isPassable(path) ? 1 : 0;
        }
        for (int i = 0; i < mapSize; i++) {
            int[] path = new int[mapSize];
            for (int j = 0; j < mapSize; j++) {
                path[j] = map[j][i];
            }
            numPassables += isPassable(path) ? 1 : 0;
        }
        System.out.println(numPassables);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs = reader.readLine().split(" ");
            mapSize = Integer.parseInt(inputs[0]);
            map = new int[mapSize][mapSize];
            slopeSize = Integer.parseInt(inputs[1]);
            for (int h = 0; h < mapSize; h++) {
                inputs = reader.readLine().split(" ");
                for (int w = 0; w < mapSize; w++) {
                    map[h][w] = Integer.parseInt(inputs[w]);
                }
            }
        } catch (IOException e) {
        }
    }

    private boolean isPassable(int[] path) {
        boolean[] isSlopePlaced = new boolean[mapSize];
        int lastHeight = path[0];
        int step = 0;
        while (step < mapSize - 1) {
            step++;
            if (path[step] == lastHeight) continue;
            if (path[step] == lastHeight - 1) { // 내려감
                if (step + slopeSize - 1 >= mapSize) return false;
                isSlopePlaced[step] = true;
                for (int onSlopeStep = 1; onSlopeStep < slopeSize; onSlopeStep++) {
                    if (path[step] != path[step + onSlopeStep]) return false;
                    if (isSlopePlaced[step + onSlopeStep]) return false;
                    isSlopePlaced[step + onSlopeStep] = true;
                }
                lastHeight = path[step];
            } else if (path[step] == lastHeight + 1) { // 올라감
                if (step - slopeSize < 0) return false;
                if (isSlopePlaced[step - 1]) return false;
                for (int onSlopeStep = 2; onSlopeStep <= slopeSize; onSlopeStep++) {
                    if (lastHeight != path[step - onSlopeStep]) return false;
                    if (isSlopePlaced[step - onSlopeStep]) return false;
                }
                lastHeight = path[step];
            } else { // 두 칸 이상 차이 남
                return false;
            }
        }
        return true;
    }
}
