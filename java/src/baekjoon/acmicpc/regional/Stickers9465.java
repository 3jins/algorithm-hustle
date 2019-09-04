package baekjoon.acmicpc.regional;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Stickers9465 {
    private int numCols;
    private int[][] points;

    public Stickers9465() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            int numTestCases = Integer.parseInt(reader.readLine());
            for (int tc = 0; tc < numTestCases; tc++) {
                init(reader);
                System.out.println(getMaxPoint());
                System.gc();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void init(BufferedReader reader) throws IOException {
        numCols = Integer.parseInt(reader.readLine());
        points = new int[2][numCols];

        StringTokenizer tokenizer = new StringTokenizer(reader.readLine(), " ");
        int col = 0;
        while (tokenizer.hasMoreTokens()) {
            points[0][col++] = Integer.parseInt(tokenizer.nextToken());
        }

        tokenizer = new StringTokenizer(reader.readLine(), " ");
        col = 0;
        while (tokenizer.hasMoreTokens()) {
            points[1][col++] = Integer.parseInt(tokenizer.nextToken());
        }
    }

    private int getMaxPoint() {
        int[][] recordedPoints = new int[3][numCols];
        recordedPoints[0][0] = points[0][0];
        recordedPoints[1][0] = points[1][0];
        for (int col = 1; col < numCols; col++) {
            recordedPoints[0][col] = Math.max(recordedPoints[2][col - 1] + points[0][col], recordedPoints[1][col - 1] + points[0][col]);
            recordedPoints[1][col] = Math.max(recordedPoints[2][col - 1] + points[1][col], recordedPoints[0][col - 1] + points[1][col]);
            recordedPoints[2][col] = Math.max(recordedPoints[0][col - 1], recordedPoints[1][col - 1]);
        }

        return Math.max(recordedPoints[0][numCols - 1], recordedPoints[1][numCols - 1]);
    }


    /*
     * Cannot figure out why this solution not working
     */

    // private int[][] recordedPoints;
    //
    // private int getMaxPoint() {
    //     recordedPoints = new int[2][numCols];
    //     dp(0);
    //     dp(1);
    //     return Math.max(recordedPoints[0][numCols - 1], recordedPoints[1][numCols - 1]);
    // }
    //
    // private int switchRow(int row) {
    //     return row == 1 ? 0 : 1;
    // }
    //
    // private void dp(int startRow) {
    //     recordedPoints[startRow][0] = points[startRow][0];
    //
    //     int curRow = startRow;
    //     int nextRow;
    //     for (int col = 0; col < numCols - 1; col++) {
    //         nextRow = switchRow(curRow);
    //         recordedPoints[nextRow][col + 1] = Math.max(
    //                 recordedPoints[nextRow][col + 1],
    //                 recordedPoints[curRow][col] + points[nextRow][col + 1]
    //         );
    //         if (col < numCols - 2) {
    //             recordedPoints[nextRow][col + 2] = Math.max(
    //                     recordedPoints[nextRow][col + 2],
    //                     recordedPoints[curRow][col] + points[nextRow][col + 2]
    //             );
    //         }
    //         curRow = nextRow;
    //     }
    // }
}
