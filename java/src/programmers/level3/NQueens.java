package programmers.level3;

public class NQueens {
    private int boardSize;
    private int[] queenRowArr;

    private boolean mayIStandHere(int col, int row) {
        for (int queenCol = 0; queenCol < col; queenCol++) {
            int queenRow = queenRowArr[queenCol];
            if (queenRow == row) return false;
            if (Math.abs(queenRow - row) == Math.abs(queenCol - col)) return false;
        }
        return true;
    }

    private int dfs(int col) {
        if (col == boardSize) return 1;
        int cnt = 0;
        for (int row = 0; row < boardSize; row++) {
            if (!mayIStandHere(col, row)) continue;
            queenRowArr[col] = row;
            cnt += dfs(col + 1);
        }
        return cnt;
    }

    public int solution(int n) {
        boardSize = n;
        queenRowArr = new int[n];
        return dfs(0);
    }
}
