package nhn;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 19:10 ~ 20:18
public class ScreenAdvertisement {
    private int screenSize;
    private boolean isClockwise;
    private int rotationCnt;
    private String[][] screen;

    public ScreenAdvertisement() {
        init();
        for (int shell = 0; shell < screenSize / 2; shell++) {
            if (shell % 2 == 0) {
                if (isClockwise) rotateClockwise(shell);
                else rotateAntiClockwise(shell);
            } else {
                if (!isClockwise) rotateClockwise(shell);
                else rotateAntiClockwise(shell);
            }
        }
        for (String[] row : screen) {
            System.out.println(String.join(" ", row));
        }
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] firstLineFragments = reader.readLine().split(" ");
            screenSize = Integer.parseInt(firstLineFragments[0]);
            int input2 = Integer.parseInt(firstLineFragments[1]);
            isClockwise = input2 >= 0;
            rotationCnt = Math.abs(input2);

            screen = new String[screenSize][];
            for (int i = 0; i < screenSize; i++) {
                screen[i] = reader.readLine().split(" ");
            }
        } catch (IOException e) {
        }
    }

    private void rotateClockwise(int leftUpCoord) {
        int step = 0;
        int width = screenSize - (leftUpCoord * 2);
        int startY = leftUpCoord;
        int startX = leftUpCoord;
        int endY = leftUpCoord + width - 1;
        int endX = leftUpCoord + width - 1;
        int y = startY;
        int x = startX;
        int maxStep = 4 * (width - 1);
        String[] prevData = new String[maxStep];
        String[] nextData = new String[maxStep];

        while (step < maxStep) {
            prevData[step] = screen[y][x];
            if (y == startY && x < endX) { // →
                prevData[step] = screen[y][x + 1];
                x++;
            } else if (x == endX && y < endY) { // ↓
                prevData[step] = screen[y + 1][x];
                y++;
            } else if (y == endY && x > startX) { // ←
                prevData[step] = screen[y][x - 1];
                x--;
            } else if (x == startX && y > startY) { // ↑
                prevData[step] = screen[y - 1][x];
                y--;
            }
            step++;
        }

        for (step = 0; step < maxStep; step++) {
            nextData[(step + rotationCnt) % maxStep] = prevData[step];
        }

        step = 0;
        while (step < maxStep) {
            prevData[step] = screen[y][x];
            if (y == startY && x < endX) { // →
                screen[y][x + 1] = nextData[step];
                x++;
            } else if (x == endX && y < endY) { // ↓
                screen[y + 1][x] = nextData[step];
                y++;
            } else if (y == endY && x > startX) { // ←
                screen[y][x - 1] = nextData[step];
                x--;
            } else if (x == startX && y > startY) { // ↑
                screen[y - 1][x] = nextData[step];
                y--;
            }
            step++;
        }
    }

    private void rotateAntiClockwise(int leftUpCoord) {
        int step = 0;
        int width = screenSize - (leftUpCoord * 2);
        int startY = leftUpCoord;
        int startX = leftUpCoord;
        int endY = leftUpCoord + width - 1;
        int endX = leftUpCoord + width - 1;
        int y = startY;
        int x = startX;
        int maxStep = 4 * (width - 1);
        String[] prevData = new String[maxStep];
        String[] nextData = new String[maxStep];

        while (step < maxStep) {
            prevData[step] = screen[y][x];
            if (x == startX && y < endY) { // ↓
                prevData[step] = screen[y + 1][x];
                y++;
            } else if (y == endY && x < endX) { // →
                prevData[step] = screen[y][x + 1];
                x++;
            } else if (x == endX && y > startY) { // ↑
                prevData[step] = screen[y - 1][x];
                y--;
            } else if (y == startY && x > startX) { // ←
                prevData[step] = screen[y][x - 1];
                x--;
            }
            step++;
        }

        for (step = 0; step < maxStep; step++) {
            nextData[(step + rotationCnt) % maxStep] = prevData[step];
        }

        step = 0;
        while (step < maxStep) {
            prevData[step] = screen[y][x];
            if (x == startX && y < endY) { // ↓
                screen[y + 1][x] = nextData[step];
                y++;
            } else if (y == endY && x < endX) { // →
                screen[y][x + 1] = nextData[step];
                x++;
            } else if (x == endX && y > startY) { // ↑
                screen[y - 1][x] = nextData[step];
                y--;
            } else if (y == startY && x > startX) { // ←
                screen[y][x - 1] = nextData[step];
                x--;
            }
            step++;
        }
    }
}
