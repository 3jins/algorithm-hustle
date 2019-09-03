package baekjoon;

import java.util.Scanner;

public class NQueen9663 {
    private int N;
    private int[] colHistory;

    public NQueen9663() {
        init();
        System.out.println(dfs(0));
    }

    private void init() {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        colHistory = new int[N];
    }

    private boolean isQueenPath(int row, int col) {
        for (int pastRow = 0; pastRow < row; pastRow++) {
            int pastCol = colHistory[pastRow];
            if (pastCol == col || pastCol + (row - pastRow) == col || pastCol - (row - pastRow) == col) {
                return true;
            }
        }
        return false;
    }

    private int dfs(int row) {
        if (row == N) {
            return 1;
        }
        int numOfNQueens = 0;
        for (int col = 0; col < N; col++) {
            if (isQueenPath(row, col)) continue;
            colHistory[row] = col;
            numOfNQueens += dfs(row + 1);
        }
        return numOfNQueens;
    }
}
