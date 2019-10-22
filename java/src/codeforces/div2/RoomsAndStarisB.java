package codeforces.div2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

// difficulty: 1000
// 20:29 ~ 21:50 (bfs가 아님을 깨달음)
// 20:17 ~ 22:08
// 01:23 ~ 01:52
public class RoomsAndStarisB {
    private int numRooms;
    private List<Integer> stairs;
    private int numStairs;

    public RoomsAndStarisB() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            int numCases = Integer.parseInt(reader.readLine());
            for (int tc = 0; tc < numCases; tc++) {
                init(reader);
                System.out.println(Math.max(
                        findMaxRoomVisitCnt(true),
                        findMaxRoomVisitCnt(false)
                ));
            }
        } catch (IOException e) {
        }
    }

    private void init(BufferedReader reader) throws IOException {
        numRooms = Integer.parseInt(reader.readLine());
        numStairs = 0;
        String stairStr = reader.readLine();
        stairs = new ArrayList<>();
        for (int i = 0; i < numRooms; i++) {
            if (stairStr.charAt(i) == '1') {
                stairs.add(i);
                numStairs++;
            }
        }
    }

    private int findMaxRoomVisitCnt(boolean fromLeft) {
        if (numStairs == 0) return numRooms;
        List<Integer> candidates = new ArrayList<>();
        candidates.add(numRooms + numStairs);
        if (fromLeft) {
            candidates.add(stairs.get(numStairs - 1) * 2 + 2);
            candidates.add(stairs.get(numStairs - 1) * 2 - stairs.get(0) + 2);
            if (numStairs >= 2) {
                candidates.add(stairs.get(numStairs - 1) + (stairs.get(numStairs - 1) - stairs.get(numStairs - 2)));
            }
        } else {
            candidates.add((numRooms - stairs.get(0)) * 2);
            candidates.add((numRooms - stairs.get(0)) * 2 - (numRooms - stairs.get(numStairs - 1) - 1));
            if (numStairs >= 2) {
                candidates.add(numRooms - stairs.get(0) + (stairs.get(1) - stairs.get(0)));
            }
        }
        return Collections.max(candidates);
    }
}
