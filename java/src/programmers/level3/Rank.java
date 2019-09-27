package programmers.level3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class Rank {
    private class Player {
        HashMap<Integer, Boolean> wins = new HashMap<>();
        HashMap<Integer, Boolean> loses = new HashMap<>();
        int numWins;
        int numLoses;
        List<Integer> winRecords = new ArrayList<>();
        List<Integer> loseRecords = new ArrayList<>();

        public Player() {
            for (int i = 1; i <= numPlayers; i++) {
                wins.put(i, false);
                loses.put(i, false);
            }
        }

        @Override
        public String toString() {
            return "Player{" +
                    "wins=" + wins +
                    ", loses=" + loses +
                    ", numWins=" + numWins +
                    ", numLoses=" + numLoses +
                    ", winRecords=" + winRecords +
                    ", loseRecords=" + loseRecords +
                    '}';
        }
    }

    private int numPlayers;
    private Player[] players;

    private void traverseWinRecord(int playerIdx, int loserIdx) {
        if (players[playerIdx].wins.get(loserIdx)) return;
        if (playerIdx != loserIdx) {
            players[playerIdx].wins.put(loserIdx, true);
            players[playerIdx].numWins += 1;
        }

        Player loser = players[loserIdx];
        if (loser.wins.isEmpty()) return;
        for (int nextLoserIdx : loser.winRecords) {
            traverseWinRecord(playerIdx, nextLoserIdx);
        }
    }

    private void traverseLoseRecord(int playerIdx, int winnerIdx) {
        if (players[playerIdx].loses.get(winnerIdx)) return;
        if (playerIdx != winnerIdx) {
            players[playerIdx].loses.put(winnerIdx, true);
            players[playerIdx].numLoses += 1;
        }

        Player winner = players[winnerIdx];
        if (winner.loses.isEmpty()) return;
        for (int nextWinnerIdx : winner.loseRecords) {
            traverseLoseRecord(playerIdx, nextWinnerIdx);
        }
    }

    private void init(int numPlayers, int[][] results) {
        this.numPlayers = numPlayers;
        players = new Player[numPlayers + 1];

        for (int i = 1; i <= numPlayers; i++) {
            players[i] = new Player();
        }
        for (int[] result : results) {
            players[result[0]].winRecords.add(result[1]);
            players[result[1]].loseRecords.add(result[0]);
        }
    }

    public int solution(int numPlayers, int[][] results) {
        init(numPlayers, results);
        int numKnownRankers = 0;

        int[] ranks = new int[numPlayers + 1];
        for (int i = 1; i <= numPlayers; i++) {
            traverseWinRecord(i, i);
            traverseLoseRecord(i, i);
            if (players[i].numWins + players[i].numLoses == numPlayers - 1) {
                ranks[players[i].numLoses + 1] = i;
                numKnownRankers++;
            }
        }
        boolean isChanged = true;
        while (isChanged) {
            isChanged = false;
            for (int i = 1; i <= numPlayers; i++) {
                for (int j = 1; j < numPlayers - 1; j++) {
                    // System.out.println(j + " " + players[i].loses.get(j) + " " + players[i].wins.get(j + 2));
                    if (ranks[j] != 0 && ranks[j + 2] != 0 && ranks[j + 1] == 0 && players[i].loses.get(ranks[j]) && players[i].wins.get(ranks[j + 2])) {
                        ranks[j + 1] = i;
                        isChanged = true;
                        numKnownRankers++;
                    }
                    if (ranks[numPlayers - 1] != 0 && ranks[numPlayers] == 0 && players[i].loses.get(ranks[numPlayers - 1])) {
                        ranks[numPlayers] = i;
                        isChanged = true;
                        numKnownRankers++;
                    }
                    if (ranks[2] != 0 && ranks[1] == 0 && players[i].wins.get(ranks[2])) {
                        ranks[1] = i;
                        isChanged = true;
                        numKnownRankers++;
                    }
                }
            }
        }

        System.out.println(Arrays.toString(ranks));
        return numKnownRankers;
    }
}
