package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 18:00 ~ 18:48
public class StartAndLink14889 {
    private int numPlayers;
    private int teamSize;
    private int[][] synergyTable;
    private int minDiff = Integer.MAX_VALUE;
    private boolean[] playersInStartTeam;

    public StartAndLink14889() {
        init();
        findGoldenBalance(0, -1);
        System.out.println(minDiff);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            numPlayers = Integer.parseInt(reader.readLine());
            teamSize = numPlayers / 2;
            playersInStartTeam = new boolean[numPlayers];
            synergyTable = new int[numPlayers][numPlayers];
            for (int h = 0; h < numPlayers; h++) {
                String[] inputs = reader.readLine().split(" ");
                for (int w = 0; w < numPlayers; w++) {
                    synergyTable[h][w] = Integer.parseInt(inputs[w]);
                }
            }
        } catch (IOException e) {
        }
    }

    private void findGoldenBalance(int playerCnt, int lastPlayerIdx) {
        if (playerCnt == teamSize) {
            int[] startTeamPlayers = new int[teamSize];
            int[] linkTeamPlayers = new int[teamSize];
            int startTeamIdx = 0;
            int linkTeamIdx = 0;
            for (int i = 0; i < numPlayers; i++) {
                if (playersInStartTeam[i]) {
                    startTeamPlayers[startTeamIdx++] = i;
                } else {
                    linkTeamPlayers[linkTeamIdx++] = i;
                }
            }
            int startTeamStat = 0;
            for (int i : startTeamPlayers) {
                for (int j : startTeamPlayers) {
                    startTeamStat += synergyTable[i][j];
                }
            }
            int linkTeamStat = 0;
            for (int i : linkTeamPlayers) {
                for (int j : linkTeamPlayers) {
                    linkTeamStat += synergyTable[i][j];
                }
            }
            int statDiff = Math.abs(startTeamStat - linkTeamStat);
            minDiff = Math.min(statDiff, minDiff);
            return;
        }
        for (int i = lastPlayerIdx + 1; i < numPlayers; i++) {
            if (playersInStartTeam[i]) continue;
            playersInStartTeam[i] = true;
            findGoldenBalance(playerCnt + 1, i);
            playersInStartTeam[i] = false;
        }
    }
}
