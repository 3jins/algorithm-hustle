package kakao.recruitment2020;

import java.util.Arrays;

// 16:17 ~ (fail)
// 16:25 ~ 17:39
public class LockAndKey {
    private int lockSize;
    private int keySize;
    private int lockCoordStart;
    private int lockCoordEnd;
    private int[][] lockWithSpace;
    private int numHoles;
    private int[][][] keyRotations;

    public boolean solution(int[][] key, int[][] lock) {
        lockSize = lock.length;
        keySize = key.length;
        lockCoordStart = keySize - 1;
        lockCoordEnd = lockSize + keySize - 2;
        lockWithSpace = new int[lockSize + (keySize - 1) * 2][lockSize + (keySize - 1) * 2];
        numHoles = 0;
        for (int y = lockCoordStart; y <= lockCoordEnd; y++) {
            for (int x = lockCoordStart; x <= lockCoordEnd; x++) {
                lockWithSpace[y][x] = lock[y - lockCoordStart][x - lockCoordStart];
                if (lockWithSpace[y][x] == 0) numHoles++;
            }
        }
        // rotate
        keyRotations = new int[4][keySize][keySize];
        makeKeyRotations(key);

        for (int y = 0; y <= lockCoordEnd; y++) {
            for (int x = 0; x <= lockCoordEnd; x++) {
                if (isSolvable(y, x)) return true;
            }
        }
        return false;
    }

    private void makeKeyRotations(int[][] key) {
        keyRotations[0] = key;
        for (int rot = 1; rot < 4; rot++) {
            for (int y = 0; y < keySize; y++) {
                for (int x = 0; x < keySize; x++) {
                    keyRotations[rot][y][x] = keyRotations[rot - 1][x][y];
                }
            }
            for (int y = 0; y < keySize; y++) {
                for (int x = 0; x < keySize / 2; x++) {
                    int tmp = keyRotations[rot][y][x];
                    keyRotations[rot][y][x] = keyRotations[rot][y][keySize - 1 - x];
                    keyRotations[rot][y][keySize - 1 - x] = tmp;
                }
            }
        }
    }

    private boolean isSolvable(int keyLUY, int keyLUX) {
        boolean breakFlag = false;
        for (int rot = 0; rot < 4; rot++) {
            int cnt = 0;
            int yStart = Math.max(keyLUY, lockCoordStart);
            int xStart = Math.max(keyLUX, lockCoordStart);
            int yEnd = Math.min(keyLUY + keySize - 1, lockCoordEnd);
            int xEnd = Math.min(keyLUX + keySize - 1, lockCoordEnd);
            for (int y = yStart; y <= yEnd; y++) {
                for (int x = xStart; x <= xEnd; x++) {
                    int lockBump = lockWithSpace[y][x];
                    int keyBump = keyRotations[rot][y - keyLUY][x - keyLUX];
                    if (keyBump == lockBump) {
                        breakFlag = true;
                        break;
                    }
                    if (keyBump == 1 && lockBump == 0) cnt++;
                }
                if (breakFlag) {
                    break;
                }
            }
            if (breakFlag) {
                breakFlag = false;
            } else if (cnt == numHoles) {
                return true;
            }
        }
        return false;
    }
}
