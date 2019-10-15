package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 15:45 ~ 16:37
public class ChickenDelivery15686 {
    private int minCityChickenDistance = Integer.MAX_VALUE;
    private int mapSize;
    private int numKyochonRemains; // 치킨은
    private int numKyochons = 0; // 역시
    private int[][] kyochons = new int[13][2]; // 교촌치킨
    private boolean[] kyochonRemains = new boolean[13]; // 허니콤보
    private int numHomes = 0;
    private int[][] homes = new int[50 * 2][2];

    public ChickenDelivery15686() {
        init();
        dfs(0, 0);
        System.out.println(minCityChickenDistance);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs = reader.readLine().split(" ");
            mapSize = Integer.parseInt(inputs[0]);
            numKyochonRemains = Integer.parseInt(inputs[1]);
            for (int r = 0; r < mapSize; r++) {
                inputs = reader.readLine().split(" ");
                for (int c = 0; c < mapSize; c++) {
                    int block = Integer.parseInt(inputs[c]);
                    if (block == 1) {
                        homes[numHomes][0] = r;
                        homes[numHomes][1] = c;
                        numHomes++;
                    } else if (block == 2) {
                        kyochons[numKyochons][0] = r;
                        kyochons[numKyochons][1] = c;
                        numKyochons++;
                    }
                }
            }
        } catch (IOException e) {
        }
    }

    private int getCityChickenDistance() {
        int cityChickenDistance = 0;
        for (int i = 0; i < numHomes; i++) {
            int chickenDistance = 999;
            for (int j = 0; j < numKyochons; j++) {
                if (!kyochonRemains[j]) continue;
                chickenDistance = Math.min(chickenDistance, (Math.abs(homes[i][0] - kyochons[j][0]) + Math.abs(homes[i][1] - kyochons[j][1])));
            }
            cityChickenDistance += chickenDistance;
        }
        return cityChickenDistance;
    }

    private void dfs(int startIdx, int cnt) {
        if (cnt == numKyochonRemains || startIdx == numKyochons ) {
            minCityChickenDistance = Math.min(minCityChickenDistance, getCityChickenDistance());
            return;
        }
        for (int i = startIdx; i < numKyochons; i++) {
            kyochonRemains[i] = true;
            dfs(i + 1, cnt + 1);
            kyochonRemains[i] = false;
        }
    }
}
