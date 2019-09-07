package kakao.recruitment2020;

import java.util.Arrays;

// 16:17 ~
public class OddLock {
    public boolean solution(int[][] key, int[][] lock) {
        return isAbleToUnlock(key, lock);
    }

    int[][] rotate90(int[][] key) {
        int width = key.length;
        int[][] rotatedKey = new int[width][width];

        // 대각선 대칭
        for (int row = 0; row < width; row++) {
            for (int col = 0; col < width; col++) {
                rotatedKey[row][col] = key[col][row];
            }
        }

        // y축 대칭
        for (int row = 0; row < width; row++) {
            for (int col = 0; col < width / 2; col++) {
                int tmp = rotatedKey[row][col];
                rotatedKey[row][col] = rotatedKey[row][width - col - 1];
                rotatedKey[row][width - col - 1] = tmp;
            }
        }

        return rotatedKey;
    }

    private boolean isAbleToUnlockWithAngle(int[][] key, int[][] lock, int numHoles) {
        int width = key.length;
        int lastIdx = width - 1;
        // int bigWidth = 3 * width - 2;

        // int[][] bigTable = new int[bigWidth][bigWidth];

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < width; j++) {
                // key: ┌, lock: ┘ / key: ┐, lock: └ / key: └, lock: ┐ / key: ┘, lock: ┌
                int[] keyRowStart = {i, i, 0, 0};
                int[] keyColStart = {j, 0, j, 0};
                int[] keyRowDirection = {-1, -1, 1, 1};
                int[] keyColDirection = {-1, 1, -1, 1};
                int[] lockRowStart = {0, 0, i, i};
                int[] lockColStart = {0, j, 0, j};
                int[] lockRowDirection = {1, 1, -1, -1};
                int[] lockColDirection = {1, -1, 1, -1};
                // int[] keyRowStart = {lastIdx - i, lastIdx - i, 0, 0};
                // int[] keyColStart = {lastIdx - j, 0, lastIdx - j, 0};
                // int[] keyRowDirection = {-1, -1, 1, 1};
                // int[] keyColDirection = {-1, 1, -1, 1};
                // int[] lockRowStart = {0, 0, lastIdx - i, lastIdx - i};
                // int[] lockColStart = {0, lastIdx - j, 0, lastIdx - j};
                // int[] lockRowDirection = {1, 1, -1, -1};
                // int[] lockColDirection = {1, -1, 1, -1};

                int cnt = 0;
                for (int pos = 0; pos < 4; pos++) {
                    boolean unlockable = true;
                    int holesMatched = 0;
                    // System.out.println(pos);
                    // System.out.println(j);
                    // System.out.println(keyRowStart[pos] + "/" + keyColStart[pos]);
                    // System.out.println(keyRowDirection[pos] + "/" + keyColDirection[pos]);
                    for (int row = 0; row <= i; row++) {
                        if (!unlockable) break;
                        for (int col = 0; col <= j; col++) {
                            // System.out.println(++cnt + " // " + row + ", " + col);
                            // System.out.print("key: " + (keyRowStart[pos] + row * keyRowDirection[pos]) + ", " + (keyColStart[pos] + col * keyColDirection[pos]) + ": ");
                            int keyHole = key[keyRowStart[pos] + row * keyRowDirection[pos]][keyColStart[pos] + col * keyColDirection[pos]];
                            // System.out.println(keyHole);
                            // System.out.print("lock: " + (lockRowStart[pos] + row * lockRowDirection[pos]) + ", " + (lockColStart[pos] + col * lockColDirection[pos]) + ": ");
                            int lockHole = lock[lockRowStart[pos] + row * lockRowDirection[pos]][lockColStart[pos] + col * lockColDirection[pos]];
                            // System.out.println(lockHole);
                            if (keyHole == lockHole) {
                                unlockable = false;
                                break;
                            }
                            if (keyHole == 1 && lockHole == 0) {
                                holesMatched++;
                            }
                            // System.out.println(holesMatched + " / " + numHoles + ", " + unlockable);
                        }
                    }
                    // System.out.println("local(" + i + ", " + j + ", " + pos + "): " + holesMatched);
                    if (unlockable && (holesMatched == numHoles)) return true;
                }
            }
        }
        return false;
    }

    private boolean isAbleToUnlock(int[][] key, int[][] lock) {
        int numHoles = 0;
        int width = lock.length;
        for (int row = 0; row < width; row++) {
            for (int col = 0; col < width; col++) {
                if (lock[row][col] == 0) numHoles++;
            }
        }
        if (numHoles == 0) return false;

        for (int i = 0; i < 4; i++) {
            if (i > 0) key = rotate90(key);
            // System.out.println(Arrays.deepToString(key));
            if (isAbleToUnlockWithAngle(key, lock, numHoles)) return true;
            System.gc();
        }
        return false;
    }
}
